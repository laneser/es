#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's cloak", "巫師鬥蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "a wizard's cloak", "巫師鬥蓬" );
	set_long( @LONG
	This cloak is used by wizard Rashudi. It is made by magical cloth and 
spreads a wanderful power of magic.
LONG
    , @C_LONG
	魔導士拉修帝慣於穿著的鬥蓬，由於用被附與魔法的布織成，散發出一股不可抵
抗的魔力，據說擁有抵抗各種魔法的能力。
C_LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 10 );
	set( "special_defense",
          ([ "electric":5, "energy":5, "mental":10 ]) );
    set( "extra_skill", ([ "elemental":10 ]) );     
	set( "weight", 30 );
	set( "no_sale", 1);
	set( "value", ({ 5800, "silver" }) );
}
