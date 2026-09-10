#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
殿內長廊到這裡已經是盡頭，廊道往東北方向延伸。廊道白玉鋪地，欄杆雕飾
精細，朱壁每尺鑲嵌著拳大夜明珠，好似一條蜿延銀蛇，不時發出白光，照耀著滿
道通明。廊旁有幾座樓閣，每座竟不知好幾層，每層九間，通體碧玉砌成，瓊檻瑤
階，金門翠東，雕雲縷月，氣象莊嚴，奇麗無儔。細看前面幾層，層層的陳設無不
窮極精麗，妙奪天工，於珠光寶氣中現出古色古香，別有雍穆清雅之致。樓閣之中
圍著一小型殿堂，通體水晶建成，白光燦爛，耀眼生輝。
LONG
	);
        set("light",1);
        set("pre_exit_func",([
           "northwest":"can_pass"]));
        set("exits" , ([
           "northeast" : SPALACE"n2",
           "northwest" : SPALACE"house1"
        ]) );
	reset();
}
int can_pass()
{
    if ( this_player()->query("palace_war") ) return 1;
    return 0;
}                            