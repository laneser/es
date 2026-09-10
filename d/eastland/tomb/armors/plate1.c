#include "../almuhara.h"

inherit ARMOR;

void create()
{
        set_name("Holy plate","東天聖甲");
        add("id",({"plate","platemail"}) );
        set_short( "東天聖甲");
	set_long(
"這是一副由某種奇異金屬所造的鎧甲,可以保護你抵抗敵人的攻擊。當你面對邪惡的
敵人時，它可以提供更好的防護力。\n"
	);
	set( "unit", "件" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 35 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([ "evil" : 20 ]) );
	set( "value", ({ 320, "gold" }) );
}
