#include "mumar.h"
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("李芃的收藏室");
  set_long( @CLong
走進這個房間，你幾乎懷疑自己是不是身處於一個軍事基地之中。這兒華麗的陳
設不說，收藏的更都是各地的珍奇物品和古玩。耀眼的珠寶(gems)和瓷器(china) 以
外，這兒還有些有趣的盔甲(plates)與武器。你覺得若是能擁有這房間裡十分之一的
財富，大概下半輩子都不用辛苦賺錢了。
CLong
);
set("light",1);
set("c_item_desc",([
    "gems":"@@to_gems","china":"@@to_china",
    "plates":"@@to_plates","mirror":"@@to_mirror"
     ]) );
 
set("exits",([
               "west":MUMAR"stage06"
             ]));
}
 
void init()
{
    add_action("to_polish","polish");
    add_action("to_touch","touch");
}
 
int to_polish(string arg)
{
 if( !arg || arg != "plates" ) return 0;
   write("你小心翼翼地地輕輕擦拭著盔甲，卻還是一個不小心差點把一具戰甲弄倒。\n");
   write("當你試圖扶起那戰甲時你才發現盔甲後面的角落裡放著一座大鏡子(mirror)。\n");
 this_player()->set_temp("look_mirror",1);
 return 1;
}
 
int to_touch(string arg)
{
   if( !arg || arg != "mirror" ) return 0;
   else  {
      if (this_player()->query_temp("mirror_ok") || ent==2){
        ent=2;
        write("在你摸著鏡子的同時，你感到一股強大的吸引力把你拉進了鏡內。\n");
        this_player()->move_player(MUMAR"m_stage",({
        "",this_player()->query("c_short")+"被吸入了鏡子\n。",
        "",this_player()->query("c_short")+"進入了這個鏡中世界。\n",
        }),"");
        }
      else {
        ent=1;
        write("你輕輕地摸著鏡子，結果摸了一手的灰...\n");
            }
        }
   return 1;
}
 
string to_gems()
{ return "一些紅寶石、貓眼石、翡翠、珊瑚之類的，讓你眼花撩亂。\n"; }
 
string to_china()
{ return "這些瓷器都是官窯正品，色澤和造型都是上上之選。\n"; }
 
string to_plates()
{ return "這兒有著東方島國的武士戰甲、諾頓大陸的騎士裝備、默爾斯人的戰袍、\n"
         "前代將軍染著敵人鮮血的盔甲。這些來自不同時空的盔甲只有一個共同的\n"
         "特色，那就是都被擦拭(polish)得一塵不染，閃著亮麗的金屬色澤。\n"; }
 
string to_mirror()
{
  if (this_player()->query_temp("mirror_ok"))
   {return "這面鏡子閃耀著一種奇異的光芒，深深地吸引著你去摸(touch)它。\n";
   ent=2;}
  else{
   return "這面鏡子似乎是這房間中最不起眼的玩意兒了。而且這鏡子還缺了一角。\n";
      }
}
 
void reset()
{
  ::reset();
  ent=1;
}
