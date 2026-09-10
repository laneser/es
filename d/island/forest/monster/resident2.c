#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(8);
    set_name("Centaur Hoodlum","半人馬流氓");
    add("id",({"centaur","hoodlum"}) );
    set_short("半人馬流氓");
    set_long(@C_LONG
這是一個魔族的『農奴』，他們祖先被迫跟隨魔族的一支來到這個荒島上墾荒。近來
天皇希望他們能增加生產力，以增強國力，抵抗蜥蜴人及人類的侵略，已經改革了很
多政策，因此雖說是奴，生活倒也過得還不錯。不過這傢伙好吃懶做，所以幹起流氓
來了。
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",-350);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",11);
    set_perm_stat("dex",11);
    set("killer",1);
    set("c_killer_msg","流氓發現你在瞄他，大喝：看啥？立刻向你衝了過來....\n");
    set("wealth/silver",150);
    set_natural_weapon(15,23,26);
    set_natural_armor(32,5);
}

