#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "sword of love", "斷掉的還情劍" );
        add( "id", ({ "sword" }) );
        set_short( "斷掉的還情劍" );
        set_long(
                "這是一把通體呈青碧色的劍，你把劍刃向著亮光處一照，竟是半點\n"
                "光澤也沒有。你隱約可以感覺到劍身散發出一種溫和愉悅的感覺，\n"
                "在劍柄近鍔處，你發現刻著一行小字 ： 情絲難斬 斷劍還情。\n"
        );

	set( "unit", "柄" );
	set( "weight", 150 );
	setup_weapon( "longblade", 40, 20, 40 );
	set( "value", ({ 400, "gold" }) );
        set("no_sale",1);

//	set("hit_func","love_damage");
	set("special_damage",10);
    set("special_c_msg","你的還情劍的斷處突然發出光輝，一道青芒直直貫入你的胸膛，\n
你突然想起了過去曾有的溫柔時光，心中一陣劇痛，幾乎連武器也握不住了 .\n\n");
	set("special_c_msg2","%s的還情劍斷處突然發出光輝，一道青芒直直貫入%s的胸膛 .\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
}
int love_damage(object victim,int damage)
{
    object holder;
    int dam,max;
    string c_msg;

    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    if ( (int)holder->query_skill("longblade")<85 ) {
      tell_object(holder,
		  query("special_c_msg"));
      holder->receive_special_damage("mental",dam+random(15));
      report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
    dam = (int) query("special_damage") ;
	max=random(100);
      if ( max < 20 )  {
                c_msg = (string)query("special_c_msg2");
                victim->receive_special_damage( "mental",dam+max );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        sprintf(c_msg,"\n你",victim->query("c_name")));
                tell_room( environment(holder), 
                        sprintf(c_msg,holder->query("c_name"),victim->query("c_name")),
                        holder );
            return dam;
}
      return 0;
}
}
