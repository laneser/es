#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black cloak", "黑鬥蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "黑鬥蓬" );
	set_long( @C_LONG
冥黑魔導士黑魔慣於穿著的黑色鬥蓬，看起來破破爛爛，但卻散發出一股邪惡
的力量，據說能抵抗各種黑魔法的攻擊。
C_LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "mage");
	set( "armor_class", 8 );
	set( "defense_bonus", 6 );
	set( "extra_stats", ([
	"int" : 3, "pie" : -5, "con" : -4, ])
	);
	set( "extra_skills", ([
	  "black-magic" : 10, "white-magic" : -10, "elemental" : 5, ])
	);
	set( "special_defense", ([
	  "cold" : 30, "electric" : 20, "fire" : -10, ])
    );
	set( "no_sale", 1);
	set( "weight", 40 );
	set( "value", ({ 5, "silver" }) );
}
