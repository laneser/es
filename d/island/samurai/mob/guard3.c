#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(14);
        set_name( "samurai guard", "武士守衛" );
        add ("id", ({ "samurai","guard"}) );
        set_short( "samurai guard","武士守衛");
        set("unit","位");
        set_long(@AAA
這是一個專門負責武士城堡城牆守衛之職的武士，他對於你的到來
似乎非常不滿．
AAA
        );
        set_perm_stat("str",25);
        set_skill("dagger",70);
        set_skill("parry",60);
        set("hit_points",250);
        set("max_hp",250);
        set ("natural_weapon_class1", 27);
        set ("natural_min_damage1",7);
        set ("natural_max_damage1",18);
        set ("natural_armor_class", 40);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",300);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        
        wield_weapon(MOBJ"samurai_short_blade.c");
        equip_armor(MOBJ"samurai_chainmail.c");
}

void init()
{
tell_room(environment(this_object()),"喂！喂！你以為這是觀光勝地嗎？再不快走小心我扁你喔！\n");
}