#include "../saulin_temple.h"

inherit CONTAINER;

void create()
{
	object gourd;
	::create();
	set_name("Well", "井");
	set_short("井");
	set("id", ({"well"}) );
	set_c_open_long(@C_LONG
你走到井邊望井裡一看，哎呀! 井水都已經乾了，井底乾裂的泥土形成一條條
縱橫的大縫。你應該可以爬(climb)下井底看看。
C_LONG
	);
	
	set("prevent_get",1);
	set("max_load",500);
	set("prevent_insert",1);
	gourd = new( SAULIN_OBJ"gourd" );
	gourd->move( this_object() );
}
