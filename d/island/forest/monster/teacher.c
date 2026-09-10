#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(10);
    set_name("School Teacher","私塾先生");
    add("id",({"teacher"}) );
    set_short("私塾先生");
    set_long(@LONG
這是一位盡職的先生，正為了生活而認真的講課。
LONG
            );
    set("unit","位");
    set("race","daemon");
    set("weight",300);
    set("hit_points",300);
    set("max_hp",300);
    set_perm_stat("str",12);
    set_perm_stat("dex",13);
    set_skill("dodge",50);
    set("wealth/silver",200);
    set_natural_weapon(10,5,12);
    set_natural_armor(15,5);
    set("tactic_func","my_tactic");
    set("chat_chance",10);
    set("chat_output",({
 "先生邊晃著頭邊喃喃道：人之初，性本善；性相近，息相遠..................\n"}) );
}

int my_tactic(object victim)
{
    if( !(victim=query_attacker()) ) return 0;
    if( random(20)<3){
    tell_object(victim,@ALONG

私塾先生大罵：好大的狗膽，敢擋老子發財，給你顏色瞧瞧.......
罵著罵著，一塊硯臺向你臉上砸來!!!!!
ALONG
         );
    tell_room(environment(victim),
    "私塾先生對"+victim->query("c_name")+"破口大罵，隨即拿起硯臺亂扔!!\n"
    ,victim );
    victim->receive_special_damage("evil",20);
    report(this_object(),victim);
    return 1;
    }
}