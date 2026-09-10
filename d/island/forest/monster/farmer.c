#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Centaur Farmer","半人馬農夫");
    add("id",({"centaur","farmer"}) );
    set_short("半人馬農夫");
    set_long(@C_LONG
這是一個魔族的『農奴』，他們祖先被迫跟隨魔族的一支來到這個荒島上墾荒。近來
天皇希望他們能增加生產力，以增強國力，抵抗蜥蜴人及人類的侵略，已經改革了很
多政策，因此雖說是奴，生活倒也過得還不錯。
C_LONG
       );
    set("gender","male");
    set("race","centaur");
    set("alignment",-500);
    set("max_hp",120);
    set("hit_points",120);
    set_perm_stat("str",10);
    set_perm_stat("dex",10);
    set("wealth/silver",200);
    set_natural_weapon(15,13,22);
    set_natural_armor(30,5);
    set("inquiry",([
        "radish":"@@ask_radish"]) );
    wield_weapon(TWEP"hoe");
}

void ask_radish(object who)
{
    tell_object(who,".......蘿蔔喔，去那個倉庫那邊找我牽手的要啦！\n");
    return ;
}
