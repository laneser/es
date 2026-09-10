#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("guardian of auction Co.", "拍賣公司守衛");
        add ("id", ({ "guard","guardian","troll" }) );
	set_short( "拍賣公司守衛");
	set_long(@LONG
你看到一個龐大的怪漢，不要懷疑，他就是傳說中的怪力巨人。拍賣公司特地
使用強大的魔法從魔界把他召喚出來，為拍賣公司守護龐大的財富，頭腦簡單的他
十分盡責，所以你千萬不要打歪主意，因為他只要隨手一巴掌，就可能把你打扁。
LONG
	);
	set( "unit", "個" );
	set( "alignment", -600 );
	set_perm_stat( "str",30);
	set_perm_stat( "dex", 24 );
        set_perm_stat( "int", 22 );
        set_perm_stat( "con", 30 );
	set_perm_stat( "pie",21);
        set_perm_stat( "kar", 18);
	set( "max_hp",1200);
	set( "hit_points",1200);
	set_natural_weapon( 100, 40,80 );
        set_natural_armor( 70, 50 );

}

void die()
{
	object killer ;
	int money ;
	killer = this_object()->query("last_attacker");
	money = environment(this_object())->query("money");
        if (killer)
	killer->add("wealth/silver",money);
	environment(this_object())->delete("money");
	::die(1);
	tell_object(killer,"打死守衛後，你趕快搜括保險箱裡的錢 ....\n"
		"你得到了 "+money+" 枚銀幣。\n");
}
