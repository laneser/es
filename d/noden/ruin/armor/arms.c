// arms.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic arms", "鎧魔臂");
    set_short("鎧魔臂");
    add("id", ({ "arms", "armband" }));
    set_long("由魔力幻化而成的臂環。\n");
    set("unit", "對");
    set("weight", 0);
    set("type", "arms");
    set("material", "knight");
    set("armor_class", 4);
    set("defense_bonus", 4);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "鎧魔臂拒絕離開你的身體!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
