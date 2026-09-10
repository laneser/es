
inherit "/std/pet.c";
#include <mudlib.h>

void init()
{
        ::init();
     add_action( "order_me","order_god");
     add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(19);
        set_name( "god", "蘭迪斯" );
        set_short( "炎之魔神 蘭迪斯");
        set_long(
@C_LONG
"本來是波士的守護神,可因為學炎魔功而走火入魔。\n"
"變成了罪大惡極的魔神，可還是不能忘記波士的大恩大德。\n"
"所以在波士在pk時就會出現。laugh.\n",
C_LONG
        );
        set_perm_stat("str", 60);
        set_perm_stat("con", 60);
        set_perm_stat("dex", 60);
        set_skill( "defend", 100 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set_skill( "block", 100 );
        set_skill( "longblade", 100 );
        set( "alignment", -100000 );

        set( "race", "human" );
        set( "gender", "male" );
        set_natural_weapon( 60, 60, 60 );
        set_natural_armor( 90, 60 );

        set( "hit_points", 200000 );
        set( "max_hp", 200000 );

        set("max_load", 180);
        set("weight", 180);
        set("post_name","'s guard god");
        set("c_post_name","守護神");
        set("prevent_give_money", 1);
        set("pet_type", "god");
                set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s舉起一把劍%s一砍", "%s用它身上的火炎噴%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "蘭迪斯用它邪惡的眼神看了看周圍的人。\n",

        "蘭迪斯噴出火炎把波士燒焦。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了過來");
        setenv("C_MMOUT","$N跟著它的主人走開");
}
