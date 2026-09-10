// File: /d/noden/asterism/tower3-1.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地精高塔的底層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中地精高塔的底層。矮人和半身人為這片土地本來的
主人建築了這麼一座外觀宏偉的住所。這兒四周的牆璧,被各式各色的寶石鑲點
得五彩繽紛。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"out" : ASTR"city_library",
		"up"  : ASTR"tower3-2",
		"down": ASTR"tower3-0",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard#1":MOB"gnome_guard",
	    "guard#2":MOB"gnome_guard",
	    ]) );
	reset();
}

int to_up()
{
  if (present("guard")&&(string)this_player()->query("race")=="daemon") 
    {
      write(
           "守衛把你擋了下來.\n"
            "守衛說:喂!魔族的。你當這裡是公園,想逛哪就去哪嗎?\n"
           "\n");
      tell_room( this_object(),
                 "守衛把"+this_player()->query("c_name")+"擋了下來.\n"
                 "守衛說:喂!魔族的。你當這裡是公園,想逛哪就去哪嗎?\n"
                  , this_player());
     return 1;
     }
   return 0;   
}
