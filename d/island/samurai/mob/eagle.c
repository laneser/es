#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Eagle Nanaruha ", "老鷹 那那魯哈" );
        add ("id", ({ "eagle","nanaruha"}) );
        set_short( "Eagle Nanaruha","老鷹 那那魯哈");
        set("unit","位");
        set_long(@AAA
那那魯哈是一隻兇猛的大鷹，擁有強健的翅膀與尖銳的爪牙，是娜考露露的好
友，經常旁在娜考露露的身旁！！
AAA
        );
        set("hit_points",350);
        set("max_hp",350);
        set ("natural_weapon_class1", 50);
        set ("natural_min_damage1",15);
        set ("natural_max_damage1",45);
        set ("natural_armor_class", 65);
        set("natural_defense_bonus",18);
        set_c_limbs(({"身體","頭部","爪子","翅膀"}));
        set_c_verbs( ({"%s向下俯衝，撞向%s","%s用尖銳的爪子抓向%s","%s用翅膀拍向%s"}) );
       
}