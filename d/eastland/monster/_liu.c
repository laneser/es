
#include <mudlib.h>
void create(object ob)
{
		if ( !ob ) return ;                                         
        ob->set_level(5);
        ob->set_name( "liu", "劉廣宇" );
        ob->add ("id", ({ "liu",}) );
        ob->set_short( "劉廣宇" );
        ob->set_long(@C_LONG
    這是個年約二十的年輕人，不過神色慌張，好像在怕什麼似的。
從那一雙結實的掌來看，他一定是個掌法高手。
C_LONG
        );
        ob->set( "gender", "male" );

        ob->set_skill( "longblade", 25 );

        ob->set_natural_armor(35,10);
		ob->set_natural_weapon(18,2,7);
		ob->set("special_defence", ([
			"all" : 33 ]) );
					
		ob->wield_weapon("/d/eastland/obj/seven");
}
