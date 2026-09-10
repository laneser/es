#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

#define SPOILED_TIME 500

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
        seteuid(getuid());
	set_name("lu wei","龍門滷味");
	add( "id" , ({ "lu","wei" }) );
   set_short("龍門滷味");
   set_long(@LONG
龍門客棧特製什錦滷味，專為您下酒用的小菜。
LONG
	);
   	set("unit","盤");
   	set("weight", 10);
   	set("value",({ 150, "silver" }) );
	call_out("be_spoiled", SPOILED_TIME );
	set("spoiled",0);
}

int eat_food(string arg)
{
        
	if( !arg ||( arg != "liu wei" && arg !="lu" && arg!= "wei") ) return 0;
	if( query("spoiled") )
	 {
		write(@LONG
		
哇!酸掉了～～～來不急了你已經吞下去了！你肚子怪怪的，可能生病了。

LONG
     );	
        SICK->apply_effect(this_player(),5,10,5);    
     	tell_room( environment(this_player()),this_player()->query("c_name")+"吃了一口滷味，臉色怪怪的，可能是滷味壞了...\n", this_player());
		}
	        else {
		write( "果然是名不虛傳的滷味，要是能喝些酒就更好了...:)\n" );
		tell_room( environment(this_player()), 
		this_player()->query("c_name")+"張大了口，三兩下就把滷味吃完了。\n" , this_player());
		this_player()->receive_healing( 20+random(20) );
	}
	remove();
	return 1;
}

void be_spoiled()
{
	object owner;
	owner = environment(this_object());
	set ("value", ({ 1, "silver" }));
	set_short("龍門滷味(發酸)");
	set_long(@LONG
龍門客棧特製什錦滷味，專為您下酒用的小菜。(已經酸了，不知道能不能吃)	
LONG
      );
	set("spoiled",1);
	tell_object( owner,"好像有股酸味，是你的襪子傳出來的嗎?\n" );
}



