// Deathland/holyplace/f01.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("fire bridge","火橋");
    set_long(@Long
Long
,@CLong
地底的岩漿所冒出的熱氣正向你侵襲而來,這地方已經相當接近地底了.在你的西邊
有一座橋,橫跨在這熊熊烈火燃燒的懸崖之上,橋下是熔岩的所在,你無法想像掉下橋下
會有甚麼後果.東邊則是一片經年累月永不消失的黑霧.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    "bridge":"@@to_look_bridge",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h13",
             ]));
reset();
}

void init()
{
     add_action("to_pass","pass");
}
string to_look_fog()
{
     return can_read_chinese() ?
            "是霧嗎?你懷疑著,你能很清楚地看到一些懸浮粒子飄散在你的周圍.\n"
            "\或許是一種邪惡的物質,你能感覺到有著邪惡的成份參雜其中.\n" :
            "need work.\n"; 
}

string to_look_bridge()
{
    return can_read_chinese() ?
          "一座不很牢固的吊橋,而且你能清楚地感覺到橋上的高溫是一般人無法\n"
          "忍受的.當然,如果你能忍受如此的高溫的話,你可以試著快速地通過這\n"
          "座火橋(pass bridge)看看.\n":
          "need work.\n";
}

int to_pass(string str)
{
    
    int i;
    object player,*item;
    
    if (!str||str!="bridge") return 0;
    
    player=this_player();
    item=all_inventory(player);
    for(i=0;i<sizeof(item);i++) 
      if ( (string)item[i]->query("name")== "Cold oil" && item[i]->query("applied") ) {
        write("你以極快的速度通過了火橋\n");
        player->move_player(Deathland"/holyplace/f02",({
        "%s passes bridge very fast.\n","%s 以極快的速度通過火橋.\n",
        "%s comes here from bridge\n","%s 從火橋上跑了下來.\n"})
        );
        return 1;
        }
    player->receive_special_damage("fire",100);
    write("你的身體被火灼傷了.\n同時你無法忍受橋的高溫而退了回來.\n");
    return 1;
}
