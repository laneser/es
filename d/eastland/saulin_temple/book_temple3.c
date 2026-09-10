//File: book_temple3.c 藏經樓內密閣 

#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "藏經樓密閣" );
       set_long( @C_LONG_DESC
沿著木梯，你爬上一座小閣樓，這座四面書架的小閣也擺滿了書，不過架上
的小條你都可以看懂，除了少部份珍貴的佛經外，大多數是武林中人夢寐以求的
武功密笈，你看著這些無價寶典(books)，心中小鹿亂撞，不過已經有人先到了，
他正滿臉疑惑的看著你。
C_LONG_DESC
       );
       set("light",1);
       set("objects",([ "fire_monk":SAULIN_MONSTER"fire_monk" ]));
       set("exits",([
         "down" : SAULIN"book_temple2"
       ]));
       reset();
#include <replace_room.h>
}
void init()
{
        if (this_player()) this_player()->set_explore("eastland#31");
}
