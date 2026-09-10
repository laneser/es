#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("Snow dagger","雪□顏");
    add("id",({"snow","dagger"}) );
    set_short("Snow dagger","雪□顏");
    set_long(@AAA
這是一把雕刻精美的匕首，讓你感覺到這應該是把藝術品而不是武器，而在你
細細觀看這把匕首之時，你彷佛可看見一幅雪國的景色！！！
AAA
       );
    set("unit","把");
    set("second",1);
    set("weapon_class",39);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",33);
    set("weight",90);
    set("value",({120,"gold"}));
//    set("hit_func","snow_damage");
    set("special_msg","  .\n\n");
    set("special_c_msg"," 散發出一陣陣的寒氣 ！！！\n\n"
        "這一陣陣的寒氣凝結出一隻只的冰刃，射入敵人的心臟！！！\n");
}

int snow_damage(object victim,int damage)
{
    object holder;
    int my_kar,dam;
    string c_msg,msg;
    
    dam = 15 + random(20);
    
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        my_kar = (int)holder->query_stat("kar");
        
        if( random(20) > my_kar/5 )
                return 0;
        else {
                msg = (string)query("special_msg");
                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage("cold",dam);
                victim->set("last_attacker", holder );
                if( !c_msg ) c_msg = msg;
                if( !msg ) return 0;
                tell_object( holder, can_read_chinese(holder)?
                        "\n你的"+query("c_name")+c_msg+"\n":
                        "\nYour "+query("name")+msg+"\n" );
                tell_room( environment(holder), 
                        holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
                        holder );
                return dam;
     }
        
}       

