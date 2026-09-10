#include "../echobomber.h"
inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("super lun","萬象無敵法輪");
       add("id",({"lun"}) );
       set_short("萬象無敵法輪");
	   set_long(@C_LONG
勾亦為法器之一種,可以用它來召請九天神佛,此謂之『勾召』... 
如來勾乃如來佛使用的法器,可用來召請五大明王幫忙 
C_LONG
	           );
        set("type","shield");
        set("armor_class",10); 

	
	set( "unit", "座" );
 	set( "weapon_class", 5 );
    set("type","longblade");
	set( "min_damage", 5 );
	set( "max_damage", 6 );
	set( "weight", 120 );
	set( "value", ({ 650, "gold" }) );
//    set("hit_func","sword_damage");
    set("special_damage",2+random(6));
    set("special_c_msg",
"法輪運轉... 天地變色... \n"
"萬象無敵法輪突然射出一道金光!!! \n\n "

);
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	if( random(my_kar*3) < vic_kar*2+5  &&  (damage_count++)<=10)
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_damage( dam );
		victim->set("last_attacker", holder );
		if( !c_msg ) return 0;
		tell_object( holder, 
			"\n你的"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
			holder );
		damage_count=0;
		return dam;
     }
	
}	
