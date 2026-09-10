
#include "../goomay.h"
inherit OBJECT;
void create()
{
set_name("paper","發黃的羊皮紙");
set_short("a paper","發黃的羊皮紙");
set_long(@PAPER
一張已經發黃的羊皮紙紙，上面寫著密密麻麻的文字.\或許你可以試著去讀(read)它.
PAPER
);
set("no_sale",1);
set( "unit", "卷");
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
    if (!str ||str!="paper") return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write(
@C_MSG
哈哈哈 !!! 我終究還是逃出來了 ... 沒想到這個地方會在最後關頭助我最後
的一臂之力 ...

    我是精靈族魔法師－林特，在一次意外的魔法試驗中，我和我的同伴 ( 也
就是現在追殺我的人 ) 魔族法師－普羅尼亞發現了合成人造生物的法術，這是
一項極其可怕的法術，我們很僥倖的利用精神控制制服了首次的成果－一隻巨大
的火焰獸，我知道幸運女神不會常常眷顧著我們，運用這種違反自然的法術必將
遭受反噬，但是普羅尼亞已經著迷了，她竟然企圖殺害我以奪取我的法力，因為
單憑一個法師的力量是絕對無法發揮那可怕咒語的威力的，我逃出來了，逃到一
個被神聖封印鎖住的地方，可是我的生命也耗竭了。

    我並不在乎生或死，我只知道瘋狂的普羅尼亞一定會想盡辦法去取得強大的
法力來繼續她的瘋狂試驗，甚至出賣靈魂也在所不惜，能來到這裡的人啊 !! 你
一定不會是邪惡的一方，求求你一定要找到普羅尼亞，在她還沒有毀滅世界之前
把她送入地獄 !! 願神保佑你 !! 願魔法之神永遠與你同在 !!

				林特．坎恩 絕筆

C_MSG
              );
          return 1;      
        }
    }
}
