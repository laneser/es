#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("海威港碼頭");
        set_long( @C_LONG_DESCRIPTION
你現在正站在海威鎮的碼頭上，數十艘或大或小的漁船散佈在港口內。你看到
許多漁民將魚網(net)掛在碼頭旁邊的空地，往南不遠處是一個魚市場(market)，
這裡偶爾會有來自西方的諾頓渡輪停靠，海威鎮的居民對這些打擾他們平靜生活的
陌生人早已司空見慣，你的出現並沒有引起太多人的注意。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "c_item_desc", ([ 
                "net" : @LONG_TEXT
這些魚網因為經年使用，所以上面都因為海水的浸蝕而佈滿了許多小孔，由此
也可以看出這裡的居民生活非常節儉。
LONG_TEXT
, 
                "market" : @LONG_TEXT
魚市場就在南邊不遠處，漁民們出海打魚回來就會把一簍一簍新鮮的漁獲運到
市場去賣。
LONG_TEXT
 ]) );
    set("objects",([
        "mew1":"/d/eastland/haiwei/monster/mew",
        "mew2":"/d/eastland/haiwei/monster/mew"]));  
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/road_jetty" ]) );
        reset();
#include <replace_room.h>
}

void init()
{
        if( !find_object("/d/std/ocean/ship_iriah") )
                "/d/std/ocean/ship_iriah"->frog();
        if( !find_object("/d/std/ocean/ship_ta_tong") )
                "/d/std/ocean/ship_ta_tong"->frog();
}
