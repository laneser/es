
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("secret room","秘密房間");
  set_long(@Long
Long
,@CLong
一間隱密的房間,是矮人為了在巨人攻進皇宮時讓一些老弱婦孺躲藏用的.另外有一個梯
子通向下面的儲藏室.
CLong
);
set("exits",([
               "up":Deathland"/palace/pa_02",
             ]) );
set("c_item_desc",([
    "ladder":@Cladder
一個通往儲藏室的梯子.
Cladder
    ]) );
set("objects",([
    "guard":Monster"/royal02",    
    ]) );
    
::reset();
}

void init()
{
    add_action("to_climb","climb");
}

int to_climb(string str)
{
   if (!str||str!="ladder") return 0;
   if (!present("guard")) {
     write("你爬下梯子,經過了許久才到儲藏室\n");
     say(this_player()->query("c_name")+"爬下了梯子\n");
     this_player()->move_player(Deathland"/dwarf/pass02","SNEAK","");
     say(this_player()->query("c_name")+"緩緩地走下來\n");
     }
   else {
     write("守衛把你擋住而不讓你下去\n");
     say(this_player()->query("c_name")+"試著爬下梯子但被守衛擋住\n");
     } 
   return 1;
}
