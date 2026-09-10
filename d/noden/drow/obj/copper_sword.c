#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "copper sword","銅刃");
        add( "id",({ "sword" }) );
        set_short( "銅刃");
        set_long(
@CLONG
這是把由粗銅所打造的長劍，握柄處還有綠色的銅鏽在。
CLONG
                );
        set( "unit", "把" );
        set( "weapon_class", 18 );
        set( "type", "longblade" );
        set( "min_damage", 17 );
        set( "max_damage", 23 );
        set( "weight", 110 );
        set( "value", ({ 300, "silver" }) );
}
