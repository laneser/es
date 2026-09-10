#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "keeper hau", "霍先生" );
    add( "id",({"keeper","hau"}) );
    set_short( "帳房 霍先生");
    set("no_attack",1);
    set_long(@C_LONG
霍先生約莫四、五十歲年紀, 戴著一隻小小的玻璃鏡片,鏡片裡好像看不到任何有
關眼睛的訊息。頂著鏡片的是一個紅紅鼻子, 呼吸間有著濃濃的酒臭味,走起路來
一搖一擺的好像被風一吹就會摔倒在地,可見他平時喝酒之多。他看起來好像遇到
麻煩了,也不去平時去的『薪膽村』酒店喝酒。
C_LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",45);
    set("gender","man" );
    set("no_attack",1);
    set("chat_chance",4);
    set("chat_output",({
            "霍先生不停地走來走去。\n",
            "霍先生停下來望著天花板似乎在想事情。\n",
            "霍先生深深地嘆了一口氣,霍先生嘆到:唉~~。\n"
    }) );
    set("inquiry", ([
             "trouble":"@@ask_trouble",
             "help":"@@ask_help" 
    ]) );
}        
void ask_trouble(object asker)
{
    tell_object(asker,
     "霍先生說道:這位英雄好漢,請問你能幫助 ( help ) 我嗎?\n"
       );
}
void ask_help(object asker)
{
    tell_object(asker,
     "霍先生說道:事情是這樣的:有一天晚上,我妻子替我看管監獄的鑰匙, 不知道\n"
     "           是誰, 從她背後偷偷地下了一個重手以致於她現在奄奄一息, 倒\n"
     "           床上昏昏沈沈的要死不活。於是我去請教過大夫, 大夫說她中了\n"
     "           某種厲害的掌力,需要『天山九轉熊蛇丸』( pill ) 才能夠醫治\n"
     "           她,可是這裡離天山那麼遠,我又有要事在身不克前往, 請問你能\n"
     "           幫我取來嗎?我會很感激你的\n"   
                );
}
int accept_item(object me, object item)
{
      string name,my_name;
      object ob;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
         
      if ( (name!="bear-snake pill") && (name!="sun pill") )
         return 0;
      
      switch ( name ) {
      case ( "bear-snake pill"):
         if ( ( item->query("master") ) != my_name ) {
            tell_object( me,
            "霍先生說道:咦,你這是從那裡偷來的九轉熊蛇丸? 拿回去吧, 我寧\n"
            "           死也不願用你偷來的藥!!\n");      
            command("give pill to "+my_name);
            return 1;}
         else {
            tell_object( me,
            "霍先生很感激地接過你的熊蛇丸,並對你說請等一下,我拿去給內人服用...\n"
            "霍先生把你的熊蛇丸拿給身邊的童子交由他帶到內室去。\n");
            item->remove();
            me->set_temp("keeper_finish1",1);
            call_out("recover1",10,me);
         }
         return 1;
      case ( "sun pill" ):
         if ( ( item->query("master") ) != my_name ) {
            tell_object( me,
            "霍先生說道:咦,你這是從那裡偷來的六陽正氣丹? 拿回去吧, 我寧\n"
            "           死也不願用你偷來的藥!!\n");
            command("give sun pill to "+my_name);
            return 1;}
         else {
            tell_object( me,
            "霍先生接過你的正氣丹,交由身邊童子帶到內室去。\n");
            item->remove();
            me->set_temp("keeper_finish2",1);
            call_out("recover2",10,me);
         }              
      }
}      
void recover1( object obj)
{
    tell_object( obj,
      "\n你忽然聽到一個悽慘的叫聲!!!!\n\n\n"
      "內室有一個童子跑到霍先生的身旁咬耳朵。\n"
      "霍先生說道:怎麼會這樣?快快快,你快去找醫生救命!!我內人服用了你帶來的\n"
      "           九轉熊蛇丸之後就口吐白沫暈倒了!!\n"
        );     
}
void recover2( object obj)
{
    tell_object( obj,
      "從內室跑出來的童子依舊到霍先生的身旁咬朵耳。\n"
      "霍先生微笑地向你謝道:大恩不言謝,內人的病終於好了。\n"
      "霍先生說道:對了,跟你說一件事,內人剛說那天偷襲他的人好像跑往\n"  
      "           監獄 ( jail ) 那個方向,如果你想知道監獄在那裡,可\n"
      "           以去請教幫中高層份子。\n" );
}