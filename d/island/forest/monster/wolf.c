#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Magic Wolf","魔狼");
    add("id",({"wolf"}) );
    set_short("Magic Wolf","魔狼");
    set_long(@LONG
這是一隻可怕的狼，正猙獰的露出它的獠牙，兇狠的對你咆嘯著。
LONG
            );
    set("unit","只");
    set("alignment",-800);
    set("weight",600);
    set_perm_stat("str",18);
    set_perm_stat("dex",18);
    set("hit_points",400);
    set("max_hp",400);
    set("killer",1);
    set("pursuing",1);
    set("exp_reward",7000);
    set_natural_weapon(30,20,30);
    set_natural_armor(50,30);
    set("unbleed",1);
    set("c_killer_msg","突然間，魔狼咆嘯一聲向你撲了過來！");
    set_skill("dodge",80);
    set_c_verbs( ({"%s的獠牙咬向%s","%s的前爪抓向%s","%s的尾巴卷向%s"}) );
    set_c_limbs( ({"背心","前爪","後腿","頸部","額頭"}) );
    set("death_msg","%s\n");
    set("c_death_msg","%s說:今後我願誓死效忠您，主人!隨即幻化成一把長刃....!\n");
    set("alt_corpse",TWEP"sword1");
}
