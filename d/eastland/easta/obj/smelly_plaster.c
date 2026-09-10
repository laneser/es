#include <mudlib.h>

inherit HERB;

void create()
{
        herb::create();
#include <compress_obj.h>
	set_name( "smelly plaster", "狗皮膏藥" );
        add( "id", ({"plaster"}) );
	set_short( "狗皮膏藥" );
	set_long("這張狗皮膏藥上標示著: 祖傳秘方，專治跌打損傷。\n");
	set( "unit", "張" );
	set( "heal_apply", 3 );
	set( "duration", 15 );
	set( "weight", 5 );
	set( "value", ({ 50, "silver" }) );
}
