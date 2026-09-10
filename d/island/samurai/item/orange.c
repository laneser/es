#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("orange","柳丁");
	add( "id" , ({ "orange" }) );
	set_short("柳丁");
	set_long(@AAA
	一個新鮮的柳丁，由於老闆的堅持你必須當場吃掉它
AAA
	);
   	set("unit","顆");
   	set("weight", 2);
   	set("value",({ 15, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if (owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"你吃下一顆汁多甘甜柳丁，感覺很滿足。\n");
		tell_room( environment(owner), 
			owner->query("c_name")+"吃下一顆柳丁看起來好像"
			"很滿足的樣子\n", owner
		);
		owner->receive_healing( 5+random(5) );
	}
	remove();
}
