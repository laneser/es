
#include "../takeda.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(2);
        set_name( "guest","食客" );
        set_short( "食客");
        set("unit","位");
        set("alignment",100);
        set("weight",400);
        set("wealth/gold",2);
        set_long(
           "這是一個慕孫二孃之名而來的食客，他正津津有味的享用著食物...\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s", "%s用她的舌頭向%s舔去" }));
        set("chat_chance", 7);
        set("chat_output",({
          "食客說：聽說大演武場上有一個奇怪的黑市商人....\n",
          "食客說：吃遍東方大陸，還是這家的東西最好吃。\n",
          "食客說：聽說肥東的廚房髒的要命，難道沒有人在打掃(sweep)廚房嗎？\n",
          "食客大叫：老闆，來兩斤牛肉，再多切點小菜。\n",
          "食客滿足的拍拍肚子，一副意猶未盡的樣子....\n"
        }));
}
