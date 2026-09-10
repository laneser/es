#include "../ruin.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(16);
	set_name( "great demon", "大惡魔" );
	add ("id", ({ "daemon", "demon", }) );
	set_short( "大惡魔" );
	set_long( @C_LONG
黑魔從冥黑的世界呼喚出來的惡魔，在魔界的地位頗高，但亦會死心塌地的
為主人賣命，聽從主人的命令，至死方休。
C_LONG
	);
	set( "alignment", -1500 );
    set( "unit", "只" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "con", 22 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 25 );
	set ("max_hp", 720);
	set ("hit_points", 720);
	set ("persuing", 1);
	set ("aggressive", 1);
	set ("killer", 1);
	set_natural_weapon( 45, 20, 35 );
	set_natural_armor( 85, 35 );
    set ("weight", 400);
    set ("exp_reward",10000 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":50, "weakest":40, "ganglion":20, ]) );
    set ("special_defense", 
         ([ "fire":25, "cold":25, "enerage":25, "electric":25, ]) );
    set_experience(20000);
    set_skill("dodge",70);
    set_c_verbs( ({ "%s用爪子抓%s", "%s用角刺%s", "%s踢%s",
                    "%s咬%s", "%s用鐮刀橫劈%s", }) );
    set_c_limbs( ({ "頭", "身體", "腳", "角", "翅膀", }) );
    wield_weapon( OBJ"scythe" );
}
