#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "plaster", "金創藥" );
	set_short( "金創藥" );
	set_long("這盒金創藥上標示著: 外用藥(apply)，嚴禁服用。\n");
	set( "unit", "盒" );
	set( "heal_apply", 3 );
	set( "duration", 20 );
	set( "weight", 15 );
	set( "value", ({ 6, "gold" }) );
}
