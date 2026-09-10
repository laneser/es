#include <mudlib.h>

#define LIMIT_TIME 20
inherit OBJECT;

void init()
{
add_action("eat_it","eat");
}
void create()
{
	set_name("dofu","麻辣豆腐");
	add( "id" , ({ "dofu" }) );
	set_short("dofu" , "麻辣豆腐");
	set_long(".." , "孫二孃拿手的加料麻辣豆腐，紅色的湯水漂浮著白色的豆腐，\n"
	"非常的美麗！你覺得最好趁熱吃....\n");
   	set("unit","碗");
   	set("weight", 15);
   	set("value",({ 100, "silver" }) );
}


int eat_it(string arg)
{
	object owner;
	if ( !arg || arg!="dofu")
	return notify_fail("吃什麼??\n");
	owner = environment(this_object());
		tell_object(owner, 
			"你淅哩嘩啦的吞下一碗麻辣豆腐，感覺一股熱氣在體內蔓延。\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"吞下一大碗麻辣豆腐，臉一下子變的"
			"紅通通的!!\n", owner
		);
		owner->receive_healing( 7+random(3) );
	remove();
        return 1;
}
