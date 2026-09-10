#include "../echobomber.h"
//	#define BOARD "/u/e/echobomber/board/board"

inherit ROOM;

void create()
{
        ::create();
        set("light",1);
        set_short("死亡大地的碼頭");
        set_long(@Long_Description
這裡是一個簡單而老舊的碼頭.北邊是一面高聳入雲的懸崖(cliff),而南,西,東
三面皆是汪洋大海( ocean ).刺骨的冷風從海上吹來,以及腐爛的藤蔓( plants )所
傳來的噁心味道,讓你覺得離開這裡將是最好的選擇.
現在你已經踏上了死亡大地--------一處充滿著死亡與財富的地方.這裡除了友善的
矮人外,還有令人懼怕的山頂巨人 ,以及從來沒人見過的骸骨人( Skeletons ).目前
黑暗的勢力正控制著這塊土地.除了祭祀邪神的矮人族外.
Long_Description

 );
set_outside( "deathland" );
 set("item_desc",(["cliff":@C_CLIFF
很高的懸崖.有很多的蔓□植物依附在上面,你可以試試是否能爬上去,但
是你不確定這蔓□是否能支撐你的重量.
C_CLIFF

,"plants":@C_PLANTS
當你注視那些腐爛的植物時,你發現有一些文字(writings)隱藏於後.
C_PLANTS

,"writings":@WRITINGS
當我將要遠離這個危險的地方時,我很慶幸我仍活著.後來的冒險者呀,為了
讓你能夠避免我的錯誤,給你一些建議
 ----潛入(dive)水中,勿爬(climb)上山.------
     冒險家  亞默
WRITINGS

,"ocean":@C_OCEAN
一片汪洋大海
C_OCEAN
                               ]));

set("exits",([
    "northeast":Deathland"/main/p1",
      
   ]));

//	BOARD->frog();

}
void init()
{
     add_action("to_climb","climb");
     add_action("to_dive","dive");
     if( !find_object("/d/std/ocean/ship_death") )
     	"/d/std/ocean/ship_death"->frog();
     if( !find_object("/d/std/ocean/ship_ta_tong") )
     	"/d/std/ocean/ship_ta_tong"->frog();
}

int to_dive()
{
   write("你潛入海洋之中.\n");
   this_player()->set_explore( "deathland#0" );
   this_player()->move_player(Deathland"/main/d4.c",
         ({"%s潛入海中而消失。\n","%s從碼頭潛了下來。\n"}),"SNEAK");
   return 1;
}

int to_climb()
{
  if ((int)this_player()->query_skill("climb")>100) {
   write("憑著高超的攀登經驗,你爬上了懸崖\n");
   this_player()->move_player(Deathland"/upper/a1","SNEAK","");
   }
   else {
   write("想想自己的技術,要爬上去簡直是妄想.\n"
      "你只好另外尋找出路.\n");
   }
   return 1;
}
