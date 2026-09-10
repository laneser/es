// helm.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic helmet", "鎧魔盔");
    set_short("鎧魔盔");
    add("id", ({ "helmet", "helm" }));
    set_long("由魔力幻化而成的頭盔。\n");
    set("unit", "頂");
    set("weight", 0);
    set("type", "head");
    set("material", "knight");
    set("armor_class", 8);
    set("defense_bonus", 3);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "鎧魔盔拒絕離開你的身體!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
	::unequip(0);
    return ::remove();
}
