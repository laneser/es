#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("copper bracers", "黃銅手環");
   add( "id", ({ "bracers" }) );
	set_short( "黃銅手環" );
        set_long(
@C_LONG
這是黃銅打造的手環，拿起來有厚重的感覺。
C_LONG
        );
	set( "unit", "個");
        set( "type", "hands" );
	set( "material", "heavy_metal" );
	set( "armor_class", 4 );
	set( "defense_bonus", 2 );                       
	set( "weight", 60 );
	set( "value", ({ 170, "silver" }) );
}
