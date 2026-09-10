#include "../dony.h"

inherit ARMOR;

void create()
{
	set_name( "seven gloves", "七彩雲套" );
	add( "id", ({ "seven","gloves" }) );
	set_short( "seven gloves", "七彩雲套" );
	set_long(@C_LONG
這是一雙由智慧草編織而成的手套，據說戴上它可以增加你的智慧哦 !!
C_LONG
	);
	set( "unit", "雙" );
        set("material","cloth");
	set( "type", "hands" );
	set( "weight", 40 );
	set( "armor_class",3 );
        set( "defense_bonus", 5 );
	set( "value", ({ 240, "silver" }) );
}
