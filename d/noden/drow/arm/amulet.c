#include <mudlib.h>
inherit ARMOR;

void create()
{
   set_name("copper rings", "銅頸環");
   add( "id", ({ "rings" }) );
	set_short( "銅頸環" );
        set_long(
@C_LONG
這個銅環看起來已經年代久遠，但是仍然磨的光亮，是黑暗精靈的
裝飾品。
C_LONG
        );
	set( "unit", "個");
        set( "type", "misc" );
	set( "material", "heavy_metal" );
	set( "defense_bonus", 2 );                       
	set( "weight", 60 );
	set( "value", ({ 200, "silver" }) );
}
