#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("cook cloth","油膩的廚師服");
    add("id",({"cloth"}) );
    set_short( "cook cloth","油膩的廚師服");
	set_long(
		"???\n",
		"這是一件看來很油膩的廚師工作服,散發出一股難聞之氣味\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 140, "gold" }) );
}
