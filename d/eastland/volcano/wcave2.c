#include "oldcat.h"

inherit ROOM;
inherit DOORS;
int check;
void create()
{
        ::create();
        set_short( "地牢" );
        set_long(
@LONG
這裡是一間又黑又髒的地牢，是矮靈族關他們抓來當祭品的人的地方，用石板
鋪的地上盡是一些已乾掉的血跡，和從前犯人所遺留下來的東西。
LONG
        );
	set( "exits", ([
        "west" : ONEW"wcave1"
	]) );
        set("item_desc", ([
            "tunnel":"一條黑黑的地道，看不到任何亮光。\n",
            ]) );
        create_door( "west","east", ([
                     "keyword" : ({"door","thick door"}),
                     "name" : "thick door",
                     "c_name" : "厚厚的門",
                     "status" : "locked",
                     "lock" : "WGUARD",
                     "desc" : "You see a door.\n",
                     "c_desc" : "一扇厚厚的木門上面有個鑰孔。\n"
                    ]) );
        set("search_desc",([
            "here":"@@to_search_here",
            "plate":"@@to_search_plate",
            ]) );
        reset();
}

void init()
{
  add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="tunnel" || !check) {
    write("你要進去那裡 ? \n");
    return 1;
  }
 write("你走進這條黑黑的地道，把石板移回定位，突然想到囚犯一定是利用這條地道逃走了。\n");
  write("你走了很久，心裡想著挖這個地道的人一定很有耐心....................\n");
  write("終於前面傳來一點亮光，已經到出口了。.........\n");
  this_player()->move_player(ONEW"wcave3","SNEAK");
  check=0;
  return 1;
}

string to_search_here()
{
  string str;

  str="你在這裡仔細的搜索，發現有一塊石板(plate)似乎有點鬆動。\n";
  return str;
}

string to_search_plate()
{
  string str;

  str="你把這塊石板周圍的東西推開，把石板用手推了推，發現竟然石板下面有個地道(tunnel)。\n";
  check=1;
  return str;
}

void reset()
{ 
  ::reset();
  check=0;
}
