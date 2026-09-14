#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "廚房" );
	set_long(
	"這是梁山泊內的大眾廚房，提供免費的食物，鍋子(pot)內正煮著食物，冒\n"
	"著陣陣的白煙，但那股奇怪的味道卻讓人不敢恭維。地上散佈著各種食物的\n"
	"殘渣，看起來這裡的主人十分不注重衛生。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "north"  : TROOM"path4",    
        ]) );
        set( "c_item_desc", ([
                "pot" : @POT
你探頭往鍋中看去，這一鍋黏不拉嘰的東西不知道是什麼，看起來令人作嘔。
再向前仔細一看，你發現一件很奇怪的事，鍋子裡都是些青菜蘿蔔和黃豆，打
碎混合的東西，難道梁山泊的人都吃素?
POT
]));              
        set( "objects",([
             "cooker" : TMONSTER"fat"
             ]));
        reset();
}
void init()
{
   object obj;

   add_action("do_sweep","sweep");
   add_action("do_consider","consider");
   add_action("do_suggest","suggest");
   if ((int)this_player()->query_temp("fat_quest/fish")==2 && present("cooker")) {
   obj = new("/d/noden/asterism/item/tea01");
   write(
   "肥東說道: 辛苦你了，邊說邊倒了杯青草茶給你.......\n");
   this_player()->set_temp("fat_quest/fish",3);
   write(
   "剛才你出去的時候，張順頭領派人送來了一些魚蝦，我就試著做了一些料理\n"
   "你要不要試試看................\n\n"
   "於是你從料理臺上挑出幾樣食物送入口中，嚼嚼嚼嚼.........\n\n"
   "說實話，味道實在不是很好，看來肥東的烹飪技術(skill)有待加強。\n");
   obj->move(this_object());
}
}
int do_sweep()
{
   if ( present("broom",this_player()) )
     {
      write(
      "你一邊哼著小毛驢，一邊把廚房打掃的乾乾淨淨....\n\n");
     
      tell_room(this_object(),
      "你看到"+this_player()->query( "c_name")+"拿著掃把，努力的清理這間廚房。\n",this_player());
   if (present("cooker")) 
     {
      write(
      "肥東感激的說道:謝謝你幫我打掃廚房，可是......\n"
      "唉.................\n\n"
      "一聲嘆息之後肥東繼續說道：其實我也是很愛乾淨的，可是我這麼胖，根本不能\n"
      "彎下腰去打掃，現在雖然你打掃得很乾淨，但我想過不了多久這裡還是會變得跟\n"
      "以前一樣那麼髒，難道你要天天幫我掃嗎？所以我想這不是一個治本的好辦法吧\n"
      "。不過儘管如此，我還是非常的謝謝你。\n"
      "說完這些話，肥東繼續哀聲嘆氣的做今天的菜。\n\n");
     
     
      this_player()->set_temp("fat_quest",(["ask":0,
                                            "diet":0,
                                            "meat":0,
                                            "fish":0,
                                            "cook":0,
                                           ]));
      call_out("recover",10,this_player());
     return 1;
     }
  else return 1;
    }
  else  {
    write(
    "你確定要用手來打掃嗎?\n");
    return 1;    
        }
}
int recover()
  { 
   write(
   "肥東抬頭看了你一眼後說：看你這樣的熱心助人，不知道你願不願意幫助\n"
   "我解決我的苦惱(trouble)呢?\n");
   this_player()->set_temp("fat_quest/ask",1);
   }   
int do_consider(string arg)
{
  if ( !arg || arg != "meat")
  return notify_fail(
  "討論什麼?\n"  );
  if ((int)this_player()->query_temp("fat_quest/meat")==2 && present("cooker")) {
  write(
  "肥東說道: 原來如此，可是像我們這種公營事業，經費是不能隨便亂用的.....\n"
  "說完，肥東又開始長噓短嘆........\n"
  "你想，這實在是一個困難的任務，憑你的智慧是很難處理的。或許應該找個聰明\n"
  "人一同來參詳\n");
  this_player()->set_temp("fat_quest/ask",2);
  return 1;
  }
  else return 0;
  }
 int do_suggest(string arg)
 {
 if (!arg || arg != "fish" )
 return notify_fail(
 "建議什麼?\n" );
 if ((int)this_player()->query_temp("fat_quest/fish")==1 && present("cooker"))  {
 write(
 "肥東說道: 用魚去作料理，聽來像是個好主意，但是我從來沒有試過，也許你可\n"
 "以先去把材料拿回來看看。\n");
 return 1;
 }
 else { write(
 "你想要幹什麼?\n");
 return 1;
}}
int clean_up() { return 0; }