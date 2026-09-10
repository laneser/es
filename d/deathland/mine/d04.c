
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","矮人礦坑的大洞穴");
  set_long(@Long
Long
,@CLong
一個很黑很暗的大洞穴,曾經是個含量豐富的礦坑.在這裡的地上充滿了黑色的
泡沫,似乎一些極可怕的生物棲息在這裡
CLong
);
set("exits",([
             "west":Mine"/d05",
             "east":Mine"/d03",
             ]));
set("objects",([
    "shadow#1":Monster"/evilshadow",
    "shadow#2":Monster"/evilshadow",
    "shadow#3":Monster"/evilshadow",
    "evilfighter":Monster"/evilfighter",
    ]) );
set("pre_exit_func",([
    "west":"to_west"
    ]) );
reset();
}

int to_west()
{
     if (!present("evilfighter")) {
       return 0;
       }
     else {
       write("邪惡的幻影戰士擋住你的去路而不讓你過去.\n");
       return 1;
       }  
}

