#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宮大道");
	set_long( @LONG
你正走在皇宮大道上，不時有衛兵在這裡輪流交替看守捍衛皇宮的安全。大道
是用玉做成的，玉上的花紋端的是五花八門琳琅滿目，令人暇不給目。兩旁還種植
著一排排的花草樹木，那花，清香撲鼻，馥郁芬芳，令人心礦神怡。在前面不遠處
就是皇宮了。
LONG
	);
        set("light",1);
        set("pre_exit_func",([
           "north":"can_pass"]));
	set( "exits", ([ 
           "north" : SCITY"palace2",
           "south" : SCITY"center"
        ]) );
	set( "objects", ([
	   "bodyguard#1" : SWMOB"wiz_bodyguard1",
           "bodyguard#2" : SWMOB"wiz_bodyguard1",
	   "bodyguard#3" : SWMOB"wiz_bodyguard1",
               "captain" : SWMOB"wiz_captain1",
	]) );
	reset();
}
int can_pass()
{
    object guard;
    if ( !guard=present("bodyguard",this_object()) ) return 0;
    if ( !present("archmaster's mark",this_player()) ) {
       write(sprintf(
          "\n%s說道：奉城主之命，閒雜人等一律不準隨便出入(entrance_palace)\n	      ，爾等快快步行出去。\n\n",
           guard->query("c_name")));
       return 1;       
    }
    write(@LONG

你大搖大擺地手持令牌進入皇宮，並對守衛的人偷偷放了一個又臭又長的屁．．

    
LONG    
   );
   return 0; 
}