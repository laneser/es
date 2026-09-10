#include <mudlib.h>

inherit ROOM;

#include <ansi.h>
void create()
{
        ::create();
     set_short( "睡房" );
       set_long(
 "    這是聖人的睡房，比外面乾淨多了，屋子中間放著的不用說了是床，\n"
 "沒有什麼特別的,床頭掛著一張照片(picture)。在床的旁邊放著一張化\n"
 "妝桌，上面擺設齊全，看來聖人很喜歡他的妻子\n"
        );
     set( "light",1 );
     set("item_desc",([
              "picture" : "這是聖人和他未過門的妻子的合照，從他臉上可\n"
                          "看出，他是非常幸福的，在照片右下角，有幾行\n"
                          "小字："RED"女神(qwe)：雖然你離我而去，但我總是忘\n"
                          "不了你，我願意等你一生一世。"NOR"\n"
         ]));
     set( "objects", ([
          "knight" : "/u/s/sage/test/deathknight.c",
         ]) );
     set( "exits", ([
           "west"  : "/u/s/sage/workroom",
           "south" : "/u/s/sage/guild/gc.c",
        ]) );
}
