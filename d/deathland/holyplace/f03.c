// Deathland/holyplace/f03.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("mystic cave","神秘的洞穴");
    set_long(@Long
Long
,@CLong
一處陰暗的地方, 整個洞穴沒有什麼特別的, 除了一個小小的木門 .
CLong
);

set("item_func",([
    "door":"to_look_door",
    "description":"to_look_description",
    ]) );
set("exits",([
             "out":Deathland"/holyplace/f02",
             ]));
reset();
}

void init()
{
     add_action("to_smash","smash");
}
int to_look_door()
{
     write( can_read_chinese() ?
            "一個小小的木門. 門上似乎有一段文字(description)寫在上面. \n"
            "除此之外, 你發現門上沒有把手, 似乎沒有任何方法能打開這門,\n"
            "除非你用撞(smash)的.\n":
            "need work.\n");
     return 1;        
}

int to_look_description()
{
    write( can_read_chinese() ?
          "通往死亡的入口.\n"
          :
          "A entrance toward Death.\n"
          );
    return 1;      
}

int to_smash(string str)
{
    if (!str ||str!="door") return 0;
    write("當你撞上那門的時候, 忽然整個門消失了, 而你也跌進了另一個地方.\n");
    this_player()->move_player(Deathland"/holyplace/f04",({
    "%s disappear.\n","你只見%s穿過木門消失了.\n",
    "%s enters.\n","%s跌了進來.\n",}) );
    return 1;
}
