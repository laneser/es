#include <mudlib.h> 
#include <ansi.h>
inherit TEACHER;
inherit MONSTER;

void create ()
{
        ::create();
        seteuid( getuid() );
        set_level(18);
        set_name( "yangsix", "楊六郎" );
        add ("id", ({ "yang","six"}) );
        set_short( "槍神 楊六郎" );
        set_long( @LONG
    生得劍眉星目,熊腰虎背,極cool的樣子,他是雷思由遙遠的東方大陸重金禮聘
來教導騎士槍法和內功的高手,如果你的等級夠高可以向他問一些關了train事情
LONG        );
        set( "alignment", 10000 );
    set( "gender", "male" );
    set( "race", "human" );
        set( "unit", "個" );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "con", 27 );
        set_perm_stat( "piety", 30 );
        set_perm_stat( "karma", 21 );
        set("max_hp", 3500);
        set("hit_points", 3500);
        set("wealth", ([ "gold": 3000 ]) );
        set_natural_weapon( 45, 25, 55 );
        set_natural_armor( 35, 30 );
    set("weight", 800);
    set("exp_reward",59000 );
    set_experience(450000);
    set_skill("parry",100);
    set_skill("block",100);
    set_skill("dodge",100);
    set_skill("jousting",100);
    set("unbleeding", 1);
    set("special_defense", ([ "all" : 50, "none" : 40 ]) );
    set("aim_difficulty", ([ "critical" : 50 ]) );
        wield_weapon( "/d/knight/fortress/weapons/dragonblood" );
        equip_armor( "/d/knight/fortress/armors/silver_plate" );
        equip_armor( "/d/knight/fortress/armors/silver_leggings" );
        equip_armor( "/d/knight/fortress/armors/silver_gauntlets" );
        equip_armor( "/d/knight/fortress/armors/silver_shield" );
        equip_armor( "/d/knight/fortress/armors/silver_boots" );
        equip_armor( "/d/knight/fortress/armors/silver_helmet" );
   set( "chat_chance", 12 );
   set( "chat_output", ({
         "楊六郎嘆道: 都沒有學生可以教, 真無聊!\n" }) );
    set( "inquiry", ([
            "楊家槍" : "@@ask_lance",
            "train" : "@@ask_train" ]) );
    set("tactic_func", "special_attack"); 
    set_lessons( ([
                "inner-force" : ({ 200, 50 }),
                "dodge" : ({ 200, 50 })
    ]) );
}

void init()
{
   npc::init();
   teacher::init();
}

void ask_lance( object who )
{
    tell_object( who, 
      "葛雷說: 你來的正好, 這家店的老闆好像正想用人, \n"
      "        你可以問他看看還有沒有(job)。\n" 
    );
}

// 10% use it! damage 40-50.
int special_attack()
{
    object *victim;
    int i;
    if( !(victim = query_attackers()) || (random(10)>1) ) return 0;
    tell_room( environment( this_object() ), 
      "\n楊六郎大喊: 看我的絕招 真空斬! \n"+
      "只見楊六郎把槍一晃，無數條彎月型的光波向所有敵人射去。\n" ,
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(random(10)+40);
      "/d/magic/magic"->report( this_object(), victim[i] );
    }
    return 1;
}
int check_trainee(object who)
{
    if( (string)who->query("class")=="knight" &&
        (int)who->query_level()>18 )
    return 1;
    else return notify_fail(
      "楊六郎說: 我只教夠資格的騎士。\n" );
}
