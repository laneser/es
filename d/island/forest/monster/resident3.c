#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Centaur Woman","半人馬農婦");
    add("id",({"centaur","woman"}) );
    set_short("半人馬農婦");
    set_long(@C_LONG
這是一個魔族的『農奴』，他們祖先被迫跟隨魔族的一支來到這個荒島上墾荒。近來
天皇希望他們能增加生產力，以增強國力，抵抗蜥蜴人及人類的侵略，已經改革了很
多政策，因此雖說是奴，生活倒也過得還不錯。她現在下工了，所以在公社中休息。
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-300);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set("wealth/silver",50);
    set_natural_weapon(10,8,15);
    set_natural_armor(25,0);
}

