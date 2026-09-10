#include <mudlib.h>
#define HEADQUARTER "/d/eastland/mumar/army_d"
 
inherit MONSTER;
 
void create()
{
        ::create();
        HEADQUARTER->add_member();
}
 
int remove()
{
        HEADQUARTER->remove_member();
	::remove();
	return 1;
}
 
int stop_attack()
{
        HEADQUARTER->add_huntee(this_player());
        return 0;
}
 
void pseudo_hunt(object me, object player)
{
   if( environment() && present(player, environment()) )
       if( this_object()==me )
           tell_room( environment(),
              query("c_cap_name") + "一個不對勁，大叫: 弟兄們!!這個小子八成是間諜，快把他幹掉！\n");
       else {
           tell_room( environment(),
              query("c_cap_name") + "殺到你面前，大喝:「你這個奸細!趕快就縛吧!!」\n" );
       if( !pointerp(attackers) || member_array(player, attackers)==-1)
                               kill_ob(player);
                }
        else if( !pointerp(will_attack) )
                will_attack = ({ player });
        else if( member_array(player, will_attack)==-1 )
                will_attack += ({ player });
}
