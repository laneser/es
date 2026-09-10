#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "thunder gloves", "雷電手套" );
	add( "id", ({ "glove", "gloves", }) );
	set_short( "雷電手套" );
	set_long( 
@C_TOPIC
雷之護衛所戴的手套，隱約可以聽到有隆隆的雷聲傳出。
C_TOPIC
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "defense_bonus", 2 );
	set( "special_defense",
	    ([ "electric":10, "poison":-5 ]) );
	set( "extra_skills", ([ "parry":10 ]) );    
	set( "extra_stats", ([ "int": -1,"str": -1 ]) );
	set( "weight", 50 );
	set( "value", ({ 1700, "silver" }) );
}
