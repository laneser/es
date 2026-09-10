// HellParadise.c	地獄仙境
//
//	Effect: +MP100 +FP100
//		(迷幻藥系)
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

//#define ILLUSION "/u/l/lilia/drug/illusion"

inherit OBJECT;

void create()
{
    set_name("hell paradise", "地獄仙境");
    add("id", ({"hell", "paradise"}));
    set_short("地獄仙境");
    set_long("這是一粒黑色的丸藥，有股刺鼻的味道。\n");
    set("unit", "粒");
    set("weight", 15);
    set("value", ({ 500, "silver" }));
}

void init()
{
    add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    int max, mp;
    object p;

    p = this_player();

    if (!arg || (arg != "pill" && arg != "hell" && arg != "paradise"))
	return notify_fail("吃什麼??");
    write("你吃下了地獄仙境，頓時腦中浮現了無數的幻覺 ....\n");

    (CONDITION_PREFIX + "sick")->apply_effect(p, 4, 10, 5);
    (CONDITION_PREFIX + "weak")->apply_effect(p, 10, 2);
    p->set("medication_resistance", 350);
    max = p->query("max_sp");
    if (max) {
    if ((mp = p->query("spell_points")) >= max) { remove(); return 1; }
    if (mp + 100 > max) p->set("spell_points", max);
	else p->set("spell_points", mp+100); }
    max = p->query("max_fp");
    if (max) {
    if ((mp = p->query("force_points")) >= max) { remove(); return 1; }
    if (mp + 100 > max) p->set("force_points", max);
  	else p->set("force_points", mp+100);
    (CONDITION_PREFIX + "slow")->apply_effect(p, 8, 2); }
    remove();
    return 1;
}

