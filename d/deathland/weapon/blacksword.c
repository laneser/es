#include "../echobomber.h"

inherit WEAPON;
int damage_count = 0;
int damage_num = 20;
void create()
{
    set_name("Black Sword", "黑劍" );
    add("id", ({"sword","blacksword",}) );
    set_short("黑劍");
	set_long("@@desc");
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    	set( "type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 35 );
	set( "weight", 100 );
	set( "value", ({ 500, "gold" }) );
   	set("hit_func","sword_damage");
    	set("special_damage",15);
    	set("special_c_msg","呼喚古代的矮人王族靈魂攻擊敵人。\n\n");
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if (damage_num == 0) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	if( random(my_kar*3) < vic_kar*2+5  &&  (damage_count)<=5) {
                if (holder->query("weapon_master")) damage_count++;
		return 0;
	}
        if (!(holder->query("weapon_master"))) damage_num--;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
                victim->receive_special_damage("mental",dam);
		victim->set("last_attacker", holder );
		tell_object( holder, 
                     sprintf("\n你的%s%s\n",query("c_name"),c_msg));
		tell_room( environment(holder), 
                        sprintf("%s的%s%s\n",holder->query("c_name"),query("c_name"),c_msg),
			holder );
		damage_count=0;
		if (damage_num == 0)
			tell_object( holder,"\n黑劍上的黑色光澤漸漸消失了。\n");
		return dam;
	}
	
}	
string desc()
{
if (damage_num == 0)
return ("用銀與米蘇里金屬混合製成的黑劍，但是卻似乎失去了原有的光澤。\n");
else 
return ("用銀與米蘇里金屬混合製成的黑劍，上面有著神秘的黑色光澤。\n");
}

