#include <mudlib.h>

void create(object ob)
{
	object ob1;
    if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "farmer's wife", "胖農夫的妻子" );
	ob->add( "id", ({ "farmer", "wife" }) );
   ob->set_short( "胖農夫的妻子" );
	ob->set_long(
		"胖農夫的妻子也一樣很胖....不過他的先生似乎並不這麼認為。\n"
	);
	ob->set( "max_hp", 35 );
	ob->set( "hit_points", 35 );
	ob->set( "race", "human" );
	ob->set( "gender", "female" );
	ob->set( "alignment", 200 );
	ob->set( "wealth/silver", 20 );

	ob1 = new( "/d/noden/item/basket" );
	ob1->move(ob);

	ob->equip_armor("/d/noden/item/skirt");
}
