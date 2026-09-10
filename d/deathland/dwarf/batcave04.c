
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("bat cave","蝙蝠洞");
  set_long(@Long
Long
,@CLong
你已經到了這個洞的盡頭.陰暗的氣息以及腐敗的味道讓人覺得很不舒服.這個地方
似乎罕見人跡,因為很少人有足夠的膽量與運氣來到這裡.
CLong
);

set("search_desc",([
    "here":"@@to_search_here"
    ]) );
set("exits",([
     "south":Deathland"/dwarf/batcave03",
     ]) );
set("beast",0);
reset();
}

string to_search_here()
{
   object monster;
   if ( !present("beast") && !query("beast")) {
     monster=new(Monster"/beast01");
     monster->move(this_object());
     set("beast",1);
     this_player()->set_explore("deathland#14");
     return "一隻龐大的巨獸忽然出現在你的面前.\n";
     }
   return "沒什麼事發生.\n";  
}

void reset()
{
   ::reset();
   set("beast",0);
}
