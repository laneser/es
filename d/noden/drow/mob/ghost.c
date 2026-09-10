
#include <../iigima.h>
inherit MONSTER;

void create()
{
       ::create();
       set_level(19);
       set_name("dynasty ghost","古代幻靈");
       set_short("dynasty ghost","古代幻靈");
       add("id",({"ghost"}));
       set_long(@C_LONG
這是由司娜可女神封印的上古朝代的幽靈，雖然它看來
並不是兇狠的惡靈，但邪惡的司娜可女神在冥界中仍招
喚它過來，意圖佔領這神宮。
C_LONG
       set("unit","位");
       set_natural_weapon(45,26,47);
       set_natural_armor(22,25,14);
       set("max_hp",1080);
       set("hit_points",1080);
       set("alignment",-1600);
       set("tactic","assault");
       set_perm_stat("str",25);
       set_perm_stat("dex",25);
       set_skill("block",100);
       set_skill("dodge",100);
       set("unbleeding",1);
       set("tactic_func","my_tactic");
       set("special_defense",(["all":45,"none":20]));
}
int my_tactic
{
       object *victim;
       if(!(victim=query_attackers())) return 0;
       if(random(20)<5){
        tell_room(environment(this_object()),
        "幻靈口中念著一陣咒語，千萬只惡魔衝向你的四周，狂亂飛舞！！\n"
        ,this_object());
        victim->receive_special_damage("mental",140);
        return 1;
        } else return 0;
}


