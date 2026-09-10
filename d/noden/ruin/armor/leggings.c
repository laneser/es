// leggings.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic leggins", "鎧魔襠");
    set_short("鎧魔襠");
    add("id", ({ "gloves", "gauntlets" }));
    set_long("由鎧魔劍的魔力幻化而成的脛甲。\n");
    set("unit", "件");
    set("weight", 0);
    set("type", "legs");
    set("material", "knight");
    set("armor_class", 8);
    set("defense_bonus", 3);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "鎧魔襠拒絕離開你的身體!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
