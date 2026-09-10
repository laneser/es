#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather saddle", "皮革馬鞍" );
	add( "id", ({ "saddle" }) );
	set_short( "皮革馬鞍" );
	set_long(
	"這是一副普通的皮革制馬鞍，騎士們都會為自己的愛馬選擇舒適的馬鞍。\n" 
	);
	set( "type", "saddle" );
	set( "material", "leather" );
	set( "armor_class", 3 );
	set( "weight", 75 );
	set( "value", ({ 230, "silver" }) );
}
