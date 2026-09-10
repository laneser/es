/*
 * 原作者：Mercury (1995.1)
 * 修改者：Ishige (1995.12)
 */

#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("Thunder Sword","雷神劍");
       add("id",({"sword"}) );
       set_short("雷神劍");
	   set_long(@AAA
這是一把擁有控制雷電力量的神劍，其威力之大據說可以劈開一座高山！
AAA

	);
	
	set( "unit", "把" );
	set( "second",1);
 	set( "weapon_class", 42 );
        set("type","longblade");
	set( "min_damage", 17 );
	set( "max_damage", 42 );
	set( "weight", 150 );
	set( "value", ({ 200, "gold" }) );
//        set("hit_func","sword_damage");
        set("special_damage",20);
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_int,dam;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
	if( (my_int/5) < random(25) )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
     tell_object(holder,
     "\n你手上的雷神劍聚集起一股巨大的雷電擊向敵人\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"手上的雷神劍發出一道巨大的雷電擊向"+victim->query("c_name")+"\n\n",
      holder);
    victim->receive_special_damage("electric",dam);
    victim->set("last_attacker",holder);
    return dam;
 }
}  
