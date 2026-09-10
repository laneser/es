#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("puty beads ","菩提念珠");
    add("id",({"bead","beads",}) );
    set_short("菩提念珠");
	set_long(@C_LONG
這是一串由千年菩提子做成的念珠, 由於使用很久, 看起來很舊了。
這一串念珠散發出一股寧靜的氣息, 帶給你心靈的平靜。
C_LONG
	);
	set( "unit", "串" );
	set( "weight", 15 );
        set("material","wood");
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 180, "gold" }) );
}
