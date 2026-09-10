#include "/d/eastland/beggar/dony.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "『吉祥』賭坊" );
        set_long(@C_LONG
你立足之地是『薪膽村』裡面最大的賭坊,這裡的空氣有點混濁, 吆喝聲特別
大。在村裡,平時人們沒有什麼地方可以去遊憩的,也沒有什麼東西好娛樂的,只有
來這兒賭上一、兩把賺賺外快, 你也可以來這裡試試你的手氣喔。不過俗話得好:
『十賭是九輸』,你應該不會這麼傻吧。牆壁上有一張紙。
C_LONG
        );
        set( "c_item_desc", ([
            "paper" :@C_LONG
斗大的字上面寫著:
        本賭坊的賭法採一次開三個骰子的方式;你先要 ( bet number type )
        如: bet 100 silver 表示你一局押 100 個銀幣的籌碼,再 ( select 
        number number number ) 如: select 2 3 5 表示你押 2 3 5 這三個
        數字。三個數字都完全命中則賠你 200 倍的籌碼;除此之外就沒有了。 
C_LONG
        ]) );
                                         
        set("exits",([
             "west":DBEGGAR"north1"
        ]) );
        set("objects", ([
             "merchant":DMONSTER"ch_waiter"
        ]) );     
        reset();
}
void init()
{
      add_action("do_bet","bet" );
      add_action("do_select","select");
}

int do_bet(string arg)
{
   object who;
   string type,weal_type;
   int num,weal;
                           
   if ( !arg || arg=="" || sscanf( arg, "%d %s", num, type)!=2 )
       return notify_fail("你要押多少？什麼種類的錢？\n");
   if ( type!="silver" )
       return notify_fail("請你以銀幣為單位,謝謝。\n");
   who=this_player();
   weal=who->query("wealth/silver");                        
   if ( num > weal )
       return notify_fail("對不起,你身上所帶的錢不夠喔。\n"); 
   if ( num > 5000 )
       return notify_fail("對不起,小小的店面請不要超過 5000 銀幣。\n");
   who->set_temp("money_bet",num);
   tell_object(who,
      "你押 "+num+" 個銀幣。\n");
   return 1;    
}
int do_select(string arg)
{
   object me;
   int num1,num2,num3,number1,number2,number3,bet_money;
   
   if ( !arg || arg=="" || sscanf( arg, "%d %d %d", num1, num2, num3)!=3 )
       return notify_fail("你到底要押那幾個數字呀？\n");
          
   if ( num1>6 || num1<1 || num2>6 || num2<1 || num3>6 || num3<1 ) 
       return notify_fail("你是不是輸昏了頭,骰子有不是小或等於六的正整數嗎?笨!\n");
   
   me=this_player();
   bet_money=me->query_temp("money_bet");

   if ( !bet_money )
       return notify_fail("對不起,你得先押一些籌碼。\n");
   if ( bet_money > (me->query("wealth/silver")) )
       return notify_fail("對不起,你身上所帶的錢不夠喲。\n");
   
   tell_object(me,
      "你現在一共押了 "+num1+" "+num2+" "+num3+" 這三個數字。\n");
   me->add("wealth/silver",-bet_money);
   number1=random(6)+1;
   number2=random(6)+1;
   number3=random(6)+1;        

   tell_object(me,
      "開出來的結果是 "+number1+" "+number2+" "+number3+" 個數字。");
   if ( ( num1==number1 ) && 
        ( num2==number2 ) && 
        ( num3==number3 ) ) {
         me->add("wealth/silver",201*bet_money);
         tell_object(me,"PERFECT!!竟然完全被你猜中,厲害厲害!!\n");
         tell_room(this_object(),                
"天空傳來一聲寧丹的嘆息聲,"+me->query("c_name")+"竟中了二百倍的獎金!!\n",me);
   } else
      tell_object(me,"可惜,沒猜中。\n"); 
   return 1;                     
}
