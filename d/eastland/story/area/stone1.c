#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("礁石");
	set_long( @LONG
你站在一塊不很大的礁石上，四周是一望無際的大海，海面波平浪靜，只濺起
些許水花。離這裡不遠處有片白沙灘，你可以試著游過去 ( swim ) 。
LONG
	);
        set("light",1);
        set("objects", ([
          "swordman1" : SMOB"swordman1"
        ]) ); 
	reset();
}
void init()
{
   add_action("do_swim","swim");
}
int do_swim( string arg )
{
   tell_object(this_player(),"你往不遠處的白沙灘游去．．\n");
   this_player()->move_player(SAREA"coast1","SNEAK");
   return 1;
}