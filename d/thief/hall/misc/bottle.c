#include "mudlib.h"
#define         RATE ({ 13,20,32,55,68,70,75,80,87,90,95 })

inherit OBJECT;

void create()
{
     set_name("pepper bottle","胡椒罐");
     set_short("胡椒罐");
     set_long(
      "這是一個裝滿胡椒粉的的小瓶子，有了它吃飯就不會那麼無聊了，不過\n"
      "你也可以拿著它去惡作劇，小心撒(scatter)到自己噴嚏打不完。\n"
      );
     add("id",({ "bottle","pepper" }) );
     set( "unit", "瓶");
     set("weight",5);
     set("value", ({ 100, "silver" }));
}
void init()
{
	add_action("do_scatter","scatter");
}
int do_scatter(string arg)
{
	object target;
	int skill,rate,level;
	if ( !arg || arg == "" )
		return notify_fail("不要對著自己亂撒胡椒粉 !!\n");
	if ( !target = present(arg,environment(this_player())) )
		return notify_fail("這裡沒有叫做 "+arg+" 的生物。\n");
	if (!living(target) )
		return notify_fail("這裡沒有叫做 "+arg+" 的生物。\n");
	if ( target->query("no_attack") )
		return notify_fail("你不可以欺負這種稀有動物，會遭天罰 ...\n");
	if ( target->query("user") ) {
		if ( (int)this_player()->query_level() < 5 || 
			(int)target->query_level() < 5 ) 
			return notify_fail("還沒到 PK 的時候嘛 ... 等你(或他)長大吧 !!\n");
	}		
	if ( !this_player()->query_vision() )
        return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	tell_object(this_player(),
		set_color("你掏出胡椒罐，把整罐胡椒粉往"+target->query("c_name")+"撒過去 ...\n","HIY") );
	tell_object(target,
		set_color(this_player()->query("c_name")+"掏出一個小罐子，對你一陣亂揚 ..\n","HIY"));
	tell_room(environment(this_player()),sprintf("%s掏出一個小瓶子，向%s一陣亂撒 ...",
		this_player()->query("c_name"),target->query("c_name") ),
		({ this_player(),target }) );
	level = (int)this_player()->query_skill("trick")/5 - (int)target->query_level()+5;
	if ( level < 0 ) 
		level = 0;
	else
		if ( level > 10 ) level = 10;
	if ( random(300) < RATE[level] ) {
		skill = ((int)this_player()->query_skill("trick")-20)/10;
		target->kill_ob(this_player());
		if ( skill > 0 ) {
			tell_room(environment(this_player()),"他開始不由自主的打噴嚏 ....\n",target);
			target->block_attack(skill);
			target->set_temp("msg_block_attack",
			"(你覺得鼻子又辣又癢，不由得打了一個噴嚏 !! )\n");
		}
		this_object()->remove();
		return 1;
	}
	tell_room(environment(this_player()),
		"但是突然吹來一陣風，把粉末都吹到他自己身上 ...\n",this_player() );
	tell_object(this_player(),"突然一陣風吹來，不妙 ... 啊 ～～ 哈嚏 ...\n");
	this_player()->block_attack(4);
	this_player()->set_temp("msg_block_attack",
		"(你覺得鼻子又辣又癢，不由得打了一個噴嚏 !! )\n");
	this_object()->remove();
	return 1;	
}
