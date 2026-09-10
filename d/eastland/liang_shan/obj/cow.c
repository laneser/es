#include <mudlib.h>
#define FRESH_TIME 400

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("beef","蔥爆牛肉");
	add( "id" , ({ "beef" }) );
	set_short("beef" , "蔥爆牛肉");
	set_long(".." , 
		"這也是孫二孃的拿手好菜，用半年大的小牛肉加入特殊佐料爆香\n"
		"入口鮮香滑嫩，令人回味無窮。\n"
	);
   	set("unit","盤");
   	set("weight", 20);
   	set("value",({ 260, "silver" }) );
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
		if( !arg || arg != "beef" ) return 0;
		write( "你愉快地吃掉這盤蔥爆牛肉，而後滿足的拍拍肚子...:)\n" );
                tell_room( environment(this_player()),
                "你看到"+this_player()->query("c_name")+"吃掉一盤蔥爆牛肉"
                "然後相當滿足地拍拍肚子...\n" , this_player()
        );		
		this_player()->receive_healing( 10+random(10) );
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
	tell_object(owner,
		"你的蔥爆牛肉太久不吃，現在已經壞了!!你順手把它丟掉。\n"
		);
	}
	remove();
}

