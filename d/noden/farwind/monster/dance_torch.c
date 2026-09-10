#include "../farwind.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(1);
	set_name( "dancing torcher", "跳跳的火把" );
	add( "id", ({ "torcher" }) );
	set_short("跳跳的火把");
	set_long(@CLONG
這是一把奇特的火把，它是艾柏魯斯年輕時在修行中得到的物品,
頗具靈性的它已經成了艾柏魯斯的寵物了。
CLONG
               );
   set( "race", "undead" );
	set_natural_armor( 10, 7 );
	set_natural_weapon( 10, 2, 7 );
	set( "unbleeding", 1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
    set( "alt_corpse", "/obj/torch" );
    set_c_verbs(({ "%s用頭上的火焰燒%s", "%s用身體撞%s" }));
    set_c_limbs(({ "身體", "頭部" }));
    set("c_death_msg","%s突然毫無生氣地躺在地上... 不動了。\n");
	set("moving", 1 );
	set("speed", 30 );
	set("patrol", ({ "north", "south", "west", "west", "east", "east",
		"south", "north" }) );
	set_perm_stat( "str", 3 );
	set_perm_stat( "dex", 4 );
	set_skill( "dodge", 40 );
	set( "special_defense", ([ "all": 20 ]) );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
}

int stop_attack()
{
   object master, *tmp;

   master = present( "ebbruce", environment() );
   if( !master ) return 0;
   tell_room( environment(),
          "艾柏魯斯喝道: 竟敢欺負我的寵物! 不要命了?\n" );
   tmp = query_temp( "protectors" );
   if( !tmp || member_array( master, tmp )==-1 ) {
        add_temp( "protectors", ({ master }) );
        master->add_temp( "protectees", ({ this_object() }) );
        }
        tmp = master->query_attackers();
   if( !tmp || member_array( this_player(), tmp )==-1 )
         master->kill_ob( this_player() );
}
