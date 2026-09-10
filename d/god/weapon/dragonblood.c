#include <mudlib.h>

inherit WEAPON;

string C_NAME="[37;1m龍血槍[37;0m";

void create()
{
	seteuid(getuid());
	set_name( "lance of dragonblood", C_NAME );
	add( "id", ({ "lance", "dragonblood" }) );
	set_short( "長槍「銀龍之血」" );
	set_long(
		"這就是許多諾頓騎士一生的夢想，完美的長槍「銀龍之血」。這把長槍\n"
		"據說是數百年前一條銀龍所守護的寶藏，許多人都相信這是工匠之神埃\n"
		"理亞(Ariah)贈送給人間最偉大騎士的禮物 ，這把長槍完美的造型與它\n"
		"無堅不摧的力量能帶給使用它的騎士最大的榮耀。\n"
	);
	set( "unit", "把" );
	set( "type", "jousting" );
	set( "weapon_class", 48 );
	set( "min_damage", 25 );
	set( "max_damage", 52 );
	set( "weight", 120 );
	set( "hit_func", "weapon_hit" );
	set( "value", ({ 5600, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit(object victim, int damage)
{
	if( (string)victim->query("race")!="dragon" ) return 0;
	victim->receive_special_damage( "magic", damage );

	return damage;
}



