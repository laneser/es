
// Deathland/ruin1/ruin13.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟");
     set_long(@Long
Long
,@CLong
一座破舊的遺蹟 ,這裡似乎已經荒廢很久了 .地上到處是殘磚破瓦 ,更讓人覺得
這地方已經許久未曾有人煙了 .一種綠色的蘚苔植物附在兩旁的牆壁上 ,使得這地方
的氣氛更顯得十分的詭異 .
    這裡是遺蹟的一處死胡同 ,然而這個地方卻有兩尊巨大的雕像 ,你或許可以從這
兩尊雕像瞭解到這座遺蹟的歷史 .    
CLong
);
     set("item_func",([
         "statue":"look_statue",
         "description":"look_description",
         ]) );
     set("exits",([
         "east":Deathland"/ruin1/ruin23",
         ]) );
     ::reset();
}

int look_statue()
{
    write(can_read_chinese()?
          "這兩尊石像似乎經過了數百年歲月無情的侵蝕 ,你已經無法清楚地看清原\n"
          "來的模樣了 .但是在雕像的底部有著一段文字的描述(description),似乎\n"
          "還清晰可見的樣子 .\n":
          "Need to work\n"
          );
    return 1;
}

int look_description()
{
    write(can_read_chinese()?
          "這段文字似乎有點語意不清 ,但是你依然能夠把它讀出來 :\n"
          "    這兩座石像是為了紀念偉大的探險家萊特與肯尼兩兄弟 ,他們成功地\n"
          "發現了繆思泉水的正確位置 .同時也發現了我們生活的城市是位與地底之\n"
          "下 ,並且建立了我們與地上高塔懷爾巫師的邦交與友誼 .\n"
          "                 ------昂德沃城國民會議\n":
          "Need to work\n"
          );
    this_player()->set_explore("deathland#20");
    return 1;
}
