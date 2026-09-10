#include "../ruin.h"
inherit MONSTER;

#define MIN_GARGOYLES 6

void create()
{
	::create();
	seteuid( getuid() );
	set_level(9);
	set_name( "Gargoyle", "石像鬼" );
	add ("id", ({ "gargoyle", }) );
	set_short( "石像鬼" );
	set_long( @C_LONG
能使用背部的翅膀在天空中飛翔, 不過比較喜歡居住在黑暗的角落。會使用
頭上的兩隻角, 攻擊敵人。
C_LONG
	);
	set( "alignment", -250 );
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "只" );
    set( "killer", 1);
	set_perm_stat( "dex", 14 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 13 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 10 );
	set("max_hp", 400);
	set("hit_points", 400);
	set("unbleeding", 1);
	set("special_defense", ([ "all":30, "none":15, ]) );
	set("aim_difficulty",
		([ "critical":30, "ganglion":50, "weakest":20, ]) );
	set_natural_weapon( 40, 10, 18 );
	set_natural_armor( 55, 10 );
    set("weight", 550);
    set_c_limbs( ({ "的身體", "的頭", "的腳", "的角"}) );
    set_c_verbs( ({ "%s用角刺%s", "%s踢%s", "%s撞%s",}) ); 
}

void die()
{
	object env;
	env = environment(this_object());
	if( env->query("mob_storage") && 
		((int)env->query("mob_storage") > MIN_GARGOYLES) )
		env->add("mob_storage", -1);
	::die();
}
