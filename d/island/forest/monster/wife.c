#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name("Farmer's wife","半人馬農夫的妻子");
    add("id",({"centaur","farmer","wife"}) );
    set_short("半人馬農夫的妻子");
    set_long(@C_LONG
這是一個魔族的『農奴』，他們祖先被迫跟隨魔族的一支來到這個荒島上墾荒。近來
天皇希望他們能增加生產力，以增強國力，抵抗蜥蜴人及人類的侵略，已經改革了很
多政策，因此雖說是奴，生活倒也過得還不錯。
C_LONG
       );
    set("gender","female");
    set("race","centaur");
    set("alignment",-500);
    set("max_hp",150);
    set("hit_points",150);
    set_perm_stat("str",8);
    set_perm_stat("dex",8);
    set_natural_weapon(13,10,20);
    set_natural_armor(25,0);
    set("wealth/silver",100);
    set("chat_chance",15);
    set("chat_output",({
    "半人馬農夫的妻子一邊工作一邊罵道:死老公，聽說城外那棵大樹有求必應\n"
    "，要他一起去求個兒子也不肯.........\n"
      }) );
    set("inquiry",([
        "radish":"@@ask_radish"]) );
    wield_weapon(TWEP"hoe");
}

void ask_radish(object who)
{
  tell_object(who,"要蘿蔔呀，去那邊找(search)啦，那邊很多啦！\n");
  return ;
}