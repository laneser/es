// leggings.c

#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic leggins", "月神襠");
    set_short("月神襠");
    add("id", ({ "gloves", "gauntlets" }));
    set_long("由月神劍的神力幻化而成的脛甲。\n");
    set("unit", "件");
    set("weight", 0);
    set("type", "legs");
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "月神襠拒絕離開你的身體!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
