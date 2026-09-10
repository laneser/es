#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Five-Color In", "五色印" );
	add( "id", ({ "shield","in" }) );
	set_short( "五色印" );
	set_long( 
@C_LONG
這是一顆漂亮的印石，上面閃耀著五種顏色的光芒。紅、綠、藍、白、黃色的光輝
交互閃爍著，令你目不暇給。
C_LONG
	);
	set( "unit", "顆" );
	set( "type", "shield" );
	set( "material", "stone");
	set( "armor_class", 8 );
	set( "defense_bonus", 6 );
	set( "special_defense",
	     ([ "none":5, "evil":5 ]) );
	set( "extra_skills",([ "block":7 ]) );     
	set( "weight", 50 );
	set( "no_sale", 1);
	set( "value", ({ 4750, "silver" }) );
}
