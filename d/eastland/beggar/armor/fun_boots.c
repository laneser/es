#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name("six sun boots","六陽元靴");
     add( "id", ({ "boots" }) );
     set_short( "六陽元靴" );
     set_long(@C_TOPIC
一雙繡著六日的靴子。靴子上面的手工很精緻,非一時可以完成。
C_TOPIC
              );
     set( "unit", "雙" );
     set( "type", "feet" );
     set( "material", "cloth" );
     set( "armor_class", 2 );
     set( "defense_bonus", 1 );
     set( "weight", 60 );
     set("special_defense",(["magic":15,"evil":-20]) );
     set( "value", ({ 200, "silver" }) );
}