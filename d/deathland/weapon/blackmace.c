#include "../echobomber.h"

inherit WEAPON;
int damage_num = 20;
void create()
{
        set_name("drain mace","索魂釘頭槌");
        add("id",({"mace",}) );
       set_short("索魂釘頭槌");
	set_long("@@desc");
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    	set("type","blunt");
	set( "min_damage", 10 );
	set( "max_damage", 39 );
	set( "weight", 180 );
	set( "value", ({ 340, "gold" }) );
    	set("hit_func","mace_damage");
    	set("special_damage",13);
    	set("special_c_msg","吸取敵人的生命力.\n\n");
}

int mace_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    int my_int,vic_int;
    string c_msg,msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if (damage_num == 0) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int"); 
	if( random(my_kar*3)+ my_int< vic_kar*2+8+vic_int  )
		return 0;
        if (!holder->query("weapon_master")) damage_num--;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_special_damage( "evil" , dam );
		victim->set("last_attacker", holder );
		tell_object( holder,
                        sprintf("\n你的%s%s\n",query("c_name"),c_msg));
		tell_room( environment(holder), 
                        sprintf("%s的%s%s\n",holder->query("c_name"),query("c_name"),c_msg),
			holder );
		if (damage_num == 0)
			tell_object( holder,"\n索魂釘頭槌上的黑色光澤漸漸消失了。\n");
		return dam;
	}
	
}
string desc()
{
if (damage_num == 0)
return ("由米蘇里與銀混合造成的黑色索魂釘頭槌，但是卻似乎失去了原有的光澤。\n");
else 
return ("由米蘇里與銀混合造成的黑色索魂釘頭槌，上面有著神秘的黑色光澤。\n");
}
