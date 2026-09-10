#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silk tail", "黑絲綁尾" );
	add( "id", ({ "silk","tail" }) );
	set_short( "黑絲綁尾" );
	set_long(
"這是一副用黑蠶絲編成的護套，專門用來保護蜥蜴人的尾巴。\n"
	);
	set( "unit", "副" );
        set("material","cloth");
	set( "type", "tail" );
	set( "armor_class", 5 );
	set( "weight", 70 );
	set( "value", ({ 240, "silver" }) );
}
