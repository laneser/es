#include <mudlib.h>

void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 2 );
	ob->set_name( "boarman", "野豬人" );
        ob->set_short( "野豬人" );
	ob->set_long(
		"這個....人有著野豬的頭和人類的身體，但是長相實在比半獸人醜，你\n"
		"看了它的臉之後，忽然覺得半獸人並不如一般人心目中醜陋。\n"
	);
	ob->set( "gender", "male" );
	ob->set_perm_stat( "str", 4 );
	ob->set_perm_stat( "con", 3 );
	ob->set( "max_hp", 50 );
	ob->set( "hit_points", 50 );
	ob->set_skill( "blunt", 20 );
	ob->set( "natural_armor_class", 10 );
	ob->set( "wealth/silver", 10 );
	ob->wield_weapon("/d/noden/recamp/obj/club");
}
