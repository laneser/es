#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "doctor Wu", "吳醫生" );
	set_short( "吳醫生" );
	add("id", ({ "wu","healer", "doctor" }) );
	set_long( @LONG
你看到一位身材高瘦、眼睛細小的中年人，這個醫生是一位混血兒，他的父
親是一個來自東方的學者，他從父親那裡學到不少有關草藥與治病的知識，
你可以問他有關醫療(heal)的事情，看他是否能給你幫助。你也可以付錢
(pay) 請他幫你看看身體狀況。
LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "inquiry", ([
		"heal" : "@@ask_heal"
	]) );
}

void init()
{
	::init();
	add_action("do_cure", "pay");
}

void ask_heal( object player )
{
	tell_object( player, 
		"吳醫生微笑著說: 我會在這裡開一家醫院，請你下次再來。\n");
}

int do_cure(string arg)
{
	string who, type;
	int num, *data;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
		return notify_fail( 
			"付誰？多少錢？\n");
	if( !id(who ) ) return 0;
	if( type != "silver" ) {
		tell_room( environment(), 
			"吳醫生說道: 對不起，我只收銀幣。\n" ,
			this_object() );
		return 1;
	}
	if( !this_player()->debit(type, num) ) 
	        return notify_fail( "你沒有那麼多銀幣。\n");
	if( !data = this_player()->query("conditions/sick") ) {
		write("吳醫生上上下下地打量著你，說: 你身體很好, 並沒有生病。\n");
			return 1;
	}
	if( num < 50 + 10*data[1]*data[2]/data[0] ) {
		write("吳醫生上上下下地打量著你，搖一搖頭，把錢退還給你。\n");
		this_player()->credit(type, num);
		return 1;
	} else {
		write("經過一番仔細的檢查，吳醫生笑著說: 你的病打個針就好了。\n");
		write("吳醫生取出一個針筒, 在你臂上打了一針。\n");
		SICK->remove_effect(this_player());
	}
	return 1;
}
