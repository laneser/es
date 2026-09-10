#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("牧馬關教場");
  set_long( @CLong
你走到牧馬關內的營地，這片空地上整齊地排列著難以數計的帳篷，而這兒就是
士兵們的家。在這瀰漫著肅殺氣息和震天殺聲的廣場上，你實在很難想像這些士兵怎
麼能睡得著。廣場的北面靠牆的地方有個平臺(platform)，東邊是一間伙房，正傳來
陣陣菜香。
CLong
);
set_outside("eastland");
 
set("c_item_desc",([
    "platform":"@@to_platform","door":"@@to_door"
     ]) );
 
set("search_desc",([
    "platform":"@@to_search_platform", "door":"@@to_search_door"
     ]) );
 
set("exits",([
               "south":MUMAR"square03",
               "east":MUMAR"kitchen",
               "west":MUMAR"square05",
             ]));
set("objects",([
               "soldier":MOB"old_soldier" ]) );
reset();
}
 
void init()
{
    add_action("to_enter","enter");
}
 
int to_enter()
{
   if (ent==1) {
     write("門是關著的，沒有把手又沒有鑰匙孔，你實在想不到怎麼打開..\n");
     }
   else
     {
     write("你進入了門內..才突然發現你什麼也踩不到。\n");
     write("你整個人摔了下去，失聲喊出...「哇!!.....」\n.\n.\n.\n.\n.\n.\n.\n");
     this_player()->move_player(MUMAR"secret01",({
      "",this_player()->query("c_short")+"進入了密門\n。",
      "",this_player()->query("c_short")+"從上面摔了下來，姿勢亂難看的不說，叫得也比大聲的。\n",
      }),"");
     }
   return 1;
}
 
string to_search_platform()
{
      return "當你仔細檢查這座司令臺時，發現在臺下有道密門(door)...\n";
}
 
string to_search_door()
{
    if (ent==1) {
      ent=2;
      return "當你仔細檢查這道門時，觸動了門下的機關，密門突然隆隆地開了...\n";
      }
    else
      {
      ent=1;
      return "當你仔細檢查這道門時，觸動了門下的機關，密門突然隆隆地關上了...\n" ;
      }
}
 
string to_platform()
{
    return "一座司令臺，站在上面可以看到整個牧馬關內的活動情形。\n";
}
 
string to_door()
{
  if (ent==1)
    return "一道一次只能讓一個人通過的小密門(door)。\n";
  else
    return  "一道一次只能讓一個人通過的小密門(door)，它現在開著。\n";
}
 
void reset()
{
  ::reset();
  ent=1;
}
