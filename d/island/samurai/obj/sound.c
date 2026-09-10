#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("sound_raise_sword","音升之劍 ");
    add("id",({"sword"}) );
    set_short("sound_raise_sword","音升之劍 ");
           set_long(@AAA
這是一把含有控制大氣精靈力量的短劍,劍身上刻有著和大氣精靈定契約的法印
AAA
        );
    set("unit","把");
    set("second",1);
    set("weapon_class",40);
    set("type","shortblade");
    set("min_damage",17);
    set("max_damage",40);
    set("weight",150);
    set("value",({120,"gold"}));
//    set("hit_func","sound_damage");
    set("special_c_msg","的音升之劍突然間開始嗡嗡作響 !! \n\n音升之劍的劍身發出一道衝擊波，擊向敵人的要害!!\n\n");
}

int sound_damage(object victim,int damage)
{
    object holder;
    int my_kar,dam;
    string c_msg;
    
    dam = 5 + random(15) ;
    
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        my_kar = (int)holder->query_stat("kar");
        if( random(20) > my_kar/5 )
                return 0;
        else {
                c_msg = (string)query("special_c_msg");
                victim->receive_damage( dam );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        "\n你"+c_msg );
                tell_room( environment(holder), 
                        holder->query("c_name") + c_msg,
                        holder );
                return dam;
     }
        
}       

