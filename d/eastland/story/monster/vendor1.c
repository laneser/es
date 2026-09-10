#include "../story.h"
inherit MONSTER;
int left=1;
void create()
{
    ::create();
    set_level(1);
    set_name( "wander merchant", "旅行商人" );
    add("id",({"merchant"}));
    set_short( "旅行商人[騎在驢子上]" );
    set_long(@LONG
這是一個四處旅行販賣物品的人，他看起來風塵僕僕地正在趕往「巫咸國」去。他
賣的盡是一些稀奇古怪的東西，你可以向他詢問價格(price) ，看是否有什麼東西
是你喜歡的。
LONG    
    );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set( "inquiry", ([
	 "price" : "@@show_menu",
        "shadow" : "@@ask_shadow" 
    ]) );
    set( "player_invisible" ,1 );
}
void ask_shadow(object asker)
{
  write(@LONG
商人說道：唉喲，前幾天晚上有個冒失鬼撞了我一下，連個對不起都沒有就逃掉了
　　　　　，你看看，我肚子上還黑青一塊，痛死了，叫那個天殺的，早晚給雷劈
　　　　　死好了。我看他逃往南邊的山嶺方向，據說，那邊最近出沒一具僵□精
　　　　　，叫他給僵□啃死了也好。  
LONG
  );
}
void show_menu(object asker)
{
 if ( !left ) 
    write("商人說道：喔，你想要向我買東西喔，唉，真是抱歉，全都賣完了咩，請你下次再來。\n");
 else 
    write("商人說道：唉，今天太好賣了，只剩下水晶玻璃球(glass)而己，你要嗎？還有一顆，價錢是 5000 銀幣。\n"); 
}
void init()
{
    ::init();
    add_action("do_buy","buy");
}
int do_buy(string arg)
{
   object glass,player;
   if ( !arg || arg!="glass" )
      return notify_fail("商人說道：很抱歉，我沒賣那樣東西。\n");
   if ( !left )
      return notify_fail("商人說道：對不起，都賣完了。\n");
   player=this_player();
   if ( !player->debit("silver",5000) ) 
      return notify_fail("商人說道：對不起，你錢不夠，水晶玻璃球需要 5000 銀幣。\n");  
   glass=new(SWITEM"crystal1");
   if( glass->move(player)!=0 ) {
      glass->remove();
      player->add("wealth/silver",5000);
      return notify_fail("對不起，這樣東西對你來說太重了。\n");
   }                                                                      
   glass->set("special_things",1);
   glass->move(player);
   left=0;
   call_out("back",900);
   return notify_fail("你向商人買下了一顆水晶玻璃球。\n");
}
void back()
{  
   left=1; 
}