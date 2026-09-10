#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Police Mace","警棍");
    add("id",({"mace"}) );
    set_short("警棍");
    set_long(@LONG
這是根用米蘇里礦和金剛石合成的警用振暴棍.
LONG
             ); 
    set("unit","把");
    set("weapon_class",25);
    set("type","blunt");
    set("min_damage",15);
    set("max_damage",30);
    set("weight",150);
//    set("hit_func","special_atk");
    set("special_damage",2);
    set("value",({400,"silver"}) );
 }
 
 int special_atk(object victim,int dam)
 {
     object holder;
     dam=(int)query("special_damage");

     if( !victim ) return 0;
     if( !(holder=environment(this_object())) || !living(holder) )
     return 0;
     
     if( random(20) > 5 ) return 0;
     tell_object(victim,
     "\n突然警棍發出一陣電擊，你覺得全身上下無法使勁\n\n" );
     tell_room(environment(victim),
     "\n突然警棍發出一陣電擊，只見"+victim->query("c_name")+"立刻癱了下去！\n\n"
     ,victim );
     victim->block_attack(6);
     victim->set("last_attacker",holder);
     victim->receive_damage( dam );
     victim->set_temp("msg_stop_attack",
     "(你全身上下感到疼痛無力，無法出手攻擊！)\n" );
     return dam;
}
