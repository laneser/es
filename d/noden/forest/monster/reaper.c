#include "../forest.h"
inherit MONSTER;

void create()
{
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "small reaper", "小樹妖" );
	add ("id", ({ "reaper", }) );
	set_short( "小樹妖" );
	set_long( @C_LONG
它看起來就像是一棵沒有枝葉的樹, 手裡拿著短刀, 用看起來像是樹
根的腳走路。看來可能很難應付。
C_LONG
	);
	set( "alignment", -200 );
    set( "race", "human" );
    set( "unit", "只" );
    set( "aggressive", 1);
    set_skill( "longblade", 40);
    set( "wealth/silver", 20 );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 8 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 3 );
	set("unbleeding", 1);
	set("special_defense", ([ "all": 50, "fire":25, ]) );
	set("aim_difficulty", ([ "critical":20, "weakest":30, "ganglion":50, ]) );
	set_natural_armor( 40, 10 );
	set_natural_weapon( 10, 3, 6 );
    set ("weight", 550);
    set_c_limbs( ({ "像身體的樹幹", "像手腳的枝幹", "像腳的樹根"}) );
    wield_weapon( OBJ"blade" );
}
