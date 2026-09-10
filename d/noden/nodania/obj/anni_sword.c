#include "../nodania.h"

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("sword", "亂環劍");
	add( "id", ({ "sword" }) );
	set_short("亂環劍");
	set_long(
	"這是安尼席洛特爾大神隨身攜帶的劍，上面鑲著許多閃亮的水晶環。\n"
	);
	set( "unit", "把" );
	set( "weight", 10 );
// Only wizards or monsters can wield this weapon.
	set( "weapon_class", 33 );
	set( "type", "longblade" );
	set( "min_damage", 16 );
	set( "max_damage", 44 );
	set( "value", ({ 300, "platinum" }) );
	set( "no_sale", 1 );
}
