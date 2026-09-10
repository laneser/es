#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("林間小徑");
       set_long( @Clong
在一道巨大的鐵柵之後，是一條陰森森的林間小路，濃密的枝葉，把天光
完全的遮蔽起來，即使是晴天的正午，這裡也是伸手不見五指。小徑的底部，
積滿了溼漉漉的落葉，彷佛從它們落到地面時，就再也沒有乾過。樹幹的根部
長滿了黑綠色的青苔，一些蝸牛在上面爬行，留下了閃亮的分泌液。據說梁山
泊好漢以前，常常到此打獵取樂，但最近，似乎發生了什麼事，大家都不敢再
來了。
Clong
          );
set("exits",([
               "south":TROOM"gate3",
              ]) );
create_door("south","north",([
             "keyword" : ({"iron prism","prism" }),
             "status" : "closed",
             "c_desc" : "一道厚重的鐵柵",
             "c_name" : "鐵柵",
             "name":"iron prism",
             "desc":"an iron prism"
              ]) );
reset();
}
int clean_up() { return 0; }