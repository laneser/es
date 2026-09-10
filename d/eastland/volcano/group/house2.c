#include "../oldcat.h"

inherit ROOM;
string str1="這裡是全族中最漂亮的女孩子所住的帳篷，走進來可以聞到一股淡淡的香氣，帳\n篷內的佈置恬靜素雅，更加襯托出這裡主人的氣質。\n";
string str2="你看到一位女孩子，用沉魚落雁都不足以形容她的美麗，全村的未婚青年都以她為追\n求的對像，只不過她冷若冰霜，對所有的求婚者皆愛理不理。\n";
void create()
{
	::create();
    set_short("帳棚");
	set("long","@@query_long" );
    set( "exits", ([
     "out" : OGROUP"warea6"
    ]) );
    set( "objects", ([
     "wmaid" : OMONSTER"wmaid"
    ]) );
    set("light",1);
    reset();
}

string query_long()
{
  if (present("the young lady"))
    return str1+str2;
  return str1;
}
