
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace3","神宮側殿");
       set_long(@C_LONG
一個由□木所雕刻的巨大書架佔據了整個房間，這裡就
是賽亞達神宮的右殿，據說賽亞達在世時，就以此地為其收
藏世界珍品與書籍的地方，後世黑暗精靈們懷念這位偉大的
騎士，便在他的故居，蓋了大神宮，也將賽亞達生前的珍藏
放在此處，永久保存。
C_LONG );
       set("exits",([
                     "north":"/d/noden/drow/r68",
                     "west":"/d/noden/drow/r66"
                    ]));
       set("light",1);
}
