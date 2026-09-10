#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black du-do", "黑肚兜" );
	add( "id", ({ "du-do","do" }) );
	set_short( "黑肚兜");
	set_long( 
@C_LONG
這是一件黑色的肚兜，上面畫了一隻猙獰的麒麟。雖然穿起來可能有點好笑，但
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
	      ([ "divine": -5,"evil":10 ]) );
	set( "extra_skills", ([ "runes" :10 ]) );
	set( "value", ({ 1200, "silver" }) );
}
