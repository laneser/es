// plate.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic plate", "鎧魔甲");
    set_short("鎧魔甲");
    add("id", ({ "plate" }));
    set_long("由魔力幻化而成的鎧甲。\n");
    set("unit", "件");
    set("weight", 0);
    set("type", "body");
    set("material", "knight");
    set("armor_class", 35);
    set("defense_bonus", 6);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "鎧魔甲拒絕離開你的身體!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
