#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "golden older", "金石老人" );
	set("id",({"older"}));
	set_short( "金石老人" );
	set_long(@C_LONG
你眼前所見的是一位面貌清矍、身材極為瘦小的老人。他鼻塌嘴闊，鼻孔掀天，兩
眼深陷，眉毛甚是稀疏，全身皮膚呈現金黃色，一副不太愛理人的樣子，古怪已極
。金石老人生平最喜歡收集和與人交換(exchange)奇物異寶，除此之外，沒有什麼
嗜好。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(30,0); 
        set("no_attack",1);
        set("inquiry",([
          "exchange":"@@ask_exchange",
          "fly_building":"@@ask_building"
        ]) );
}
void init()
{
   ::init();
   add_action("do_help","help_me");
   add_action("do_select","select_me");
}
int do_help(string arg)
{
    object player;
    player=this_player();
    if (!player->query_temp("golden_older_asked")) return 0;
    switch ( arg){
    case "1":
        write(@LONG
金石老人道：
遁龍樁是遁法的一種，是我早年用法術練的，不管你遭遇到什麼樣的危險或者
身在千里之外，你只要(use_dragon_wood)，它都會把你帶到我的住所來。　
LONG
    );
       return 1;
    case "2":
        write(@LONG  
金石老人道：
萬相俱滅術是我多年研究有形無形等物質的心得而來的。萬相俱滅術在於隱藏
自已的形蹤變成空氣中的塵埃，並在空間放著一個自己的法相用以欺騙敵人，
以達到保護自已的功用。不過，由於研究的不完全，所以只能對某些特定的怪
物而使用。使用時，你只要　(　cast-me wonderful　)　就可以了，不過請
切記，這術有使用的時效，如果想變回只需　( uncast-me wonderful )　就
可以了，據我的估計，全部有半個時辰的時效。
LONG   
    );
        return 1; 
    case "3":
        write(@LONG
金石老人道：
純金打造的籃子，有點像狗籠之類的，可以用來裝(package)動物。
LONG
    );        
        return 1;
    default:
        write("金石老人道：這並不在我跟你交換的東西之內。\n"); 
        return 1;
    }
}
int do_select(string arg)
{
    object player,item;
    player=this_player();
    if (!player->query_temp("golden_older_asked")) return 0;
    player->delete_temp("golden_older_asked");
    switch(arg) {
    case "1":
         write("你想了想，決定要遁龍樁這樣東西。於是金石老人拿出了遁龍樁放在地上。\n");         
         item=new(SWITEM"flee1");
         item->move(environment());
         return 1;
    case "2":
         write("你想了想，決定要萬相俱滅術這樣東西。於是金石老人拿出了萬相俱滅術放在地上。\n");
         item=new(SWITEM"spell2");
         item->move(environment());
         return 1;   
    case "3":
         write("你想了想，決定要金色籃子這樣東西。於是金石老人拿出了金色籃子放在地上。\n");
         item=new(SWITEM"basket1");
         item->move(environment());
         return 1;
    default:
         write("金石老人道：這並不在我跟你交換的東西之內。\n");                       
         player->set_temp("golden_older_asked",1);
         return 1;
    }
}
void ask_exchange(object asker)
{
   
   if ( asker->query_temp("golden_older_asked") ) {   
       write(@LONG
金石老人道：請問你要交換下列什麼樣的東西呢？

     **********************************
       1.遁龍樁(dragon wood)。
       2.萬相俱滅術(wonderful-spell)。
       3.金色籃子(golden basket)。

       
如果不懂請打(help_me number)，決定好了以後選一樣(select_me number)。
LONG
   );
   return;
   }

   if ( asker->query_temp("exchange_things_with_older") ) {
       write("金石老人道：怎麼，今天有帶什麼東西來跟我交換嗎？\n");   
       return ;
   }
   if ( !asker->query_temp("golden_older_asked") ) {
      write("金石老人白了你一眼道：小孩子沒事不要來打擾我，問東問西的，討厭死了～\n");
   return ;
   }
}
void ask_building(object asker)
{   
   if ( asker->query_temp("exchange_things_with_older") ) {
   write(@LONG
金石老人道：天都？看在你跟我交換東西的份上，我就指點你一迷津。天都是眾神
　　　　　　居住的地方，想去天都得借「飛翔之笛」(fly_flute)才能到達。
LONG
   );
   return ;   
   }
  write("金石老人白了你一眼道：小孩子沒事不要來打擾我，問東問西的，討厭死了。\n");
  return ;
}
int accept_item(object player, object item)
{
    if ( !item->query("special_things") ) {
       item->remove();
       tell_object(player,@LONG

金石老人接過你給他的東西並且打量一番...
金石老人開口道：這個東西並不怎麼樣，不過，既然拿了你的東西，那我也不能失禮。
接著金石老人從口袋裡掏出一個銀幣給你，接著就不理你了。

LONG        
    ); 
       player->add("wealth/silver",1);
       return 1;
    }
    item->remove();
    player->set_temp("golden_older_asked",1);
    tell_object(player,@LONG
金石老人接過你給他的東西打量一番後瞪大了眼！
金石老人喜牧牧地開口道：嗯，的確是個非凡的東西，這樣吧，我也送你一樣
                       東西做為交換好了。
金石老人在四周翻倒櫃拿了幾樣東西。
金石老人說道：嗯，下列有幾樣東西你挑一樣吧，如果不知道那一樣好，你就
              ( help_me number )好了，我會跟你說明。決定好了以後，選
              擇( select_me number )一樣你喜歡的，不過選擇好以後就不
              準後悔了。　　

     **********************************
       1.遁龍樁(dragon wood)。
       2.萬相俱滅術(wonderful-spell)。
       3.金色籃子(golden basket)。       


LONG
    );
    player->set_temp("exchange_things_with_older",1);
    return 1;
}
