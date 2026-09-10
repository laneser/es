#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "s2w1", "『薪膽村』廣場" );
	set_long(@C_LONG
這是一大片黃砂廣場,旁邊有一顆大樹。這裡因為『丐幫』弟子常在此處練武
功,所以地面顯得光禿禿的一根雜草也沒有。有時候風颳的很大挾帶著漫天的灰塵
,尤其是每當南邊的高山吹著『落山風』, 真叫人眼睛睜不開。於是『丐幫』擬定
做一些水土保持的工作, 但是村裡缺乏另一大片空地可以供弟子們練習,所以每次
提出做值地皮的工作就會遭人反對,於是乎人們還是得繼續忍受下去。東、西和北
邊是廣場的繼續延申, 南邊則是山坡。
C_LONG
	);
	set_outside( "noden" );
	set( "exits", ([
                      "east":DBEGGAR"south4.c",
                      "west":DBEGGAR"s4w2.c",
	              "north":DBEGGAR"s1w1.c"
	]) );
        set("c_item_desc",([
                 "tree":"一顆大樹。\n"
        ]) );
     reset();
}
void init()
{
   add_action("to_climb","climb");
}
int to_climb(string str)
{
   if (!str) return 0;
   if (str=="tree") {
       this_player()->move_player(DBEGGAR"tree1",({
            "",
            "%s從外面爬了進來。\n"}),"");
       return 1;
   }
   else {
   write("你想爬上那裡呢?\n");
   return 1;
   }
}
