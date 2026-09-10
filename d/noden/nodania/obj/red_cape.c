#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red cape", "紅披風" );
	add( "id", ({ "cape" }) );
	set_short( "紅色披風" );
	set_long(@CLONG
一件用東方的絲綢精心縫製的紅色披風，上面繡著耶拉曼王家的標誌:
獅鷲獸。這件披風看起來不但昂貴，而且質地細密，穿在身上一點也不
會妨礙行動。
CLONG
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "cloak" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "energy":10, "mental":-10 ]) );
	set( "no_sale",1 );
	set( "value", ({ 310, "gold" }) );
}
