#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(14);
	set_name( "Minaceus", "米娜修斯" );
	add( "id", ({ "minaceus", "bard" }) );
	set_short(  "流浪詩人米娜修斯" );
	set_long(@CLONG
米娜修斯是諾達尼亞著名的吟遊詩人，她優雅的歌聲和美麗的臉龐不知道
風靡了多少王公貴族，但是她寧願一個人自由自在的到處旅行，因為她認
為世界上沒有比四處旅行和音樂更令人陶醉的事。
CLONG
	);
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 22 );

	set( "race", "elf" );
	set( "gender", "female" );
	set( "wealth/silver", 220 );
	set( "alignment", 400 );

	set_skill( "dagger", 90 );
	set_skill( "dodge", 70 );
	set_skill( "parry", 40 );
	set( "natural_armor_class", 55 );
	set( "natural_defense_bonus", 24 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 8 );

	ob1 = new("/d/noden/nodania/obj/ivory_dagger");
	ob1->move(this_object());
	wield_weapon(ob1);

	ob2 = new("/d/noden/nodania/obj/white_suit");
	ob2->move(this_object());
	equip_armor(ob2);

	ob3 = new("/d/noden/nodania/obj/white_cape");
	ob3->move(this_object());
	equip_armor(ob3);
}
