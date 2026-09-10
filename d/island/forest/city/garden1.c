#include "../tsunami.h"
#include "/include/move.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("御花園");
    set_long(@LONG
這是樹雷王家最引以為傲的御花園，裡面種滿了各種難得一見的奇花異
草，如「 王家之淚」(tear_flower)，「 勝利女神 」(goddess_flower)
等等，旁邊還種有一些大樹(tree)，看起來和種在神社旁的及長在城外的是
同樣的品種，只是樹齡沒那麼大；不過，這兒的美景真是令人流連忘返呀！
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "south":CITY"inway1"]) );
    set("item_desc",([
        "tear_flower":@ALONG
這是一種現在十分罕見的花卉，在古魔族帝國時代，這種花隨處可見，但
自從那大隕石掉落後，這種花幾乎絕跡了！這種花的花語是「悲傷，離別」
，種在這兒是為了紀念歷次戰爭中陣亡的同胞。
ALONG
       ,"goddess_flower":@BLONG
這是魔族的王族在戰爭時必帶的花朵，相傳它可保佑王族的安全，也可
為戰爭帶來勝利；當年這一支王族遷徙時，為了祈求平安，所以也帶著它；
如今就種在這兒！                     
BLONG
        ,"tree":@CLONG
咦～～！這些樹難道也是王家的守護靈嗎？怎麼看起來好像是同一品種呢？
CLONG
            ]) );
    set("objects",([
        "farmer":TMOB"farmer1",
        "luoky":TMOB"luoky"]) );
    reset();
#include <replace_room.h>
}

