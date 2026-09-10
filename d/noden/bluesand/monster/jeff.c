#include <mudlib.h>

inherit MONSTER;

void create()
{
	object obj1;

	::create();
	set_level(4);
	set_name( "Jeff", "傑夫" );
	set( "id", ({ "jeff", "sailor" }) );
   set_short( "老水手傑夫" );
	set_long(
		"老傑夫年輕的時候曾經是一名強壯勇敢的水手，但是現在他已經又老又\n"
		"病，再也沒有辦法出海了。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 250 );

	set_perm_stat( "str", 6 );
	set( "wealth/silver", 20 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "wimpy", 80 );
	set( "tactic", "flank" );
	
	set_skill("dodge",30);
	set_skill("tactic",30);

	set_natural_armor( 23, 8 );
	set_natural_weapon( 5, 3, 8 );

	wield_weapon( "/d/noden/bluesand/item/stick" );
}

void die()
{
    tell_room( environment(),
		"傑夫口吐鮮血，倒在地上。\n"
		"傑夫口中喃喃地咒罵道: 你 ... 你們 .... 一定會付 ... 出代價的！\n"
		"傑夫從口袋中取出一個奇怪的煙火，用顫抖的手點燃煙火，射向空中。\n"
            "當你低頭再去看傑夫，發現他已經一動也不動 .... 死了。\n",
		this_object() );
	"/adm/daemons/event/pirate"->start_war();
	::die(1);
}
