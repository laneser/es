#include "mudlib.h"

inherit CONTAINER;

void create()
{
	object obj1;
	::create();
	set_name("shelf", "書架");
	set_short("書架");
	set("id", ({"shelf"}) );
	set_c_open_long(@C_LONG
這是一個巨大的黑檀木書架，上面放了許許多多的書，有些滿布灰
塵，看來它們擺在這裡已有相當久的時間了。除了書以外，不少粗
心的冒險者常常在進來查詢資料後，把行李遺忘在書架上。
C_LONG
	);
	
	set("prevent_get",1);
	set("max_load",2000);
	obj1 = new( "/d/adventurer/hall/obj/letter1" );
	obj1->move( this_object() );
}
void init()
{
      ::init();
      container::init();
      add_action("do_get","get");
}
int do_get(string str)
{
     string s1,s2;
     if (!str) {
         write(
             "要拿什麼?\n");
             return 1;
             }
         sscanf(str, "%s from %s", s1, s2);
         if ((!s2) || (lower_case(s2) != "shelf")) return 0;
         
         if ( this_player()->query("class") == "adventurer" )
             return 0;
          
         if ( !present("avery",environment(this_object())) ) return 0; 
          
         write("艾佛瑞推了你一把，罵道: 你想幹嘛啊，當我死了嗎?\n");
         return 1;
}                
