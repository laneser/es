
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("potion", "奇怪的藥水");
        add( "id", ({ "s_potion","potion","strange potion" }) );
        set_short( "奇怪的藥水" );
        set("long",@LONG
這是一個很奇怪的藥水瓶，裡面裝了些橙色的藥水，上面還貼了張標籤(list)。
LONG
        );
        set( "weight", 20 );
        set( "unit", "瓶" );
}

void init()
{
        add_action("to_read","read");
}

int to_read(string s)
{
        if (s != "list") return 0;
        tell_object(this_player(),@LONG

你仔細的開始讀上面所寫的標籤：
        成份：曼陀羅花的根，龍葵，百葉草，桐木果。
        作用：強化肌肉及神經反應。
請小心收藏，切勿外傳。
LONG
        );
        return 1;
}
