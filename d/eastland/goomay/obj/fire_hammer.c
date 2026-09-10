#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire hammer", "火焰之錘" );
	add( "id", ({ "hammer" }) );
	set_short("火焰之錘" );
	set_long(
		"這是一把火紅的巨錘，據說可以發出像火神一樣的威力。\n"
	);
	set( "unit", "把" );
	set( "weight", 250 );
	setup_weapon( "blunt", 45, 25, 45 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);
        set("nosecond",1);

//	set("hit_func","fire_damage");
	set("special_damage",25);
	set("special_c_msg","「嘩啦」的一聲，發出一道火焰，轟擊敵人的身體。\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
     sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
   return 1;
}
int fire_damage(object victim,int damage)
{
    object holder;
    int dam,max;
    string msg,c_msg;


    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    if ( (int)holder->query_skill("blunt")<90 ) {
      tell_object(holder,"火焰之錘「嘩啦」一聲巨響發出一道火焰，卻轟到了你自己。\n\n");
      holder->receive_special_damage("fire",dam+random(20));
      report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
    dam = (int) query("special_damage") ;
	max=random(100);
      if ( max < 20 )  {
                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage( "fire",dam+max );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        "\n你的"+query("c_name")+c_msg+"\n");
                tell_room( environment(holder), 
                        holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
                        holder );
            return dam;
}
      return 0;
}
}
