#include "../island.h"

inherit ROOM;

void create()
{
     object knight;
     ::create();
     
     set_short("史蹟陳列室");
     set_long(@C_LONG
這兒就是和平紀念堂的二樓，這兒供奉著促成和平者『聖騎士』的金
身，還有專人在維護金身的安全與完整。只見堂中瀰漫著一股莊嚴肅穆的
氣氛，進入此處，最好保持嚴肅的心情，不然你可能會很快就會遭到報應
哦！
C_LONG
             );
     set("light",1);
     set("exits",([
                 "down" : ITOWN"museum"
            ]) );
     set("objects",([
           "monk": IMON"e-shi",
           "trashcan" : "/obj/trashcan"
          ]) );
     set("no_embattle",1);
     set("no_demand",1);
     knight=new(IMON"holy_knight");
     knight->move(this_object());     
     reset();
 }

int clean_up() { return 0; } 