#include <mudlib.h>
#define MSPECIAL "/u/m/mercury/obj/special";

inherit MSPECIAL 

void create()
{
        set_name( " ", "  ");
        add ("id",({ "dagger"}) );
        set_short( "  ");
        set("unit", "把");
        set_long(
            
            " !!!!\n"
        );
        set( "type","dagger");
        set("weapon_class",30);
        set("min_damage",15);
        set("max_damage",30);
        set("special_attack",(["damage_type" : "cold","main_damage" : 18 ,
                                "random_damage" : 22  ,"hit_rate" : 20 ]) );

//        set("hit_func","special_attack");
        set("wield_func","wield_dagger");
        set("unwield_func","unwield_dagger");
        set( "weight", 100 );
         
   set("c_msg","\n你招演 ***浪子回頭*** 一道冰霧化為龍形向他而去!!\n\n");
   set("c_enemy_msg","\n的玉尺招演 ***浪子回頭*** 你只見一股龍形冰霧向你襲來!!\n\n");
   set("c_fail_msg","\n你的武器噴出一片奇冷的寒氣，卻冰到你自己 ! \n\n");
   set("c_fail_room_msg","的武器噴出一片奇冷的寒氣，卻冰到他自己 ! \n\n");
   }

 int fail_to_use()
 {
      if ( (string)this_player()->query("gender")=="female")
              return 0;
          else
              return 1;
}

void unwield_ferule()
{
 if(query("form"))
        {
        set( "weapon_class", 15 );
        set( "min_damage", 10);
        set( "max_damage", 20);
        tell_room( environment(this_player()), ({
        this_player()->query("c_name")+"的冰寒玉尺光芒退去，變回平凡的銀尺.......\n"
        }), ({this_player()}) );
        tell_object( this_player(),
         "你的冰寒玉尺冷光斂去，變成平凡的銀尺............\n"
                );

        set_name( "silver ferule", "銀戒尺");
        set_short( "silver ferule", "銀戒尺");
        set("form",0);
                return ;
        }
        return ;
}

void wield_ferule()
{
        int pi,iq,i ;

        if ( (string)this_player()->query("class")=="healer")
        {
        pi=this_player()->query_perm_stat("pie");
        iq=this_player()->query_perm_stat("int");
        i = (pi+iq)/2+random(20);
        set("weapon_class",30);
        set("min_damage",15);
        set("max_damage", i );
        tell_room( environment(this_player()), ({
         this_player()->query("c_cap_name")+"的銀戒尺發出一陣光芒，與他的手結合，變成他身體的一部份。\n"
        }), ({this_player()}) );
        tell_object( this_player(),
         "你的戒尺泛出萬丈光芒，變成一把晶瑩剔透的玉尺........。\n"
                );
        set_name( "cold ferule", "冰寒玉尺");
        set_short( "cold gerule", "冰寒玉尺");
        set("form",1);
                return ;
        }
}
 
