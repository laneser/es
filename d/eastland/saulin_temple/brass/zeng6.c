#include "almuhara.h"

inherit ROOM;

void create()
{
        ::create();
        set_short( "銅人陣中" );
        set_long(
@C_LONG
你進入了一個較小的石室，環顧四周空無一物，只有在牆上掛了張
卷軸(scroll)，以及旁邊有個茶壺(teapot)。看來這兒是用來讓闖關的
人稍做休息之用，在經歷了剛才的大戰後，你不禁感激當初做此設計的
人。
C_LONG
        );


        set( "light",1 );
        set( "exits", ([
                "north" : BRASS"/zeng7"
        ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        add( "item_desc", ([
        	"scroll" :
"哇 !! 你已經通過前三關了，相當厲害 !! 
下一關是在考驗你的七十二絕技的功力，請先準備好再往前走。\n",
		"teapot" :
"一個小小的茶壺，也許你可以喝喝水(drink water)，休息一下。\n"
	]) );  
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
	add_action("do_drink","drink");
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
		obj->delete_temp("drink_already");
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
		obj->delete_temp("drink_already");
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_drink(string str)
{
	object obj;
	obj = this_player();
	
	if(!str || str == "") return 0;
	if( str == "water" ) {
		if( !obj->query_temp("drink_already") ) {
			tell_object(obj,
				"喝了一口水，你覺得全身一陣清涼。\n" );
			obj->add("medication_resistance",-300);
			obj->set_temp("drink_already",1);
			return 1; }
		tell_object(obj,
			"再喝一口水，你覺得好像沒什麼差別了。\n" );
		return 1; }
	else return 0;
}

int post_north()
{
	this_player()->delete_temp("drink_already");
}

int do_auction()
{
	return 1;
}