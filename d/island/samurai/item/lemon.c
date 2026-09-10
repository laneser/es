#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("lemon","檸檬");
	add( "id" , ({ "檸檬" }) );
	set_short("檸檬");
	set_long(@AAA
	一個新鮮的檸檬，由於老闆的堅持你必須當場吃掉它
AAA
	);
   	set("unit","顆");
   	set("weight", 2);
   	set("value",({ 50, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if (owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"你吃下一顆檸檬，實在有夠酸，但你依然覺得很舒服。\n");
		tell_room( environment(owner), 
			owner->query("c_name")+"吃下一顆檸檬，整個臉因為太酸而"
			"扭曲了．．．．\n", owner
		);
		owner->receive_healing( 5+random(10) );
	}
	remove();
}
