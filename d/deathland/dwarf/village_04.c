
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The barrack","軍營");
  set_long(@Long
Long
,@CLong
這裡是軍營的內部,有好幾棟建築物(buildings)在路的兩旁,雖然這些建築
物的外形看起來都一模一樣,但是每一棟建築物都有其特別的功能.
有條小路穿越軍營,連接著矮人的村落.
CLong
);

set("c_item_desc",([
    "buildings":"一些方方正正的建築,每棟建築的門上都有一塊板子標示該建築\n"
                "的功能,其中有三棟建築的功能似乎比較有趣,分別是:\n"
                "新兵教育中心(new_trained_soldier center)\n"
                "巨人攻擊模式研究室(the college of studing trolls' attack mode)\n" 
                "兵器庫(weapons storage room)\n",
    "center":"新兵教育中心(new_trained_soldier center)\一處訓練新兵的地方\n",
    "college":"巨人攻擊模式研究室(the college of studing trolls' attack mode)\n"
              "一處研究巨人的攻擊模式,期望能夠擊潰巨人的研究單位\n",
    "room":"兵器庫(weapons storage room)"    
           "儲存各式各樣武器的地方 \n",    
                ]) ); 
set("exits",([
               "south":Deathland"/dwarf/village_03",
               "north":Deathland"/dwarf/village_05",
             ]));
::reset();
}

void init()
{
add_action("to_enter","enter");
}

int to_enter(string str)
{
   if (!str) return 0;
   if (str=="center") {
    this_player()->move_player(Deathland"/dwarf/center",
        ({ 
        "%s進入了新兵訓練中心.\n",
         "%s從外面走了進來.\n"}),"");
     return 1;
     }
   else if (str=="college") {
     this_player()->move_player(Deathland"/dwarf/college",
      ({
      "%s進入了巨人攻擊模式研究室.\n",
      "%s從外面走了進來.\n"
       }),"");
     return 1;
     }
   else if (str=="room") {
     write("當你試著進入兵器庫的時後,發現它被鎖著.\n");
     return 1;
     
     }
   else if (str=="buildings" ||str=="building") {
     write("你想進入那一棟建築物?\n");
     return 1;
     }
   else return 0;  
}
