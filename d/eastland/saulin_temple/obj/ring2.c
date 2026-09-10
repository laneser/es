#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("king-kong ring","金剛指環");
        add("id",({"ring"}) );
	set_short("金剛指環");
	set_long(
"這是由金剛界--東方金剛部第二金剛王所使用過的指環,具有非凡的防禦力\n"
);
	set( "unit", "個" );
	set( "weight", 10 );
	set("material","element");
	set( "type", "finger" );
	set("armor_class",0);
	set( "defense_bonus", 8 );
	set( "value", ({ 250, "gold" }) );
}
