#include <mudlib.h>
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(19);
	set_name("yamor", "亞默");
	add ("id", ({ "elder", "adventurer" }) );
   	set_short( "亞默長老");
	set_long(
		"亞默長老是一個看起來很慈祥的老人，他年青的時候曾經遊歷過世界上所\n"
		"有的地方。現在他退休了，住在這裡將自己的經驗分享給那些和他一樣出\n"
		"外冒險的年青人，如果你需要幫助(help)的話，儘管問他。\n" 
	);
	set_perm_stat("strength", 25);
	set_perm_stat("dexterity", 25);
	set_skill( "blunt", 100 );
	set_skill( "dodge", 80 );
	set( "max_hp", 560 );
	set( "hit_points", 560 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1200 );
	set_natural_armor( 120, 35 );
	set_natural_weapon( 25, 13, 30 );
	set("special_defense", ([ "all":40, "none":20 ]) );
	set("aim_difficulty",
			([ "vascular":25, "ganglion":30 ]) );
	set( "tactic_func", "my_tactic" );

	set( "inquiry", ([
		"help" : "@@help_me"
	]) );
	wield_weapon("/d/adventurer/hall/weapons/wiser_staff");
	equip_armor("/d/adventurer/hall/armors/wiser_amulet");
}

void help_me( object who )
{
	tell_room( environment(),
		"亞默長老微笑著說道: 如果你需要幫助的話，去諾達尼亞跟戴利佛提我的名字。\n",
		this_object()
	);
}

int my_tactic()
{
	object *atk;

	if( !(atk = query_attackers()) || random(20)<16) return 0;
	tell_room( environment(this_object()), 
		"亞默長老召喚全能者的神力，你看到他的身邊出現一團光霧....然後消失。\n",
		this_object() );
	this_object()->receive_healing(100);
	return 1;
}
