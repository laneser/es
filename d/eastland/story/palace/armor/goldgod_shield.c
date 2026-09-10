#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Gold-God's shield","曲盾" );
     add( "id",({ "shield" }) );
     set_short( "曲盾" );
     set_long(@C_LONG
一面黃金製成的盾牌，圓圓的，好似一顆大球。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "面");
     set( "type", "shield" );
     set( "material","heavy_metal" );
     set( "armor_class",5 );
     set( "defense_bonus",1 );
     set( "value",({ 1500,"silver" }) );
}
