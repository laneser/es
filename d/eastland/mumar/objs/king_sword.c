#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("empire sword", "尚方寶劍");
        add ("id",({ "sword" }) );
        set_short("尚方寶劍");
        set_long(
          "這是一支鑲滿珠寶，用黃金制鞘的寶劍。據說是皇帝御賜給重臣的信物，\n"
          "而擁有這把寶劍的人可以代行皇命，先斬後奏。另外也有傳聞說這把劍是\n"
          "神物，是真是假就不得而知了...\n"
        );
        set( "unit", "把");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 36 );
        set( "weight", 200 );
        set( "value", ({ 5200, "silver" }) );
        set( "hit_func", "weapon_hit" );
        set( "no_sale",1 );
}
 
int weapon_hit( object victim, int damage )
{
    object owner,target;
    int dexx, t_dexx, sp, dam, ali;
 
    owner = environment();
    target = owner->query_attacker();
    dexx = owner->query_stat("dex");
    t_dexx= target->query_stat("dex");
    sp = owner->query("spell_points");
    ali = owner->query("alignment");
    if (ali < 0) dam = 1;
    if (ali > 50000) dam = (dexx - t_dexx) * 5 ;
    else dam = (dexx - t_dexx) * ali/10000;
    if (dam>28) dam =28;
    if( random(10)>6 && sp > 6 && (dexx-t_dexx)>3 ) {
       tell_object( owner,set_color(
         "\n你手中的尚方寶劍劇烈地震動，同時一道潔淨無瑕的銀白色強光，划向敵人的要害。\n\n","HIW") );
       tell_room( environment(owner),
         set_color(owner->query("c_name") + "敏捷的身形一轉，手中寶劍散射出一道潔淨無瑕的銀白色的強光，直劈敵人的要害。\n\n","HIW")
         ,owner);
       victim->receive_special_damage( "divine", dam );
       owner->add( "spell_points", -6);
       return dam;
     }
}
