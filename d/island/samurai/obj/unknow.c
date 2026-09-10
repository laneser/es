#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("unknow sword","無名劍");
       add("id",({"sword"}) );
       set_short("無名劍");
	   set_long(@AAA
一把爛爛且不起眼的劍，據說曾是一代劍神無名的愛劍
AAA
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 45 );
    set("type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 45 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
//    set("hit_func","staff_damage");
    set("special_damage",5);
}

int staff_damage(object victim,int damage)
{
    object holder;
    int my_int,vic_int,dam,n;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int");
        if( (random(my_int*3) < vic_int*2) && ((damage_count++)<=5))
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(4) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n你使出無名劍法第一是 大漠風暴 ，劍如飛逝的流星一般射向敵人\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"的劍如飛逝的流星一般射向敵人\n\n",
      holder);
    victim->receive_special_damage("magic",dam);
    victim->set("last_attacker",holder);
    damage_count =0;
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n你使出無名劍法第二式 冰城銀雪 ，劍身上泛起朵朵明亮的劍花\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"的劍身上泛起朵朵明亮的劍花刺向敵人\n\n",
      holder);
      victim->receive_special_damage("magic",dam+10);
      victim->set("last_attacker",holder);
      damage_count =0;
 return dam;
   }
 case 2:
   {
      tell_object(holder,
      "\n你使出無名劍法第三式 怒濤驚天 劍身上泛出無數劍氣射向敵人 \n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"的劍身上泛出無數劍氣向敵人射去\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+15);
      damage_count =0;
      return dam;
   }
 case 3:
   {
     
     tell_object(holder,
      "\n你使出無名劍法第四式 毀天滅地 ，你人劍合一向敵人衝去\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"身劍合一整個人向衝敵人了過去\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+20);
      damage_count =0;
   return dam;
   }
  }
 }
}  
