#include "iigima.h"

inherit ROOM;

int adv;

void create()
{

        ::create();
        set_short( "desk","祭壇");
        set_long(
@C_LONG
來到這裡，你看到一個偌大的祭壇，由四方形的石磚砌成的祭壇，
四周由八個大柱子支撐著祭壇的方形頂盤，頂盤上盤著無數條巨蛇的石
像(statue)□嚇！一陣刺耳的尖銳叫聲，從前方的引道傳來，你的勇氣
鼓勵你勇敢的邁開步伐向前進！
C_LONG
        );
        set( "light",1 );
        set( "exits", ([
                     "northwest": DROW"r29",
                    
                     "south": DROW"r33",
        ]) );
        set("c_item_desc",([
              "statue":
@C_LONG
嚇！！好大的蛇像，栩栩如生的模樣，張牙舞爪似乎要一口吞了你！
咦？蛇像的基座有個小洞(hole)，看來怪怪的....
C_LONG
,             "hole":
@C_LONG
這個小洞看來形狀怪怪的，不像被腐蝕的痕跡，倒像某種卡鎖，
好像可以放入(put)什麼東西....
C_LONG
     ])); 
        reset();
}

void init()
{
   add_action("do_put","put");
}

int do_put(string str)
{
        object ob,player;
        string scale;
        player = this_player();

   if( !str || str != "scale into hole" ) {
        write( "你要做啥?\n" );
        return 1;
     }
        ob = present("scale",player);
   if( !ob ) {
        write( "你身上沒有蛇鱗！\n" );
        return 1;
     }
   if( adv ) {
        tell_object( player,
                    "你把蛇鱗放進祭壇上的一個小洞，卡一聲！瞬時卡鎖彈開，鎖鏈鬆開了！\n"
                    "\n"
                    "你聽到東北方傳來陣陣的怪叫聲，噫～好可怕。\n"
                    );
        add("exits",(["northeast":DROW"r30"]));
	new(DRO"teeder")->move(this_object());
   ob->remove();
                    adv = 0;
                return 1; 
     }
        else tell_object( player,
                    "你放入了蛇鱗，但是什麼事都沒有發生。\n" );
   ob->remove();
   return 1;
}

void reset()
{
   room::reset();
   adv = 1;
   delete( "exits/northeast" );
}
