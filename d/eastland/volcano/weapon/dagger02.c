#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith dagger", "矮靈之匕" );
	add( "id", ({ "dagger" }) );
	set_short( "矮靈之匕" );
	set_long(
		"這是一把矮靈之匕，上面沾滿了血跡，而且有一種無法形容的魔力。\n"
	);
	set( "unit", "把" );
	set( "weight", 40 );
	setup_weapon( "dagger", 35, 19, 33 );
	set( "value", ({ 1500, "silver" }) );
        set( "second", 1 );
//	set("hit_func","evil_damage");
	set("special_damage",8);
	set("special_msg","射出一道血光，刺入敵人的靈魂。\n");
}

int evil_damage(object victim,int damage)
{
    object holder;
    int my_ali,vic_ali,dam,max;
    string msg;

    holder=environment(this_object());
    my_ali =(int) holder ->query("alignment");
    vic_ali= (int) victim->query("alignment");
    dam = (int) query("special_damage") ;
    if ( my_ali > vic_ali &&  my_ali > -3000 ) {
      tell_object(holder,"矮靈之匕射出一道血光，卻傷到了你自己。\n\n");
      holder->receive_special_damage("evil",dam+random(20));
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
      max= my_ali > 0 ? 0 :(my_ali<-2000 ? 35 :(my_ali)/-100  ) ;
      if ( random(35-max) < 5 )  {
        msg = (string)query("special_msg");
        msg = (string)query("special_msg");
        victim->receive_special_damage( "evil",dam );
        victim->set("last_attacker", holder );
        if( !msg ) return 0;
        tell_object( holder,
           "\n你的"+query("c_name")+msg+"\n");
        tell_room( environment(holder),
           holder->query("c_name") + "的"+query("c_name")+msg+"\n",
           holder );
        if ( vic_ali < 0 )
            return dam;
        else
            return dam+random(max/3);
      }
      return 0;
    }
}
