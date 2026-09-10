// g0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("廢棄的花園");
    set_long(@C_LONG
你來到了一個廢棄的花園，到處長滿了雜草和青苔。這裡瀰漫著很重的溼
氣，當然少不了那刺鼻的黴味無禮地刺激著你的嗅覺。雜草中似乎隱藏著一條
小徑通往北方，「或許那兒的空氣會比這裡好一些」，你想。
C_LONG
	    );
    set("exits", ([ "north" : AREA"g1" ]) );
    reset();
}
