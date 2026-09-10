#include "saulin_monka.c"

void create()
{
	object ob1;
	::create();
	set_level(5);
	set_name( "temple guest", "進香客" );
	add( "id", ({ "guest" }) );
	set_short( "進香客" );
	set_long(@C_LONG
他是一個虔誠的佛教徒，懷抱非常快樂的心情來少林寺進香。
他長的很胖，提著一個大籃子，但笑咪咪的似乎一點都不累...
C_LONG
   	        );
	set( "max_hp", 145 );
	set( "hit_points",145 );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set( "wealth/silver", 10 );
//	set( "speed", 50);
//	set( "forgetful", 1);
//	set( "moving", 1);
	seteuid( getuid() );
	set( "wimpy", 70);
	set_perm_stat("strength",10);
	set_perm_stat("dexterity",10);
	set_perm_stat("piety",10);
	set_natural_weapon( 8, 4, 9 );
	set_natural_armor( 25, 10 );
	set_skill("dodge",50);  
	set_c_verbs( ({ "%s提起籃子，重重的向%s敲了下去",
			"%s大叫一聲，用拳頭向%s打下",  
			"%s一個閃身跑向前來，撞向%s", 
		}) );
	set_c_limbs(({ "光亮的禿頭", "肥肥的身體", "油油的巨手", "粗粗的肥腿"}));
	ob1 = new( SAULIN_OBJ"basket" );
	ob1->move(this_object());
}
/*

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "進香客大叫一聲: 又是 "+who->query("c_name")+" 這強盜來了，快逃命嘍 !\n"
      ,  ({ this_object(), who }) );
    tell_object( who, 
      "進香客大叫一聲: 又是你這個殺人不眨眼的強盜，快逃命嘍 !\n" 
    );
    return 1;
}
*/
