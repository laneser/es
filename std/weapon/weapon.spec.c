//  File     : /std/weapon/weapon.spec.c
//  /std/weapon/weapon.c 的 spec —— 全站所有武器都繼承它，
//  setup_weapon() 設下的四個值直接餵給戰鬥計算。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

void test_setup_weapon(object ob)
{
	ob->setup_weapon("longblade", 30, 10, 20);
	expect_eq( ob->query("type"), "longblade", "武器類型" );
	expect_eq( ob->query("weapon_class"), 30, "武器等級" );
	expect_eq( ob->query("min_damage"), 10, "最小傷害" );
	expect_eq( ob->query("max_damage"), 20, "最大傷害" );
}

void test_damage_range_sane(object ob)
{
	ob->setup_weapon("dagger", 12, 4, 9);
	expect_true( ob->query("min_damage") <= ob->query("max_damage"),
		"最小傷害不該大於最大傷害" );
}

void test_inherits_prop_system(object ob)
{
	//  武器也是物件，ob_data 那一套要能用
	ob->set("value", ({ 150, "gold" }));
	expect_true( pointerp(ob->query("value")), "武器應該能照常使用 ob_data" );
}

void test_setup_weapon_is_overwritable(object ob)
{
	//  同一把武器被重新 setup（例如強化、變形）時要能蓋掉舊值
	ob->setup_weapon("blunt", 5, 1, 2);
	ob->setup_weapon("blunt", 50, 20, 40);
	expect_eq( ob->query("weapon_class"), 50, "重新 setup 應該覆寫舊值" );
}
