#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "小徑" );
    set_long(@C_LONG
你來到了一條清幽小徑,小徑的兩旁有一排排不知名的樹木,樹枝擋住了陽光,
顯得有些陰涼,樹上一些鳥兒正啾啾地叫著。你東方有一面大湖,湖上波潭相映,一
波波的漣漪,一隻只的白鷺絲或飛或停,煞是情趣。在旁有個告示牌 ( sign ) 。
C_LONG
    );
    set( "light",1);
    set( "can_use_sea_ball",1);
    set( "exits", ([
     "west":LAKE"plain0"
    ]) );
    set("c_item_desc",([
            "lake":"一面綠色的大湖。\n",
            "sign":@LONG
一張頗破舊的牌上面寫著:


          ＸＸ　遊客止步!!　ＸＸ
    
    
       近來發現湖中不時有妖怪出現,此地已列為管制區域!!
       因此,請不要在這裡逗留,更嚴禁亂丟東西到湖裡!切記切記!                  
   
   
   
LONG    ]) );
    set("pre_exit_func",([
        "tunnel":"can_pass"]));
    reset();
}

int can_pass( string arg )
{
    if ( !query("exits/tunnel") ) 
       return 1;
    if ( present("water beast",this_object()) ) {
       tell_object(this_player(),
         "無支祈以巨大的身軀攔在你身前不讓你過去..\n");   
       return 1; 
    }
}

void reset()
{
    delete("exits/tunnel");
    delete("exit_suppress");
    delete("c_item_desc/water-tunnel");
    ::reset();
}