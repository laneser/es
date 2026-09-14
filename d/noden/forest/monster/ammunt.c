#include <mudlib.h>

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(7);
	set_name( "ammunt", "亞曼特獸" );
	add ("id", ({ "ammunt", "beast" }) );
	set_short( "兇猛的亞曼特獸" );
	set("aggressive", 1);
	set("killer", 1);
	set("pursuing", 1);
	set_long(@CLONG
    這是一隻有介於鱷魚、河馬、獅子之間的奇怪野獸。對於比人還小的
動物, 它可以連下巴都不必動就能一口吞下。
CLONG
	);
	
	set( "alignment", -500 );
	set( "unit", "只" );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "int", 3 );
	set_perm_stat( "piety", 3 );
	set("special_defense", ([ "all":20 ]) );
	set("aim_difficulty", ([ "critical":10, "vascular":30, ]) );
	set_natural_weapon( 9, 6, 10);
	set_natural_armor( 35, 7);
	
	set_c_limbs( ({ "的身體", "的頭", "的腳", "的尾巴"}) );
	set_c_verbs( ({ "%s狠狠地向%s一口咬下", "%s向%s飛身一撲",
		 "%s用尾巴重重地橫掃%s",}) ); 
}
