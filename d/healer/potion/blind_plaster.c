#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	set_name("blind plaster", "明目膏" );
	add( "id", ({"plaster"}) );
	set_short("明目膏");
	set_long(
		"這是用來治療輕微眼睛傷害的藥膏, 把他塗(apply)在眼睛上可以改善\n"
		"失明的狀況, 如果傷的太重, 還是要靠手術醫療。\n"
	);
	set( "can_apply", 1 );
	set( "unit", "份" );
	set( "weight", 20 );
	set( "value", ({ 100, "silver" }) );
}

int apply(object player)
{
	int degree;
	if( !(degree=player->query("blind")) ) return 0;
	if( degree > 5) {
	  tell_object(player, "你的眼傷太重, 敷藥已經沒用了, 找醫生動手術吧。\n");
	  return 1;
	}  
	degree--;
	if (degree<1) { 
	  player->delete("blind");
	  tell_object(player, "你的眼睛又能看到東西了。\n");
	}  
	else {
	  player->set("blind",degree);
	  tell_object(player,"你的眼睛好了一些, 但仍看不清楚。\n");
	}  
	return 1;
}
