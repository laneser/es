#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("orange","柳丁");
	add( "id" , ({ "orange" }) );
	set_short("orange" , "柳丁");
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
		tell_object(owner, can_read_chinese()?
			"你吃下一顆新鮮柳丁，感覺很滿足。\n":
			"You drink a cup of Special Wine....\n"
		);
		tell_room( environment(this_player()), ({
			owner->query("cap_name")+" drink a cup of Special Wine....\n",
			owner->query("c_name")+"吃下一顆柳丁看起來好像"
			"很滿足的樣子\n"}), this_player()
		);
		owner->receive_healing( 5+random(5) );
	remove();
}
