#include "../island.h"
#include <money.h>

inherit SHOP;

void create()
{
    ::create();
    set_short("德記古玩行");
    set_long(@LONG
這是謫仙島中唯一的古玩行，牆上掛的橫匾寫著「大小通吃」四個大
字，室內裝潢非金即銀，十足的不可一世，彷佛天底下有價值的古玩均已
盡入其內似的。這兒的老闆有個嗜好，喜歡收集一些零零總總的器具，瞧
上眼的便收起來自己珍藏；為了能有更多的機會見識到各種器具，便開了
這家古玩行以招攬顧客。在櫃檯上方還有一副對聯(words)。
LONG
            );
    set("light",1);
    set("item_desc",(["words":@LONG
    
                 【 你 得 認 命 】
             【                     【 
             你                     是
             不                     你
             來                     的
             他                     是
             不                     他
             來                     的
             自                     都
             有                     是
             人                     我
             來                     的 
             】                     】
LONG
          ])); 
    set("exits",(["north":ITOWN"town08"]) );
    storeroom()->set("objects",([
               "torch":"/obj/torch",
               "bag":"/obj/bag",
               "bandage":"/obj/bandage"
                ]) );
    set("objects",([
        "trashcan":"/obj/trashcan",
        "keeper":IMON"shopkeeper"
                ]) );
    reset();
    replace_program(SHOP);
}
