#include "../nodania.h"

inherit "/d/noden/nodania/monster/knight";

object weap, armor;

void create()
{
	::create();
	set_level(13);
	set_name("tower guard", "衛兵" );
	add( "id", ({ "guard" }) );
	set_short( "看守塔樓的衛兵" );
	set_long(
		"這個衛兵正在塔樓上擔任警戒任務，他看起來有些疲倦。\n"
	);
   set( "alignment", 500 );
	set_perm_stat("str",16);
	set_perm_stat("dex",15);
	set_skill("parry", 50);

	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 40 );
	set( "war_score", 500 );

	wield_weapon("/d/knight/fortress/weapons/longsword");
	equip_armor("/d/knight/fortress/armors/chainmail");
}
