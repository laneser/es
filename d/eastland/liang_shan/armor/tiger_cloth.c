#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("tiger fur cloth","虎皮套體");
    add("id",({"fur","cloth"}) );
    set_short( "tiger fur cloth","虎皮套體");
	set_long(
		"This is a cloth made of fur of tiger\n",
		"這是用虎皮製成的衣物，剪裁非常的樸實無華，略能敝體．\n"
	);
	set( "unit", "件" );
	set( "weight", 160 );
	set( "type", "body" );
	set( "armor_class", 24 );
        set("material","leather");
	set( "defense_bonus", 3 );
	set( "value", ({ 75, "gold" }) );
        set( "special_defense",(["none":8]));
}
