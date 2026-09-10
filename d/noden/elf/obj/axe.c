
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name("golden battleaxe", "黃金戰斧");
        add ("id",({ "axe", "battleaxe" }) );
        set_short( "黃金戰斧" );
        set_long(
            "這是一把閃亮的黃金戰斧，它巨大斧刃顯示出這是把罕見的強力武器。\n"
        );
        set("nosecond", 1);
        set("unit", "把");
        set( "weapon_class", 33 );
        set( "type", "axe" );
        set( "min_damage", 20 );
        set( "max_damage", 45 );
        set( "weight", 300);
        set( "value", ({ 300, "gold" }) );
}

