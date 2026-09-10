// Echo/item/letter01.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("scroll","羊皮卷軸");
set_short("a scroll","羊皮卷軸");
set("c_long",@LONG_D
一張沾滿著泥土的卷軸,上面寫著密密麻麻的文字.\或許你可以試著去讀(read)它.
LONG_D
);
set("no_sale",1);
set( "unit", "張");
set("weight", 5);
set("value", ({ 5, "silver" }));
}
void init()
{
add_action("read_letter","read");
}

int read_letter(string str)
{
    object ob1,room_1;
    if (!id(str)) return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write(
          "當我向宏都拉斯借得運礦車後, 終於撞破了那堆亂石, 來到了那個\n"
          "被封印以久的邪惡神官的墓穴. 然而一道門卻擋住了我的路, 我必\n"
          "須去尋找這門的鑰匙..........\n"
          "不知這是幸運呢還是不幸, 我實在沒有什麼把握在邪惡神官奧根的\n"
          "墓穴中會有什麼奇怪的詛咒.\n"
          "                ------矮人探險家英蒙得\n"
          );
          return 1;      
        }
    }
}
