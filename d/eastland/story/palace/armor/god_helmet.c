#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon helmet","亢龍盔" );
     add( "id",({ "helmet", }) );
     set_short( "亢龍盔" );
     set_long(@C_LONG
一頂太白金精製成的頭盔，彷造龍的形狀做成的。
C_LONG
     );
     set( "weight",40 );
     set( "unit", "頂");
     set( "type", "head" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "the_one",1);
     set( "value",({ 2000,"silver" }) );
}
