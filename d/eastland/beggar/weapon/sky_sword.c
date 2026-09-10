#include <mudlib.h>

#define DETECT_ALI(x) (int)x->query("alignment") 
#define DETECT_SCORE(x) (int)x->query("war_score")
inherit WEAPON;

void create()
{
    set_name( "blood sword","赤血劍" );
    add("id",({"blood","sword"}) );
    set_short( "赤血劍" );
    set_long(@C_LONG
一把劍身呈紅色的長劍。赤血劍的來源已不可考,只知道是在三國時代一位偉大的
鑄劍師製成。這把劍還有一段不為人知的歷史;想當初那位鑄劍師為了讓這把劍有
了靈氣,不惜投身於火爐之中,於是在劍身似乎還留有一絲絲紅色的血氣。
C_LONG
            );
    set("unit","柄");
    setup_weapon("longblade",20,15,15);
    set("weight",50);
    set("value",({400,"silver"}) );
}
