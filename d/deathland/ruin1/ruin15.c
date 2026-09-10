
// Deathland/ruin1/ruin15.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟");
     set_long(@Long
Long
,@CLong
一座破舊的遺蹟 ,這裡似乎已經荒廢很久了 .地上到處是殘磚破瓦 ,更讓人覺得
這地方已經許久未曾有人煙了 .一種綠色的蘚苔植物附在兩旁的牆壁上 ,使得這地方
的氣氛更顯得十分的詭異 .這個地方是遺蹟的西北角 ,你來到這個地方的時候 ,你的
視線就被一個雕刻很精緻的一個小石像給吸引住了 ,彷佛那是一個栩栩如生的人伸出
手來想要與你握手寒喧的樣子 .
CLong
);
     set("item_func",([
         "statue":"look_statue",
         ]) );
     set("exits",([
         "southeast":Deathland"/ruin1/ruin24",
         ]) );
     ::reset();
}

int look_statue()
{

    write(can_read_chinese() ?
          "一個栩栩如生的石像 ,這石像實在是不可多得的藝術品 ,它的樣子就像是想\n"
          "要和你握手寒喧 ,讓人有一種友善的感覺 ,你是否感受到它友善的氣息而不\n"
          "禁地放下你的武器來與它握手呢 ?\n" :
          "???"
         );
   return 1;
}

void init()
{
   add_action("to_hand","hand");

}

int to_hand(string str)
{
    if (!str||str!="statue") return 0;
    if ( this_player()->query("weapon1") ) 
       write("你覺得並沒有甚麼不同.\n");
    else { 
       write("當你手握住雕像的手時, 你覺得一種友善的感覺傳入你的心中\n"
             "好像一種特別的聲音迴繞在你的耳邊.\n...Ding Ding Ding....\n"
             "Ding Ding ......\n"
             );
       }
    return 1;        
}
