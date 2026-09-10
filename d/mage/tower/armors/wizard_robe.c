#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's robe", "巫師魔袍" );
	add( "id", ({ "robe", }) );
	set_short( "a wizard's robe", "巫師魔袍");
	set_long( @LONG
	This robe is used by wizard Rashudi. It is made by magical cloth,
so spreads a strong power of magic.
LONG
    , @C_LONG
	這是魔導士拉修帝慣於穿著的服裝，不要看它只是用普通的布織成，它可是擁有
出乎你意料之外的防禦力，據說還能抵抗各種魔法。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 45 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 35 );
	set( "defense_bonus", 10 );
	set( "special_defense" ,
	      ([ "evil": 10, "none":2 ]) );
	set( "extra_skills", ([ "magic-shield" :10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 2000, "silver" }) );
}
