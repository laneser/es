#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "medicine robe","藥師診袍" );
     add( "id",({ "cloth","robe"}) );
     set_short( "藥師診袍" );
     set_long(@C_LONG
一件純棉製成的衣服。在這件衣服上面另塗有某些藥材，都是用來防毒和防酸的。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","healer" );
     set( "armor_class",32);
     set( "defense_bonus",7 );
     set( "value",({ 1000,"silver" }) );
     set("special_defense",
        (["evil":30,"poison":30,"fire":-30,"cold":-30]) );
}
