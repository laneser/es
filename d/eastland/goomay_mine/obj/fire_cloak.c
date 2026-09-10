#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire cloak", "火披風" );
	add( "id", ({ "fire","cloak" }) );
	set_short( "fire cloak", "火披風" );
	set_long(@C_LONG
	一件非常奇特的披風，若有似無，還散發出陣陣的熱氣，對於寒冷系
	的攻擊有特殊的防禦能力．
C_LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 6 );
	set( "defense_bonus", 7 );
	set( "special_defense",
          ([ "cold":10 ]) ) ;
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
}
