#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(11);
	set_name( "Balbal", "巴爾巴爾" );
	add ("id", ({ "balbal", }) );
	set_short( "巴爾巴爾" );
	set_long( @LONG
A gargoyle with no wings.
LONG
             , @C_LONG
因為長期在迷宮中生活的緣故, 翅膀已經退化的石像鬼。
C_LONG
	);
	set( "alignment", -1000 );
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "只" );
	set_perm_stat( "dex", 13 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 4 );
	set_perm_stat( "karma", 15 );
	set ("max_hp", 300);
	set ("moving", 1);
	set ("speed", 30);
	set ("hit_points", 300);
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon( 22, 12, 20 );
	set_natural_armor( 65, 20 );
    set ("weight", 600);
    set_c_limbs( ({ "身體", "頭", "腳", "角"}) );
    set_c_verbs( ({ "%s用角刺%s", "%s狂踢%s", "%s猛撞%s",}) );
    set ("exp_reward", 1450 );
    set_experience(14000);
}
