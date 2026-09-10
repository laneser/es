#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("徵木神社");
    set_long(@LONG
這裡長著棵非常茂密的大樹(tree)，旁邊還有座神社，上頭寫著『徵木神社』
四個字，神社周圍打掃的十分乾淨，你覺得有一股莊嚴肅穆的氣氛攏罩在你的身旁，
難道這兒就是祭祀樹雷王家守護靈們的地方嗎？
LONG
       );
    set("light",1);
    set_outside("island");
    set("exits",([
        "south":CITY"inway2"]) );
    set("item_desc",([
        "tree":@ALONG
哇～～～！這棵大樹的樹齡似乎也有數百年了，只是看起來似乎比城外那棵更
具有歷史，啊～～～！你突然有所領悟：難不成這也是一位守護靈的化身嗎？如果
是，那麼它是哪一位呢？嗯～～！在神社(abbey)中應該能獲得解答。
ALONG
     ,"abbey":@BLONG
這是座遵照魔族傳統建築風格而建的神社，雖然稱不上富麗堂皇，但其散發出
那神聖不可侵的氣息，卻使人不敢有任何不敬的舉動；嗯！你心想：應該可以進去
(enter)參拜一番吧！
BLONG
          ]) );
    reset();
}

void init()
{ 
   add_action("do_enter","enter");
   add_action("do_pray","pray");
}


int do_enter(string str)
{
    if( !str || str != "abbey")
    return notify_fail("你要進哪裡？\n");
    write("\n\n..........你雙手合十，懷著虔敬的心情步入神社..........\n\n\n");
    tell_room( environment(this_player()),
        this_player()->query("c_name")+"懷著虔敬的心情緩緩的步入神社！\n"
        ,this_player() );
    this_player()->move_player(CITY"abbey1","SNEAK");
    tell_room( environment(this_player()),
        this_player()->query("c_name")+"懷著虔敬的心情緩緩的走了進來！\n"
        ,this_player() );
    return 1;
}       
         
int do_pray()
{
    write(@ALONG
突然由樹葉射出一道道的光線，在你的面前逐漸形成一片光幕，不一會兒，守護靈
津名魅緩緩的從光幕中飄了出來：
　　親愛的勇者，我們目前遇到了一個大浩劫，也是守護靈之一的龍皇快要耗盡所有的
靈力了；為了魔族的延續與傳承，請你帶回他的種子(seed)，並請園丁將它種在花園中
，好讓他的靈力得以藉轉生而傳承下去！我所能說的就只有這麼多了，勇者，一切都麻
煩你了.........
　　守護靈的美麗容貌使你陷入陶醉之中，之後的情況你完全不記得了.......--|:
ALONG
           );
    tell_room( environment(this_player()),
      this_player()->query("c_name")+
      "呆呆站在樹前，突然間口水直流，真是該死的傢伙，居然如此褻瀆神明...\n"
      ,this_player() );
    return 1;
}         
