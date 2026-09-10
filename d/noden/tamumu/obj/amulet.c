#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet of Cybilas", "護身符" );
	add( "id", ({ "amulet" }) );
	set_short( "賽比拉斯護身符" );
	set_long(@C_LONG
這個護身符上閃爍著一點一點藍色的白光，像天空中最耀眼的星星，當你將它
握在手中的時候，可以感覺到它點溫暖。
C_LONG
        );
	set( "type", "misc" );
	set( "material" ,"element");
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", 
	      ([ "acid":5, "fire":5, "evil":-2 ]) );
	set( "weight", 15 );
	set( "value", ({ 205, "gold" }) );
}
