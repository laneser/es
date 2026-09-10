// googol.c
// A patrolling and talking monster.
// He uses the say command so that he may speak in different languages.
// If you just want a monster to speak in Common, you can use the
// chat_chance property instead, which is easier and faster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>

inherit MONSTER;

void create ()
{
	object bo;

	::create();
	set_level(19);
	set_name( "hong chigon", "洪七公" );
	add ("id", ({ "hong", "chigon", "beggar chief", "beggar", "chief" }) );
	set_short( "Hong Chigon the Beggar Chief", "九指神丐洪七公" );
	set_long(
		"Hong Chigon is the legendary beggar and he is the leader of the\n"
		"beggar's gang. He likes eating very much and is always looking for\n"
		"delicious foods.\n",
		"洪七公是傳說中丐幫的老幫主，他非常喜歡吃，常常跑遍天下尋找各種珍\n"
		"奇美味。\n"
	);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );

	set ("max_hp", 500);
	set ("hit_points", 500);

	set ("wealth", ([ "gold":300 ]) );

	set ("gender", "male");

	set ("natural_armor_class", 40);
	set ("natural_weapon_class1", 40);
	set ("natural_min_damage1", 25);
	set ("natural_max_damage1", 60);

	set ("chat_chance", 40);
	set ("att_chat_output", ({
		"Chigon cackles and says: Let's me teach you how to fight, Kids!\n",
		"洪七公哈哈大笑: 小兔崽子，讓老叫化子指點你幾手。\n",
		"Chigon turns around while striking you with palms.\n",
		"洪七公轉身背對著你，手掌向後推出，說道: 這招叫「神龍擺尾」。\n",
		"Chigon mumbers: Hmmm... should I beat you so easily?\n",
		"洪七公沉吟道: 唔... 要用哪一招才不會失手打死你... ？\n",
		"Chigon smiles and says: Good, it would be a match if you fight with my children.\n",
		"洪七公說道: 不錯，你再練幾年就可以和我徒兒郭靖過招玩玩。\n",
		"Chigon get a chicken from his bag, chews a piece of it and put the chicken in bag again.\n",
		"洪七公從容不迫地從懷裡取出一根雞腿，咬了一口又放回懷中。\n"
	}) );

	bo = new("/obj/example/weapon/bo");
	bo->move(this_object());
	wield_weapon(bo);
}

