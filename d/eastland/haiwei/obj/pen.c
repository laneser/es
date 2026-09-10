#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "judge-pen", "判官筆" );
	add( "id", ({ "pen" }) );
	set_short( "判官筆" );
	set_long( "這是一枝鐵鑄的判官筆。\n");
	set( "unit", "枝" );
	set( "type", "thrusting" );
	set( "weapon_class", 22 );
	set( "min_damage", 8 );
	set( "max_damage", 18 );
	set( "weight", 50 );
	set( "second", 1 );
	set( "value", ({ 440, "silver" }) );
	set_c_verbs( ({ "的%s往%s筆直劃下", "%s斜挑%s", "%s往%s一點",
		"的%s凌空一撇，順勢勾向%s", "%s虛晃一下，立即往%s直削過去",
		"%s筆鋒一帶，轉刺%s", "%s橫勾%s" }) );
}
