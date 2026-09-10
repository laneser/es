#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("silken threads","綸巾");
        add("id",({"threads","hat"}) );
        set_short("綸巾");
        set_long(
"這是一頂綸巾，是東方大陸的軍師才有資格戴的裝備。\n"
        );
        set( "unit", "頂" );
        set( "weight", 50 );
        set( "type", "head" );
        set( "material", "cloth" );
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "value", ({ 1200, "silver" }) );
        set( "no_sale",1);
}
