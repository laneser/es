// Echo/item/letter01.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("paper","破舊的紙張");
set_short("a paper","破舊的紙張");
set("c_long",@ScryBall
一張已經發黃的紙張,上面寫著密密麻麻的文字.\或許你可以試著去讀(read)它.
ScryBall
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
    if (!str ||str!="paper") return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write("當我在矮人迷宮中研究了四十幾天之後, 我終於發現了通往矮人村的\n"
                "正確方法,但是同樣地矮人牧師底斯宜爾也發現了我,他使用該死的靜\n"
                "止術然後把我捉來這裡 ,我的巨人族同伴們試著把我救出但是卻一一\n"
                "失敗了.最後該死的矮人把這裡的出口封住,把我困死在這裡 .在我生\n"
                "命的盡頭,我把這個令矮人活著如此久的該死迷宮秘密計錄下來.希望\n"
                "我的巨人夥伴能得知,讓矮人族的生活永遠處在恐懼之中,不得安寧.\n"
                "這秘密是:進入迷宮之後,走,東,南,南,北,西,北,西,矮人的財富與生\n"
                "命就在你的掌握之中了........哈!哈!哈.\n"
                "\n\n                        _______巨人魔法師林頓(Lindn)...\n"        
              );
          return 1;      
        }
    }
}
