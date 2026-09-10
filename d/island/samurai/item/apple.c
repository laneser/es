#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("apple","蘋果");
	add( "id" , ({ "蘋果" }) );
	set_short("apple" , "蘋果");
	set_long(@AAA
	一個新鮮的蘋果，由於老闆的堅持你必須當場吃掉它
AAA
	);
   	set("unit","顆");
   	set("weight", 2);
   	set("value",({ 20, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if ( owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"你吃下一顆新鮮蘋果，咬起來有夠脆，汁又多讓你還想再吃一個。\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"吃下一顆蘋果看起來好像很愉快的樣子\n"
			, owner
		);
		owner->receive_healing( 5+random(5) );
	}
	remove();
}
