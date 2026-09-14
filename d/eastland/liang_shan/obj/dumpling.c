#include <mudlib.h>
#define FRESH_TIME 500

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("dumpling","包子");
	add( "id" , ({ "dumpling" }) );
	set_short("a dumpling." , "包子");
	set_long(".." , 
		"皮薄餡厚，入口即化，這就是孫二孃的手工特製鮮肉包。\n"
	);
   	set("unit","盤");
   	set("weight", 10);
   	set("value",({ 100, "silver" }) );
//	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int move(mixed ob)
{
	if ( ob && living(ob))
		call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

int eat_food(string arg)
{
		if( !arg || arg != "dumpling" ) return 0;
		write( "你狼吞虎嚥的吃下這盤包子..咦? 怎麼有根奇怪的毛?\n" );
		tell_room( environment(this_player()),
		this_player()->query("c_name")+"飛快地吃掉了一盤包子，然後\n"     
	        "一臉狐疑的從嘴角拉出一根毛...\n" , this_player());
		this_player()->receive_healing( 8+random(2) );
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	if ( !owner ) { 
//	what->set ("value", ({ 1, "silver" }));
//	what->set_short("壞了的炒青菜");
//	what->set_long("這盤青菜變成黃色，不能吃了。\n");
//	what->set("is_fresh",0);
	if( living(owner) )
	tell_object(owner,"你聞到你的包子發出一股酸菜的味道，你覺得丟了它比較好!!\n"
	"你丟掉一盤餿了的肉包。\n");
	}
	remove();
}

