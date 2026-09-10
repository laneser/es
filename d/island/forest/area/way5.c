#include "../tsunami.h"
#include "move.h"



inherit ROOM;

int seed;

void create()
{
    ::create();
    set_short("枯木");
    set_long(@LONG
這兒四周長滿了奇形怪狀的植物，大多是目前尚不為人知的。風也已經
和緩多了，不像狹道中那般強勁可怕；令人不解的是：為何這兒的植物都欣
欣向榮，唯獨這棵十分巨大的樹(tree)會枯萎掉了呢？
LONG
             );
    set("exits",([
            "south":AREA"way4"]) );
    set_outside("island");
    set("item_desc",(["tree":@ALONG
仔細的瞧一瞧這巨大的枯木，似乎和河邊的那棵是相同品種的植物，只
是，為何河邊那棵會長得那麼茂盛，而這棵卻已經枯萎了呢？嗯......
難道傳說中的守護靈－龍皇　就是這幅模樣嗎？
ALONG
              ]) );          
    reset();
}

void init()
{
    add_action("do_pray","pray");
}

void reset()
{
    ::reset();
    seed = 1;
}
int do_pray(string str,object obj)
{
     
     obj=new(TOBJ"seed");
    
     if( !str || str != "seed")
        return notify_fail("你努力的祈求著，希望枯木能冒出一顆種子給你..\n"); 
     if( !this_player()->query_temp("luoko_quest")) {
   write("你虔誠的祈禱了半天，結果只有一隻烏鴉從你頭上呱呱叫著飛過....:P\n");
       return 1;
       }      
     
     if( seed == 0){
     write(@ALONG
突然一陣光芒圍繞著你，一位老態龍鍾的男人出現在你的面前：
    孩子，真是不巧，已經有人在幫我了，不過還是謝謝你！
ALONG
       );
       return 1;
     }
       else{         
     write(@BLONG
突然一陣光芒圍繞著你，一位老態龍鍾的男人出現在你的面前：
　　孩子，你願意幫我忙是吧？這是我的種子，也是我靈力的來源，請你將它種在
御花園中，讓我重生，好讓我有足夠的靈力來保護這個民族；孩子，一切就都拜託
你了！
　　只見到一棵種子緩緩的飄到你手中，接著光芒就消失了.........
BLONG
          );
     obj->set("getter",(string)this_player()->query("name") );
     obj->move(this_player());
     tell_room(environment(),
     "突然一陣光芒攏罩著"+this_player()->query("c_name")+"，但不久就消失了！\n");
     this_player()->delete_temp("luoko_quest");
     seed = 0;
     this_player()->set_explore("island#4");
     return 1;
     }
}
