#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "medicine gloves","藥師手套" );
     add( "id",({ "gloves"}) );
     set_short( "藥師手套" );
     set_long(@C_LONG
一件以純棉製成的手套。這藥師手套上有特別塗上防毒防酸的藥材，但卻不耐燒。
C_LONG
     );
     set( "weight",40 );
     set( "unit", "件");
     set( "type", "hands" );
     set( "material","healer" );
     set( "armor_class",4 );
     set( "defense_bonus",3 );
     set( "value",({ 800,"silver" }) );
     set("special_defense",
        (["evil":20,"poison":20,"fire":-20,"cold":-20]) );
}
