#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "three moon gloves", "三陰玄套" );
	add( "id", ({ "gloves" }) );
	set_short( "三陰玄套" );
	set_long(@C_LONG
一雙讓你感覺得到陣陣寒意的手套。
C_LONG
	);
	set( "unit", "雙" );
        set("material","cloth");
	set( "type", "hands" );
	set( "weight", 70 );
        set( "defense_bonus", 1 );
        set("special_defense",(["magic":15,"divine":-15]) );
	set( "value", ({ 240, "silver" }) );
}
