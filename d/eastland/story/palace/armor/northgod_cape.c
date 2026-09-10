#include "../../story.h"

inherit SARM"OR";
inherit ARMOR;

void create()
{
     set_name( "Crystal cape","水晶雲肩" );
     add( "id",({ "cape" }) );
     set_short( "水晶雲肩" );
     set_long(@C_LONG
一件水晶製成的披風，不時散發著些微寒氣。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "cloak" );
     set( "material","element" );
     set( "the_one",1);
     set( "armor_class",6 );
     set( "defense_bonus",3 );
     set( "value",({ 4000,"silver" }) );
     set( "special_defense",(["fire":-20,"cold":40]));
}
