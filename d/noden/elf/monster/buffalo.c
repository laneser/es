#include "../layuter.h"

inherit MONSTER;

void create()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(4);
        set_name( "buffalo", "野牛" );
        set_short( "野牛" );
        set("unit","頭");
        set_long(
        "你看見一隻壯碩的動物，有著兩隻長長的角，而它那兇惡的眼神，\n"
        "正彷如警告般的瞪著你\n"  
        );
        set_perm_stat("str", 5);
        set("max_hp",60);
        set("hit_points",60);
        set ("natural_weapon_class1", 4);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 5);
        set ("natural_armor_class", 17);
        set_c_verbs(({"%s用它的長角向%s攻擊","%s用它的後腿向%s踢去"}));
        set_c_limbs(({"身體","頭部","腳部","尾巴"}));      
}
