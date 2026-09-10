#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("snake gloves", "青蛇手套");
   add( "id", ({ "gloves" }) );
	set_short( "青蛇手套" );
        set_long(
@C_LONG
這是一雙由蛇皮所縫製的手套，上面有美麗的紋路，具有絕佳的伸
縮性，能適合任何尺寸的人來配戴。
C_LONG
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set( "material", "leather" );
   set( "armor_class", 4 );
   set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );                       
	set( "weight", 25 );
	set( "value", ({ 180, "gold" }) );
}
