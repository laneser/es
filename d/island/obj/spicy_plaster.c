#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "spicy plaster", "天香斷續膏" );
	add( "id", ({ "plaster" }) );
	set_short( "天香斷續膏" );
	set_long(@C_LONG
這是一盒著名的外傷靈藥「天香斷續膏」，採用了超過一百種產自翰煙山
的稀有藥草熬製而成，如果敷(apply)在傷處，有恢復神效。
C_LONG
	);
	set( "unit", "盒" );
	set( "heal_apply", 7 );
	set( "duration", 30 );
        set( "weight", 15 );
	set( "value", ({ 25, "gold" }) );
}
