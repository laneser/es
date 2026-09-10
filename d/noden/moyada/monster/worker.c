#include "../moyada.h"

inherit MONSTER;

void create ()
{
    object shovel;
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "worker", "工人" );
	set_short( "修路工人" );
	set_long( @C_LONG
修築道路的工人, 你看他滿頭大汗的樣子, 不禁想要幫助(help)他。
C_LONG
	);
	set( "alignment", 200 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "個" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 7 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 220);
	set ("hit_points", 220);
	set ("wealth", ([ "silver": 15 ]) );
	set_natural_weapon( 10, 7, 12 );
	set_natural_armor( 25, 5 );
    set ("weight", 750);
    set ("exp_reward",690 );
    set_experience(2000);
    shovel = new(MOYADA"obj/shovel");
    shovel->move(this_object());
    wield_weapon( MOYADA"obj/pick" );
    equip_armor( MOYADA"obj/dirty_shirt" );
    set ("chat_chance", 5);
    set ("chat_output", ({
      "修路工人一邊把碎石子鋪在地上, 一邊用髒毛巾擦汗。\n",
    }) );
}

void init()
{
    add_action( "to_help", "help" );
}

int to_help(string str)
{
   object player;
   if( !str || str != "worker" )
     return notify_fail("幫誰忙呢???\n");
   tell_object( this_player(), 
     "工人說: 謝啦, 聽說商店的老闆正在找工人, 你可以去試試看。\n" 
     );
   return 1;
}
