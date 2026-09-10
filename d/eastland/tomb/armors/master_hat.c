#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("gold dauist hat", "紫金道冠");
        add( "id", ({ "hat" }) );
        set_short("紫金道冠");
        set_long(
                "這是傳說中神仙所使用的道冠，能得到它的人往往很有仙緣． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "mage");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":5, "divine":5, "mental":4 ]) );
        set( "weight", 60 );
        set( "value", ({ 450, "gold" }) );
}



