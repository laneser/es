
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "Dwarf baby", "矮人嬰孩" );
	add ("id", ({ "baby", "dwarf", }) );
	set_short( "Dwarf baby", "矮人嬰孩" );
	set_long(
	" a crying baby.\n",
    "一個呱呱大哭的小嬰兒.\n"
    );
    set( "alignment",10);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "kar", 3 );
	set ("natural_weapon_class1", 3);
	set ("natural_armor_class", 7);
	set ("natural_min_damage1", 1);
	set ("natural_max_damage1", 4);
    set ("weight", 100);
   // set ("chat_chance", 25);
	equip_armor(Armour"/amulet03");
}
