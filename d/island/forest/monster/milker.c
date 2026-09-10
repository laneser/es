#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(4);
    set_name("Milker","乳牛");
    add("id",({"cow"}) );
    set_short("乳牛");
    set_long(@LONG
你看見一只身上有著白底黑花的動物, 肚子還垂著大大的乳房, 雖然頭上還長著
兩隻角, 但是看起來似乎是十分溫馴的模樣!
LONG
            );
    set("unit","頭");
    set_perm_stat("str",5);
    set("hit_points",50);
    set("max_hp",50);
    set_natural_weapon(4,3,5);
    set_natural_armor(15,0);
    set_c_verbs( ({"%s用強有力的後腳踹向%s","%s用它頭上的角向%s攻擊"}) );
    set_c_limbs( ({"身體","頭部","腹部","尾巴"}) );
}