#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "white plaster", "雲南白藥" );
	add( "id", ({ "plaster", "yun-nan white plaster" }) );
	set_short( "雲南白藥" );
	set_long(
		"這是由東方大國進口的雲南白藥，盒子上標示著: 外用藥(apply)，嚴禁服用。\n"
	);
	set( "unit", "盒" );
	set( "heal_apply", 5 );
	set( "duration", 30 );
	set( "weight", 15 );
	set( "value", ({ 150, "silver" }) );
}
