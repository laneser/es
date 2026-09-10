#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The 2rd floor of Mega Tower","摩天塔的二樓走廊");
  set_long(@Long
Long
,@CLong
你到達了摩天塔的第二層, 這裡到處可見破碎的瓦片與石塊. 曲曲折折的迴廊
是這層的特色, 每個轉角你都必須小心陷阱, 莫名的怪物也將躲在角落處等著偷襲
你.  
CLong
);
  set("exits",([
               "south" :Megatower"/floor2/62",
               "west"  :Megatower"/floor2/53",
               "north" :Megatower"/floor2/64",
             ]));

::reset();
}

