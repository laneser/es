#include "../oldcat.h"

inherit ROOM;

int be_get1;
void create()
{
	::create();
        set_short("後院");
	set_long( 
@LONG_DESCRIPTION
這裡是神殿後院，一小塊地上種著各種不同的蔬菜(vegestable)，中間一條小
徑可通往後殿，你還看到有一口井(well)。
LONG_DESCRIPTION
	);

set( "exits", ([
     "west": OTEMP"temple13",
     "southeast":OTEMP"temple25"
     ]) );

set("item_desc",([
    "vegestable":"這一片蔬菜園是神殿裡的人種的，使他們可以自給自足。\n",
    "well":@Well
一個已經乾枯的水井，你看到井底連一滴水都沒有，很明顯的，這口井已經廢棄
很久了。
Well
   ]) );
set("search_desc",([
    "vegestable":"@@to_search_vegestable",
    ]) );
set_outside("eastland");
reset();
}

string to_search_vegestable()
{
  string str;
  object ob;

  if(be_get1==2)
    return "你沒有找到任何有用的東西。\n";

  str="\n你在菜園子裡，找到一個澆菜用的大桶子。\n";
  ob=new(OOBJ"bucket");
  ob->move(this_player());
  be_get1++;
  return str;
}

void reset()
{
  ::reset();
  be_get1=0;
}
