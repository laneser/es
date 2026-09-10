#include <mudlib.h>

#define INT(x)  (int)x->query_perm_stat("int")
#define ALI(x)  (int)x->query("alignment")
#define NAME(x) (string)x->query("c_name")
inherit WEAPON;

void create()
{
    set_name( "seven-star shortsword","名刀 七星劍" );
    add("id",({"shortsword"}) );
    set_short( "名刀 七星劍" );
    set_long(@C_LONG
七星劍的劍身鑲有七顆七彩寶石,分別照著北斗七星的方式排列。七星劍原本是上
古神兵利器, 但隨著三國時代『董卓』的滅亡而消失了好一陣子, 直到『明太祖』
挖掘『趙王陵』時又重現了出來。相傳七星劍一出, 就會帶來給人類一場大浩劫,
『董卓』亂政就是一個最好的例子。
C_LONG
            );
    set("unit","柄");
    setup_weapon("shortblade",30,15,20);
    set("weight",30);
    set( "bleeding", 10 );
    set("value",({2400,"silver"}) );
    set( "wield_func","wield_shortsword");
    set( "unwield_func","unwield_shortsword");
    set_c_verbs( ({ "手持%s暗捏劍訣,使出了一式『白虹貫日』快速地刺向%s",
                    "用%s刷刷刷連三劍,飛快地砍向%s",
                    "和%s身劍合一,一道人影電射向%s",
                    "把%s對準%s一丟,然後又撿了回來",
                  }) );   
}
