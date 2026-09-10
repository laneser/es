#include <mudlib.h>
#include <conditions.h>
inherit WEAPON;

void create()
{
        set_name("Blood sucker","嗜血");
        add ("id", ({"sucker","blood","dagger" }) );
        set_short("嗜血");
        set_long(@LONG
一把通體由不知名血紅色晶體制成的七□長匕首。
LONG
        );
        set("unit","把");
        setup_weapon("dagger",30,1,1);
        set("weight", 70);
        set("wield_func","wield_dagger");
        set("unwield_func","unwield_dagger");
        set("value", ({ 6000, "silver" }) );
        set("hit_func","special");
}
int wield_dagger()
{
   int lv;
   lv=this_player()->query_level();
   set("weapon_class",lv*2);
   set("min_damage",lv+5);
   set("max_damage",lv*2);
   return 1;
}
int unwield_dagger()
{
   set("weapon_class",30);
   set("min_damage",1);
   set("max_damage",1);
   return 1;
}
int special(object victim,int damage)
{
    int my_int,vic_kar,degree;
    string hname,vname;
    object holder,env;
    holder=environment(this_object());
    if ( holder->query("spell_points")<5 )
       return 1;
    env=environment(holder);
    hname=holder->query("c_name");
    vname=victim->query("c_name");
    my_int=holder->query_stat("int");
    vic_kar=victim->query_stat("kar");
    degree=my_int-vic_kar;
    if( random(100) > 20+degree ) return 0;
               
    tell_object(holder,set_color(sprintf("你手中的嗜血開始瘋狂地吸取%s的鮮血！！\n\n\n",vname),"HIR"));
    tell_object(victim,set_color(sprintf("\n%s手中的嗜血開始瘋狂地始吸取你的鮮血！！\n\n",hname),"HIR"));
    tell_room(env,set_color(sprintf("%s手中的嗜血開始吸取%s的鮮血！！\n",hname,vname),"HIR"),
                  ({ victim,holder }) );     
    (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,1);
    holder->receive_healing(25);
    holder->add("spell_points",-5);
    victim->set("last_attacker",holder);
    return 5;
}