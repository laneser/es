/*
 * 原作者：Mercury (1995.1)
 * 修改者：Ishige (1995.12)
 */

#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("Blade Lock","刀鎖");
       add("id",({"lock","blade"}) );
       set_short("刀鎖");
	   set_long(@AAA
這是一把形狀相當奇怪的刀，好像有什麼特殊功用
AAA

	);
	
	set( "unit", "把" );
	set( "second",1);
 	set( "weapon_class", 40 );
        set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 40 );
	set( "weight", 200 );
	set( "value", ({ 200, "gold" }) );
//        set("hit_func","sword_damage");
//        set("special_damage",15);
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_int,dam,n;
    
    if( !victim ) return 0;
    if( (int)victim->query("weapon1") == 0 ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
	if( (my_int/5) < random(25) )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(2) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n你將手上的刀鎖射出，將敵人的武器扣住\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_cap_name")+"將手上的刀鎖射出，將"+victim->query("c_cap_name")+"的武器扣住\n\n",
      holder);
    victim->receive_damage(dam);
    victim->set("last_attacker",holder);
    victim->block_attack(6);
    victim->set_temp("msg_stop_attack",
    "( 你手上的武器被刀鎖釦死了，你無法出手攻擊!! )\n");
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n你手上的刀鎖發出耀眼的光芒飛斬向敵人\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_cap_name")+"手上的刀鎖發出耀眼的光芒飛斬敵人\n\n",
      holder);
      victim->receive_damage(dam+random(15));
      victim->set("last_attacker",holder);
 return dam;
   }
  }
 }
}  
