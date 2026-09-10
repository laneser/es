#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
	set_name( "branz herb", "布蘭茲藥草" );
	add( "id", ({ "herb" }) );
	set_short( "布蘭茲藥草" );
	set_long(
		"據說如果把布蘭茲藥草敷(apply)在傷口上，會使傷口恢復得比較快。\n"
	);
	set( "unit", "束" );
	set( "heal_apply", 2 );
	set( "duration", 10 );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
