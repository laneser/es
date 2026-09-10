// flute.c

#include "../lilia.h"

inherit WEAPON;

void create()
{
    set_name("Silver flute", "銀色長笛");
    set_short("銀色長笛");
    add("id", ({"flute"}));
    set("unit", "把");
    set("weapon_class", 35);
    set("type", "blunt");
    set("min_damage", 10);
    set("max_damage", 25);
    set("weight", 100);
    set("value", ({1500, "silver"}));
    set("hit_func", "fireball");
}

int fireball(object victim, int damage)
{
    object p;

    if (!(p = environment(this_object())) || !living(p)) return 0;
    if (random(10) > 4) return 0;
    victim->receive_special_damage("fire", 5);
    victim->set("last_attacker", p);
    tell_object(p, set_color("\n你的銀色長笛吹奏出一顆火球燃燒著敵人！\n", "HIR"));
    tell_room(environment(p), set_color(p->query("c_name")+"的銀色長笛吹奏出一顆火球燃燒著"+victim->query("c_name"), "HIR"), p);

    return 1;
}

