#include "mudlib.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("ru-lai rope","如來鎖");
       add("id",({"so","rope",}) );
       set_short("如來鎖");
	   set_long(@C_LONG
鎖亦為法器之一種,可以用它來召請九天神佛,停止敵人的攻擊... 
如來索乃如來佛使用的法器,可用來召請五大明王幫忙 
C_LONG
	);
	
	set( "unit", "捆" );
 	set( "weapon_class", 20 );
        set("type","whip");

        set("second",1);
        set_c_verbs(({ "%s唰的一聲向%s捲去","%s迅速的向%s砸去" 
  
         }));

	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 50 );
	set( "value", ({ 180, "gold" }) );
//    set("hit_func","tie_enemy");
    set("special_damage",1);
    set("special_c_msg",
"向北方一揮,鎖□發出嗡嗡的嘯聲... 頓時天地昏暗了下來... \n"
"五大明王中的馬頭明王被如來鎖召喚出來,捆綁住它的敵人!!! \n\n "

);
}

int tie_enemy(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if( random(18)==7   )
		return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->block_attack(4);
                victim->set_temp("msg_stop_attack", 
                "(你被馬頭明王緊緊困住,無法攻擊)\n");

                  victim->set("last_attacker", holder );
		if( !c_msg ) return 0;
		tell_object( holder, 
			"\n你的"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_cap_name") + "的"+query("c_name")+c_msg+"\n",
			holder );
     }
	
}	
