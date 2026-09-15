#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(6);
       set_name( "huge crab", "大螃蟹" );
       add("id",({"crab"}) );
       set_short( "大螃蟹" );
       set("unit","只");
        set_long(
       "           ∪        ∪
           ﹨ ⊙  ⊙ ∕
           ︽\\┴─┴/︽     這是一隻體型碩大的火蟹，看來十分嚇人
           ︽︳    ▕︽
            ╰───╯\n");
       set_perm_stat("dex", 4);
       set ("natural_weapon_class1", 10);
       set ("natural_min_damage1",5);
       set ("natural_max_damage1", 10);
       set ("natural_armor_class", 1);
       set_c_verbs(({"%s用它的巨螯向%s攻擊"}));
       set_c_limbs(({"身體","頭部"}));
       set ("exp_reward", 200);
       set ("tactic_func", "fire_ball");
}

void fire_ball()
{
    object victim;
    if( !(victim=query_attacker()) || random(8)> 1 ) return 0;
    tell_object( victim,
      "火蟹突然張開大嘴，吐出一團火焰。\n" );
    tell_room( environment(this_object()),sprintf(
      "火蟹突然張開大嘴，對%s吐出一團火焰。\n",victim->query("c_name"))
     , ({ victim, this_object() })
    );
    victim->receive_special_damage("fire", 6, 1 );
}

