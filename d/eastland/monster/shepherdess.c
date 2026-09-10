#include <mudlib.h>

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "shepherdess", "牧羊女" );
	add( "id", ({ "girl" }) );
	set_short( "牧羊女" );
	set_long(
		"你看到一位笑容甜美的小女孩，她正在照顧這群綿羊。\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set( "alignment", 1000 );
	set( "max_hp", 500 );
	set( "hit_points", 500);
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 24 );
	set_perm_stat( "pie", 24 );
	set_perm_stat( "str", 6 );
   set_skill( "bo", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "anatomlogy", 100 );
	set_skill( "defend", 100 );
	set_temp( "aiming_loc", "vascular" );
	set( "special_defense", ([ "all": 70 ]) );
        set_natural_armor( 80, 20 ) ;
	set_natural_weapon( 100, 13, 22 );

	wield_weapon( "/d/eastland/obj/green_stick" );

	set( "chat_chance", 20 );
	set( "chat_output", ({
		"牧羊女愉快地哼著: 啦啦啦 .... 可愛的小白羊 .... 綠綠的青草地 ....\n",
		"牧羊女一隻只地數著她的白羊。\n",
          "牧羊女喃喃自語道: 可惡的土狼不要偷吃我的小羊!\n",
		"牧羊女揮舞著青竹棒，身影翩翩，姿勢美妙，宛如在演練一套劍法。\n"
	}) );
   set_lessons( ([ "bo" : ({ 220, 50 }) ]) );
   set( "inquiry", ([
          "wolf" : "@@ask_wolf",
          "hyaena" : "@@ask_wolf"
   ]) );
}

void ask_wolf(object who)
{
   tell_object( who,
        "牧羊女嘆道: 最近土狼常常趁我不注意時, 偷吃我的小羊。\n"
              "如果你幫我除去, 我就教你使用棍棒類(bo)武器。\n" );
}

void protect_sheep(object sheep, object thief)
{
	object *sheeps;

	tell_room( environment(), 
		"牧羊女奔到羊群前面，大叫: 喂！你想偷我的羊？別作夢！\n"
	 );
	sheeps = (object *)query_temp( "protectees" );
	if( sheeps && member_array(sheep, sheeps)!=-1 ) return;
	add_temp( "protectees", ({ sheep }) );
	sheep->add_temp( "protectors", ({ this_object() }) );
	if( !attackers || member_array(thief, attackers)==-1 )
		kill_ob(thief);
}

int check_trainee(object who)
{
   if( !who->query_temp("killed_wolf") )
   return notify_fail(
     "牧羊女說道: 土狼還在附近徘徊, 我不能專心教你噢!\n" );
   return notify_fail(
     "牧羊女說道: 由於大神們還沒達到共識, 我暫時還不能教你任何技能。\n");
   if( (string)who->query("class")=="adventurer" &&
       (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
     "牧羊女說: 我只教夠資格的冒險者啦!\n" );
}
