
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace1","神宮側殿");
       set_long(@C_LONG
這裡是賽亞達神宮的左殿，左殿的東邊有一富麗的拱門
通往神宮主殿，這個大廳中央有一張白玉鑲銅的石壇，上面
擺了不少的兵器，石壇角落並隨時有一股白霧環繞在左右，
雖然年代已久，但兵器看來絲毫不受年代的影響，仍鋒利如
新。
C_LONG );
       set("exits",([
                     "east":"/d/noden/drow/r66"
                    ]));
       set("light",1);
}
