#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
殿內長廊到這裡已經是盡頭，廊道往東南方向延伸。廊道白玉鋪地，欄杆雕飾
精細，朱壁每尺鑲嵌著拳大夜明珠，流瑩生輝，照耀著滿道通明。廊旁有幾座樓閣
，每座竟不知好幾層，每層九間，通體碧玉砌成，瓊檻瑤階，金門翠東，雕雲縷月
，氣象莊嚴，奇麗無儔。細看前面幾層，層層的陳設無不窮極精麗，妙奪天工，於
珠光寶氣中現出古色古香，別有雍穆清雅之致。樓閣之中圍著一小型殿堂，玉柱金
庭，珠光寶氣。
LONG
	);
        set("light",1);
        set("exits" , ([
           "southeast" : SPALACE"s2",
           "southwest" : SPALACE"house3",           
        ]) );
        set("pre_exit_func",([
            "southwest":"can_pass"]));
        reset();
}        
int can_pass()
{
        if ( this_player()->query("palace_war") ) return 1;
        return 0;
}