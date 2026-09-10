#include "../asterism.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("Black Sword","黑劍");
       add("id",({"sword","blacksword",}) );
       set_short("黑劍");
       set_long(
           "用銀與米蘇里金屬混合製成的黑劍,向來是矮人王的佩劍。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    set("type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 35 );
	set( "weight", 100 );
	set( "value", ({ 500, "gold" }) );
    set("hit_func","sword_damage");
    set("special_damage",15);
    set("special_c_msg","呼喚古代的矮人王族靈魂攻擊敵人.\n");
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg,msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	if( random(my_kar*3) < vic_kar*2+5  &&  (damage_count++)<=10)
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		msg = (string)query("special_msg");
		c_msg = (string)query("special_c_msg");
		victim->receive_damage( dam );
		victim->set("last_attacker", holder );
		if( !c_msg ) c_msg = msg;
		if( !msg ) return 0;
           tell_object( holder,
                   "\n你的"+query("c_name")+c_msg+"\n" );
           tell_room( environment(holder), 
              holder->query("c_cap_name") + "的"+query("c_name")+c_msg+"\n",
			holder );
		damage_count=0;
		return dam;
     }
	
}	
