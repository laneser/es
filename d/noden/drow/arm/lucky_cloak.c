#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky cloak", "幸運鬥蓬");
        add( "id", ({ "cloak" }) );
        set_short( "幸運鬥蓬" );
        set_long(
@C_LONG
這件白色的鬥蓬據說是畢老爹在離開黑暗精靈村時，送給神官薩林
的離別紀念品，上面縫有小刀的圖案，也是小偷工會的標記，能在
戰鬥時為您帶來好運。
C_LONG
        );
        set( "unit", "領");
        set( "type", "cloak" );
   set( "material", "thief" );
   set( "armor_class", 7 );
   set( "defense_bonus", 10 );
        set( "special_defense",
               ([ "fire": -10 ]) );
   set("extra_skills", ([ "dodge" : 10 ]) );
   set( "weight", 55 );
        set( "value", ({ 2650, "silver" }) );
        set( "no_sale", 1);
}
