#include "../legend.h"

inherit MONSTER;

void create()
{

	::create();
	set_level(16);
	set_name( "crystal shapeshifter", "水晶變形蟲" );
	add( "id",({ "shapeshifter" }) );
        set_short( "水晶變形蟲" );
	set_long(@LONG
一隻通體透明的變形蟲，形狀就像麵糰一般，緩緩的在你面前蠕動著。變形蟲一口一
口吞食著樹薇，細碎的光點慢慢流進體內，看來十分有趣。 
LONG	);
	set_skill( "dodge", 100);
	set( "alignment", 1000 );
	set( "max_hp",300);
	set( "hit_points", 300);
	set( "special_defense",([ "all":80, "none":30 ]));
	set( "max_fp",1000);
	set( "race", "shapeshifter" );
	set( "gender", "female" );
	set_natural_armor( 10, 200 );
	set_natural_weapon( 80, 15, 20 );
        equip_armor( LARMOR"kernel1" );
}
