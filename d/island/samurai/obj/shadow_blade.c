
#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("shadow Blade","夜影大刀");
       add("id",({"dagger","blade"}) );
       set_short("夜影大刀");
	   set_long(@AAA
這是一把散發出一股邪惡氣息的的刀，雖然名稱是大刀但是卻是
一把短如匕首的武器，真不知為何有此名稱．
AAA

	);
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
        set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 27 );
	set( "weight", 100 );
	set( "value", ({ 130, "gold" }) );
//        set("hit_func","dagger_damage");
        set("special_damage",15);
}

int dagger_damage(object victim,int damage)
{
    object holder;
    int my_int,dam,n;
    
    if( !victim ) return 0;
    if( (int)victim->query("alignment") > -2000 ) return 0;
	my_int = (int)holder->query_stat("int");
	if( (my_int/5) < random(10) )
		return 0;
	else {
		
     tell_object(holder,
     "\n你將手上的夜影大刀感受的你內心中的邪惡氣息，發出一道巨大的刀芒射向敵人\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"臉上浮出一股黑氣，手上的夜影大刀發出一道邪惡的光芒設向"+victim->query("c_name")+"的武器扣住\n\n",
      holder);
    victim->receive_damage(dam);
    victim->set("last_attacker",holder);
    return dam;
 }
}  
