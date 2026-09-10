#include <mudlib.h>
#include "../../story.h"
inherit SPALACE"sacrifice";

void create()
{
    ::create();
    set_short( "plate", "奉獻臺" );
    set_long(@C_LONG
這裡是奉獻臺，在這裡你可以把你要的東西奉獻給天帝，如果，你誠心夠的話
，天帝會賞賜給你一些錢。
C_LONG
    );
    set("light",1);
    reset();
}