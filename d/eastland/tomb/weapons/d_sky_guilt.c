#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "Sky Guilt", "『 天罪 』");
        add( "id", ({ "sword", "sky guilt","guilt" }) );
        set_short( "『 天罪 』" );
        set_long(
  "『 天罪 』 -----  一把傳說中的上古神兵。它的外型相當詭異，通體漆黑。劍柄\n"
  "底部雕了一個邪鬼像，邪鬼的眼中不時閃過妖異的光芒，在兩眼上方有個小洞，似\n"
  "忽本來鑲了什麼東西。整支劍身則是由許多小金屬片所組成，當你望向劍身時，一\n"
  "道道的反光就像許多小眼睛般地望入你心靈深處。據說它是魔族三大神兵之一，如\n"
  "今一見果然名不虛傳。\n"
        );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weapon_class", 43 );
        set( "min_damage", 28 );
        set( "max_damage", 45 );
//        set( "bleeding", 25);
        set( "weight", 95 );
//        set( "hit_func", "my_special" );
        set( "special_damage", 10 );
        set( "special_c_msg",
             "劍身突然分解成許多碎片貼到敵人身上，變成通紅後飛回!!\n\n" );
        set( "wield_func", "body_effect" );
        set( "extra_look",
             "一片邪惡的黑霧團團圍繞著$N的身軀。\n" );
        set( "value", ({ 300, "gold" }) );
        set( "no_sale", 1 );
}

int my_special(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    int my_int,vic_int;
    int my_str,vic_str;
    int now_sp, now_hp;
    string c_msg,msg;

    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    my_kar = (int)holder->query_stat("kar");
    vic_kar =(int)victim->query_stat("kar");
    my_int = (int)holder->query_stat("int");
    vic_int =(int)victim->query_stat("int");
    my_str = (int)holder->query_stat("str");
    vic_str =(int)victim->query_stat("str");
    if( random(my_kar *3 +my_int*3)+ my_str < vic_kar+3+vic_int+vic_str) 
       return 0;
    now_sp = (int)holder->query( "spell_points" );
    if( ( now_sp < 7 ) ) return 0;
        else {

                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage( "magic" , dam );
                victim->set("last_attacker", holder );
                now_hp = (int)holder->query( "hit_points" );
                if ( holder->query_temp("NO_DRAIN") ) 
                	now_hp = now_hp + dam + 50;
                else    now_hp = now_hp - dam - 25;
                if ( now_hp > (int)holder->query("max_hp") )
                	now_hp = (int)holder->query("max_hp");
                holder->set("hit_points", now_hp);
                now_sp = now_sp - 7;
                holder->set("spell_points", now_sp);
                if( !c_msg ) return 0;
                tell_object( holder,
                        "\n你的"+query("c_name")+set_color(c_msg,"HIR")+"\n" );
                tell_room( environment(holder), 
                holder->query("c_name") + "的"+query("c_name")+set_color(c_msg,"HIR")+"\n",
                        holder );
                return dam;
     }
}

void body_effect()
{
 object holder;

 holder = environment(this_object());
 tell_object( holder, 
     "\n一陣黑霧忽自邪像口中發出，迅速籠罩著你。\n" );
}

