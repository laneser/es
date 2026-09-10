#include "/u/e/echobomber/echobomber.h"

inherit ARMOR;

void create()
{
        set_name("stone beads","黑晶石念珠");
        add("id",({"bead","beads",}) );
         set_short("黑晶石念珠");
	set_long(@C_LONG
這是一串由南海黑晶石做成的念珠,看起來閃閃發光... 
這一串念珠戴在脖子上,散發出一股厚重沉靜的氣息 
C_LONG
	);
	set( "unit", "串" );
	set( "weight", 15 );
	set( "material", "monk" );
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 50, "gold" }) );
}
