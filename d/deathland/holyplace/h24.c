
#include "../echobomber.h"
#include <move.h>
inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("mystic fire","妖火");
  set_long(@Long
Long
,@CLong
你已經清楚地看到那團妖火了, 只見一種邪惡的氣氛由火團裡散出, 令人不寒
而慄. 
CLong
);
set("item_func",([
    "fire":"to_look_fire",
    ]) );
set("search_desc",([
    "fire":"一團可怕的火, 你最好別太靠近它.\n",
    ]) );    
set("exits",([
             "east":Deathland"/holyplace/h23",
             ]));
reset();
}

int to_look_fire()
{
    object player;
    player=this_player();
    write("當你看著那團火的時候, 你的人覺得昏昏沉沉的, 只覺得有個模模"
          "糊糊的人影慢慢地出現在你的眼中.\n");
    player->set_temp("block_command",1);          
    say("當"+player->query("c_short")+"注視著火團的時候, 你覺得他好像失了魂似的.\n");
    call_out("quest",3,player);
    return 1;
}

void quest(object player)
{
     tell_object(player,
     "一道清晰的聲音傳入你的腦海.\n"
     "我, 暗黑巫妖 , 邪惡之神 YANG 的弟子 , 艾思(ICE) , 現在召喚你.\n"
     "你很榮幸地可以為我效勞. 我須要一個人幫我解除禁錮於我身上的詛咒\n"
     ", 你只須要找到我的駭骨, 撕掉附在它身上的那道符咒, 然後回到這裡\n"
     "你將得到你的報償.\n"
     );  
     if ( present("paper",player) ) { 
       tell_object(player,
       "想不到你帶回了這個該死的符咒, 我想我將可以恢復我的魔力了.\n"
       "哈哈哈.....\n\n\n\n"
       "此時你看到妖火慢慢地由明變暗........\n"
       );
       call_out("quest_2",4,player);
       }
     else
       player->set_temp("block_command",0);
     return;
}


void quest_2(object player)
{
     object item;
     int moveflg;
     
     tell_object(player,
     "\n\n\n\n\n\n火再度地亮了起來.\n\n"
     "妖火說到: 那符咒已經被下了極可怕的咒語, 凡人將無法解除它.\n"
     "想不到哈德瑞得屈裡的魔力變得如此強大. 這個可惡的傢伙, 我\n"
     "想到如今他的法力也應該和我當年一樣了吧! \n"
     "我能寄望你能為我打敗他嗎? 不過我也沒有選擇了. 送你一個月\n"
     "之鑽. 這是唯一你能夠擊敗他的物品, 但是經過了這幾個世紀,\n"
     "不知還有沒有效. \n"
     );
     item=new(Object"/diamond01");
     moveflg=item->move(player);
     if ( moveflg !=MOVE_OK ) { 
       tell_object(player,
       "**你無法拿的動這月之鑽**.\n"
       );
       item->remove();
       }
     player->set_temp("block_command",0);
     return ;  
}
