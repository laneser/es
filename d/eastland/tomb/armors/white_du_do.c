#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white du-do", "白肚兜" );
	add( "id", ({ "du-do","do" }) );
	set_short( "白肚兜");
	set_long( 
@C_LONG
這是一件白色的肚兜，上面有個大大的金字--「福」。雖然穿起來可能有點好笑，但
是卻能提供相當好的保護。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 3 );
	set( "special_defense" ,
	      ([ "divine": 10,"evil":-5 ]) );
	set( "value", ({ 1200, "silver" }) );
}
