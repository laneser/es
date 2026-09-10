#include <mudlib.h>
#include <stats.h>
#include <races.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "soothsayer", "算命先生" );
	add( "id", ({ "sayer" }) );
	set_short( "算命先生" );
	set_long(@C_LONG
這位算命先生大約四、五十歲，留著兩撇八字鬍子，你可以問他有關未來
(future)的事，請他指點迷津。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_natural_weapon( 3, 1, 5 );
	set_natural_armor( 6, 10 );
	set_perm_stat( "dex", 5 );
	set_perm_stat( "kar", 5 );
	set_skill( "dodge", 20 );
	set( "wealth/gold", 5 );
	set( "inquiry", ([
		"future" : 
			"想算命？只要付(pay)我五塊金幣，我就替你算算。"
	]) );
}

void init()
{
	add_action( "do_fortell", "pay" );
}

int do_fortell(string arg)
{
	string who, type, race;
	int num, age;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
           return notify_fail( 
                   "付誰？多少錢？\n" );
	if( !id(who ) ) return 0;
	if( type != "gold" ) {
           tell_room( environment(), 
               "算命先生說道: 對不起，我只收金幣。\n",
			this_object() );
		return 1;
	}
   if( !this_player()->debit(type, num) ) return notify_fail(
           "你沒有那麼多金幣。\n" );
	if( num < 5 ) {
           write( 
              "算命先生上上下下地打量著你，搖一搖頭，把錢退還給你。\n" );
		this_player()->credit(type, num);
		return 1;
	}
	if( this_player()->query_temp("payed_soothsayer") && num >= 1000 ) {
           tell_room( environment(), 
			"算命先生說道: 閣下真是有緣人，小弟有幸認識閣下，真是上輩子修來的福氣。\n\n"
                   "算命先生說道: 小弟願為閣下作法，補回兩年陽壽。\n" );
		this_player()->add("dead_count", -1);
		return 1;
	}
	race = this_player()->query("race");
	age = RACE_MASTER(race)->query_natural_life();
	age -= (int)this_player()->query("dead_count") * 2;
	age -= (int)this_player()->query("natural_age");
	age -= (int)this_player()->query_age() / 86400;
	if( age > 0 )
           tell_room( environment(), 
			"算命先生說道: 謝謝，請把你的手掌給我。\n\n"
+ age + " 年陽壽，好自為之吧。\n" );
   else tell_room( environment(), 
		"算命先生說道: 謝謝，請把你的手掌給我。\n\n"
		"算命先生仔細地端詳了一會兒，然後捻著鬍子說道: 閣下陽壽已盡，請千萬\n"
           "    珍重，以免墜入輪迴受苦。\n" );
	if( num >=500 ) call_out( "my_special", 6, this_player() );
	return 1;
}

void my_special(object player)
{
	if( !present(player, environment()) ) return;
   tell_object(player, 
		"算命先生壓低聲音說道: 看來閣下與小弟頗有緣份 .... 如果閣下能再\n"
             "        出 1000 塊金幣，也許 ....\n" );
	this_player()->set_temp("payed_soothsayer", 1 );
}
