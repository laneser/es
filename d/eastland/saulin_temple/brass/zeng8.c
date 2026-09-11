#include "almuhara.h"

inherit ROOM;

void create()
{
        ::create();
        set_short( "銅人陣中" );
        set_long(
@C_LONG
你進入了一個較小的石室，環顧四周空無一物，只有在牆上掛了張
卷軸(scroll)。看來這兒是用來讓闖關的人稍做休息之用，在經歷了剛
才的大戰後，你不禁感激當初做此設計的人。
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng9"
        ]) );
        add( "item_desc", ([
        	"scroll" :
"嗯，看來你在少林武學上的造詣相當高深喔。
下一關是最後一關了，少林寺僧人除了武藝超群之外，在佛學上亦應有相當之
造詣，能不動武來化解干戈是最好的，還是多念念佛吧。\n"
	]) );  
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
}

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"突然兩個紅衣羅漢自牆中暗門走出，將你抬了出去。\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("你看到兩個紅衣羅漢將%s像抬豬公一樣抬了出來。\n",
				obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"突然兩個紅衣羅漢自牆中暗門走出，將你抬了出去。\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("你看到兩個紅衣羅漢將%s像抬豬公一樣抬了出來。\n",
			obj->query("c_name") ) );
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_auction()
{
	return 1;
}