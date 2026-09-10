#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "green cloak", "綠鬥蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "綠鬥蓬" );
	set_long( 
@LONG
這是□□所穿著的鬥蓬，其實只是一塊綠色的布，但這是從□□幼年時就穿到現
在，隨著主人一起修煉，已經有一種靈性，對於一些魔法有較強的抗力。
LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "mage");
	set( "armor_class", 5 );
	set( "defense_bonus", 6 );
	set( "extra_skills", ([
	  "black-magic" : 10, "white-magic" : -10, "elemental" : 5, ])
	);
	set( "special_defense", ([
	  "cold" : 30, "electric" : 20, "fire" : -10, ])
    );
	set( "no_sale", 1);
	set( "weight", 40 );
	set( "value", ({ 1000, "silver" }) );
}
