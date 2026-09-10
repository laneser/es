#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
          set_name( "iron", "熨斗" );
          add( "id", ({ "iron" }) );
     set_short( "熨斗" );
	set_long(
                 "一個普普通通的熨斗，上面刻著“多多贈”三個大字！\n"
	);
          set( "unit", "個" );
	set( "material", "cloth");
	set( "weight", 10 );
	set( "value", ({ 24, "silver" }) );
}
