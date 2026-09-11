
#include "zeus.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("清境");
  set_long(@CLong
一陣濃郁的藥草味撲鼻而來，可見此地是礦工們療養治病的地方，一張張
\擺設整齊且乾淨的床鋪，的確是一個休息的好地方，與外面烏漆吵雜的環境迥
然不同．
CLong
);
   

set("exits",([
             "east":ZROOM"/center1",
             ]));
set("objects",([
             "invalid":ZMOB"/invalid.c"
             ]));
             reset();
#include <replace_room.h>
             }