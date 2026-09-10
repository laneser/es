#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
    ::create();
    set("lvlimit",15);
    set_level(7);
    set_name( "countryman ahtu", "阿土仔" );
    add( "id",({"ahtu","countryman"}) );
    set_short( "莊稼漢 阿土仔");
    set_long(@C_LONG
阿土仔穿著一件薄薄的短袖汗衫,露出兩條黑拗拗的粗壯手臂, 手臂上不下幾千百
個瘡疤。從阿土仔衣服的破洞所露出來的身體, 你依稀可以看到一條條的括痕,這
都是阿土仔平時辛勤工作的結果。 他昨天被發現受傷( hurt )倒在路旁因而被人
抬到藥鋪來接受小雪子的悉心治療。 
C_LONG
            );
    set("unit","位");
    set("gender","man" );
    set("race","human");      
    set("age",45);
    set_perm_stat( "dex", 14 );
    set_perm_stat( "str", 16 );
    set_perm_stat( "int", 7 );
    set_perm_stat( "con", 13 );
    set_perm_stat( "piety", 5 );
    set_perm_stat( "karma", 10 );
    set ("max_hp", 250);
    set ("hit_points", 250);
    set ("wealth", ([ "silver": 60 ]) );
    set_natural_weapon( 19, 10, 18 );
    set_natural_armor( 15, 2 );
    set ("weight", 550);
    set ("exp_reward", 1150 );
    set("chat_chance",2);
    set("chat_output",({
            "阿土仔不著地呻吟道:唉喲,好痛喲～\n",
            "阿土仔不著地呻吟道:早知道就不要多喝兩杯。\n"
    }) );
    set("inquiry", ([
             "hurt":"@@ask_hurt"
    ]) );
}        
void ask_hurt(object asker)
{
    tell_object(asker,
     "阿土仔嘆道:唉,昨天我去『牽豬哥』回來時多喝了兩杯,黑漆漆的不知道\n"
     "           碰到了什麼東西,然後被壓倒在地上。當我爬起來的時候,又\n"
     "           不知道被誰從後面重重的砍了一刀, 我就昏倒了。起來時就\n"
     "           在這裡了, 我一向沒有和人結仇,怎麼會那麼『雖』? 唉喲,\n"
     "           好痛喲～\n"
       );
}
