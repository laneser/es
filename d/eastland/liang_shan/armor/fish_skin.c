#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("fish skin","魚皮水靠");
    add("id",({"fish","skin"}) );
    set_short( "fish skin","魚皮水靠");
	set_long(
		"This is a cloth made of skin of fish\n",
		"這是一大塊魚皮作成的衣服，滑溜溜，黏搭搭，摸起來頗為\n"
		"噁心，但在水中穿著卻可可以活動自如．\n"
	);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "armor_class", 19 );
        set("material","leather");
	set( "defense_bonus", 2 );
	set( "value", ({ 45, "gold" }) );
        set( "special_defense",(["none":4,"acid":-5]));
        set( "extra_skills",(["swimming":20]));
}
