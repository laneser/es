#include <almuhara.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "銅人陣中" );
        set_long(
@C_LONG
你進入了一個寬廣的石室，迎面而來的是三個金光閃閃的銅人，揮
舞著手上的武器向你襲來。你心想這次可真要佛祖保佑了.....
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng4"
        ]) );
        set( "pre_exit_func", ([
		"north" : "pre_north" ]) );
	set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        set( "objects", ([
        	"monk1" : AOBJ"/brassman2",
        	"monk2" : AOBJ"/brassman2",
        	"monk3" : AOBJ"/brassman2" ]) );
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

int pre_north()
{
	if ( present("brassman",this_object()) ) {
		write("銅人擋著你的去路。\n");
		return 1; }
	else return 0;
}

int post_north()
{
	reset();
}

int do_auction()
{
	return 1;
}