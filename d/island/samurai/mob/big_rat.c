#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(7);
        set_name( "big rat","大老鼠" );
        add ("id", ({ "rat"}) );
        set_short( "big rat","大老鼠");
        set("unit","只");
        set_long(@ANGEL
這是一個大老鼠，看起來很兇惡的樣子
ANGEL
        );
        
        set ("gender", "male");
        set_c_verbs(({"%s用它銳利爪子抓向%s","%s身體一轉用尾巴甩向%s","%s跳來用牙齒咬向%s"}));
        set_c_limbs(({"身體","頭部","腳部","尾巴"}));
}