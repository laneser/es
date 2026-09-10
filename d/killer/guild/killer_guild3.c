//sage修改於： 98-6-11
#include "/d/monk/guild/saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
        ::create();
    set_short("殺手武功練習室");
        set_long( @LONG_DESCRIPTION
這是一個很潮溼陰暗的房間，整個房間瀰漫一股血腥香味。由於長沒有人來過，你發
現地上的石板都長滿了厚厚的一層青苔。    
這個房間的正中央有一具骸骨，不知道是何用意，牆上貼了一張紙(paper) 。  
LONG_DESCRIPTION
        );
    set("c_item_desc",([
         "bone":@BOOK
          一具很陳舊的骸骨，可能是某個武林高手在這裡死後留下來的唯一的紀念
      品，想到這裡，你從心底下產生了一種敬仰之情，要不是怕別人看見，你真想
      跪下去個給這位老前輩磕幾個頭。        
BOOK
         "paper":@BOOK
                         
                           偷兵器劍法修習資格

       1. 是本公會護法以上身份。
       2. 要非常邪惡。  
       3. .............(不可告人的條件，看你是否有緣)。 

       達到以上資格者，才能在此練習偷兵器劍法(practice getsb-sword) 

       注: 本公會絕技眾多，但本公會一向主張在精不在多的原則，每個會員只能擇
           其一學之。
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
//             "down" : SAULIN"72" ]) );  
               "west" : "/d/killer/guild/killer_guild"]) );
        reset();
}

void init()
{
        add_action("to_study","ketou");
//      add_action("to_delete","sangon");
}

/*
int to_delete(string arg)
{
        object me;
        if( !arg || arg != "bone" ) return 0;
        me = this_player();
        if( undefinedp( me->query("monk_gonfu/power-finger") ) )
             { write(" 你跟本不曾學過大力金剛指! \n");
               return 1;
             }
        else {
        write("你的金剛指力暫時消失了!!! \n"); 
                me->delete("monk_gonfu/power-finger");
                me->set("monk_learn/72",0);
                return 1;  
         }
} 
*/      /*暫時決定不能散功*/

int to_study(string arg)
{
        object me;

        if( !arg || arg != "getsb-sword" ) return 0;

        me = this_player();
        if( !wizardp(me) && (string)me->query("class") != "killer" )
                write("你不是本公會的人所以不能學此功夫。\n");
//        else if( (int)me->query_level() < 15 )
//                write("『 你的職級太低，沒資格學。\n");
//        else if( (int)me->query_perm_skill("inner-force") < 72 )
//                write("『 你的基本內功\(inner-force)技巧太差，沒資格學。\n");
//        else if( ((int)me->query_perm_stat("str") < 17) 
//                          )
//                write(" 你的力量不夠，還沒資格學大力金剛指。\n");
//        else if( !undefinedp(me->query("monk_gonfu/power-finger")) ) {
//                if((int)me->query("monk_gonfu/power-finger")==35) {
//                        write("你已經完全瞭解大力金剛指的要義了，可以再去練習另一種絕技。\n\n");
//                        me->set("monk_learn/72",0); }   
//                else write("你已經學會大力金剛指了，快去練習吧!\n"); }
          else if( me->query("killer_learn/72") )
                  write("你已經學過一項絕技了!\n");
          else {
                write(@LONG
        
       突然，骸骨站了起來衝著你一陣陰笑，你立刻毛骨悚然，嚇得雙腳一軟，
   跌到在地，骸骨伸出兩隻鬼抓向你腦袋抓來，你只覺得腦袋一陣劇痛，心想
   到：“我命休已。”就昏了過去。

LONG
                );  
                me->set("monk_gonfu/power-finger", 0);
                me->set("monk_learn/72",1);
        }  
    return 1;  
} 

int clean_up() 
     { return 1; }
