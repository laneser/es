#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("unknow sword","天羽奇劍");
       add("id",({"sword"}) );
       set_short("天羽奇劍");
	   set_long(@AAA
一把天羽劍派的掌門信物，也是一把上古神兵，據說持有它就可以使出天羽二十四劍
AAA

	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
        set("type","longblade");
//        set("bleeding",10);
	set( "min_damage", 15 );
	set( "max_damage", 35 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
//        set("hit_func","sword_damage");
        set("extra_look","$N拿著一把象徵天羽劍派掌門的劍");
        set("special_damage",5);
        set_c_verbs( ({"的%s劃出一道劍芒斬向%s","揮動%s飛快的向%s連刺三劍",
                       "的%s舞出朵朵的劍花罩向%s","迴轉%s以一個詭異的角度斬向%s"}));
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_int,dam,n;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
        if( (my_int/5) < random(30) )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(5) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n你使出天羽劍法之 長虹貫日 劍如長虹般飛射敵人\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"使出天羽劍法之 長虹貫日 劍如長虹般飛射敵人\n\n",
      holder);
    victim->receive_special_damage("magic",dam+random(15));
    victim->set("last_attacker",holder);
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n你使出天羽劍法之 九弧震日 劍身上泛出詭異的劍芒卷向敵人\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"使出天羽劍法之 九弧震日 劍身上泛出詭異的劍芒卷向敵人\n\n",
      holder);
      victim->receive_special_damage("magic",dam+random(20));
      victim->set("last_attacker",holder);
 return dam;
   }
 case 2:
   {
      tell_object(holder,
      "\n你使出天羽劍法之 血蹤萬里 劍身上泛出無數劍氣射向敵人 \n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"使出天羽劍法之 血蹤萬里 的劍身上泛出無數劍氣向敵人射去\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+random(25));
      return dam;
   }
 case 3:
   {
     
     tell_object(holder,
      "\n你使出天羽劍法之 玉石俱焚 整個人攏罩在劍氣之下射向敵人\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"使出天羽劍法之 玉石俱焚 整個人攏罩在劍氣之下射向敵人\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+random(30));
   return dam;
   }
 case 4:
 {
    tell_object(holder,
    "\n你使出天羽劍法之 三潭印月 劍化為三以三個詭異的角度刺向敵人\n\n");
    tell_room(environment(holder),
    "\n"+holder->query("c_name")+"使出天羽劍法之 三潭印月 劍化為三以三個詭異的角度刺向敵人 \n\n", 
    holder);
    victim->set("last_attcaker",holder);
    victim->receive_special_damage("magic",dam+random(15));
    return dam;
 }   
  }
 }
}  
