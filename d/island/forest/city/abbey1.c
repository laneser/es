#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("徵木神社");
    set_long(@LONG
神社中似乎沒有想像中的那麼可怕，只見簡單的陳設，供奉著三位守護靈：
一位是『船穗』，一位是『龍皇』，另一位是『津名魅』；雖然這裡並沒有供奉
三位守護靈的雕像，無法得知他們的真面目，但是，傳說他們都是很親切和藹的
靈，如果你有幸，說不定能見到他們顯靈呢！外面那一棵就是『津名魅』！如果
你是有緣人，肯誠心誠意的在她面前祈禱(pray)，或許她會出現在你的面前哦！
LONG
            );
    set("light",1);
    set("exits",([
        "out":CITY"abbey"]) );
    set("no_monster",1);
    reset();
#include <replace_room.h>
}
