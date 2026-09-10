#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Queen's helmet","玉勝" );
     add( "id",({ "helmet", }) );
     set_short( "玉勝" );
     set_long(@C_LONG
玉勝雖然算是婦人的首飾，卻如穿耳的環，男女皆可戴。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "頂");
     set( "type", "head" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "value",({ 1000,"silver" }) );
     set( "special_defense",(["acid":30]));
}
