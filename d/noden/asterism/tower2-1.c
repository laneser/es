// File: /d/noden/asterism/tower2-1.c 
//                              by Indra in Eastern Story

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的底層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中矮人高塔的底層,一陣肅殺的氣氛籠罩與此地.這裡的防護
十分強大,除了有著守衛看守著之外,這高塔的每一層都用上了厚厚的鎖 ,以防止外人
進入.
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"out" : ASTR"city14",
		"up"  : ASTR"tower2-2",
		"down": ASTR"tower2-0",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard#1":MOB"dwarf_guard01",
	    "guard#2":MOB"dwarf_guard01",
	    ]) );
	reset();
}

int to_up()
{
   if (present("guard")) 
      {
      if((string)this_player()->query("race")=="dwarf")
         { 
           if( ((int)this_player()->query_level())<15 ) return 0 ;
      
           write(
                    "守衛把你擋了下來.\n"
                    "守衛說:你這乳臭未乾的小子想上去幹嘛 ? 回家吸奶嗎 ?\n"
                      );
           tell_room( this_object(),
                    "守衛把"+this_player()->query("c_name")+"擋了下來.\n"
                    " 守衛說:你這乳臭未乾的小子想上去幹嘛 ? 回家吸奶嗎 ?.\n"
                     ,this_player());
           return 1 ;
         }
      write(
      "守衛把你擋了下來.\n"
      "守衛說:往上走的唯一方法是踏著我的屍體上去.\n");
      tell_room( environment(this_object()),
                 "守衛把"+this_player()->query("c_name")+"擋了下來.\n"
                 "守衛說:往上走的唯一方法是踏著我的屍體上去.\n"
                              ,this_player());
     return 1;
    }
   return 0 ;   
}
