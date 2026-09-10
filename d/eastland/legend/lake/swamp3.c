#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
        ::create();
    set_short("沼澤");
        set_long( 
@LONG
啊！毒氣，糟糕，你走進了最危險的沼澤地，四周都是足以致命的瘴氣，而四
下的沼澤怪物更是對你虎視眈眈，隨時都會撲過來，咬斷你的咽喉，撕裂你的身軀
，吸食你的腦漿。啊，你一聲慘叫，原來是一隻吸血螞蝗正狠狠的咬住你的脖子，
你慌慌張張的用刀把螞蝗削掉，但是四周愈來愈多奇奇怪怪的生物靠了過來，你現
在腦中只有一個想法，就是『逃命啊』！
LONG
    );
    set( "exit_suppress", ({
            "north","east","west","south" }) );
    set("exits",([
            "north":LAKE"swamp2",
            "west":LAKE"swamp5",
            "east":LAKE"swamp3",
           "south":LAKE"swamp2"
        ]) );
    set("objects",([
          "leech#1":LMONSTER"leech",
          "leech#2":LMONSTER"leech",
          "leech#3":LMONSTER"leech"         
         ]) );
    reset();    
}

