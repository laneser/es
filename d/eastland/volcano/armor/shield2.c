#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "dark shield", "□盾" );
	add( "id", ({ "shield" }) );
	set_short(  "□盾" );
	set_long( 
             @LONG
這個盾是左無心學藝完成，下山以前，他的師父交給他的，據他師父說這個盾不
怕任何邪惡的攻擊，是左無心殺妖除魔重要的防具。
LONG
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "evil":15, "mental":-5 ]) );
	set( "extra_skills",([ "block":5 ]) );     
	set( "weight", 130 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
