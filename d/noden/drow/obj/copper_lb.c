#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "copper longsword","精銅長刃");
        add( "id",({ "sword","longsword" }) );
        set_short( "精銅長刃");
        set_long(
@CLONG
    這是把用高級純銅所打造的長刀，刀鋒銳利，而刀柄用細長的布纏
    /住/，只有高級的黑暗精靈武士能擁有。    
CLONG
                );
        set( "unit", "把" );
        set( "weapon_class", 20 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 32 );
        set( "weight", 110 );
        set( "value", ({ 700, "silver" }) );
}
