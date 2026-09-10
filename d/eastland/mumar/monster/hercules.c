#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(15);
        set_name( "Hercules", "力士" );
        add ("id", ({ "hercules", "yang" }) );
        set_short( "力士" );
        set_long(
    "牧馬關的力士們在戰爭中通常是擔任前鋒的職務，往往造成敵人的重大損失。\n");
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "個" );
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 10 );
        set_perm_stat( "int", 15 );
        set ("wealth", ([ "gold": 50 ]) );
        set_natural_weapon(10,14,17);
        set_natural_armor(75,35);
    set ("weight", 300);
    set( "pursuing",1 );
    set ("chat_chance", 10);
    set( "att_chat_output", ({
        "力士邊揮舞大□頭邊狂笑著：看我把你打成肉餅！\n"
        }));
    set("c_death_msg","%s 龐大的身軀晃了一晃，噗通一聲倒在你身上，差點把你壓昏..\n");
    set_skill("blunt",60);
    set_skill("parry",70);
    wield_weapon(OBJS"hammer1");
}
