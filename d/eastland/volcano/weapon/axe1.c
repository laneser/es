#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("Huge Axe","巨靈斧");
       add("id",({"axe",}) );
       set_short("巨靈斧");
       set_long(
           "左護衛－左青城用的一把斧頭\n"
     	);
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 45 );
        set("type","axe");
        set("bleeding",8);
	set( "min_damage", 28 );
	set( "max_damage", 40 );
	set( "weight", 210 );
	set( "value", ({ 300, "gold" }) );
//	set("hit_func","axe_damage");
        set("special_damage",20);
        set("special_msg","揮出一道破空氣流直刺入敵人的防禦中心.\n");
}

int axe_damage(object victim,int damage)
{
    object holder;
    int my_pie,vic_pie,dam;
    string c_msg,msg;
    
        if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_pie = (int)holder->query_stat("pie");
	vic_pie =(int)victim->query_stat("pie");
	if( random(my_pie*3) < vic_pie*2 ) return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
        if ((int)holder->query_skill("axe")<80) {
          tell_object(holder,
              "\n你勉強揮動的巨靈斧所產生的氣流不小心傷到了自己.\n\n");
          tell_room(environment(holder),
              "\n"+holder->query("c_name")+"的巨靈斧所產生的氣流不小心傷到了自己.\n\n",
              holder );
          holder->receive_damage(dam);
          return dam;
        }
	msg = (string)query("special_msg");
	victim->receive_damage( dam );
	victim->set("last_attacker", holder );
	if( !c_msg ) c_msg = msg;
	if( !msg ) return 0;
	tell_object( holder, 
		"\n你的"+query("c_name")+c_msg+"\n");
	tell_room( environment(holder),
	holder->query("c_name") + "的"+query("c_name")+msg+"\n",
		holder );
	return dam;
	
}	

