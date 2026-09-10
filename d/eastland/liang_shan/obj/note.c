#include "../takeda.h"

inherit OBJECT;

void create()
{
       set_name("cook note","廚師筆記");
       add("id",({"note"}) );
       set_short("廚師筆記");
	   set_long(
           "這是一本有點發黃的筆記，記載著廚師的烹飪心得...\n"
	);
	
	set( "unit", "本" );
	set( "value", ({ 10, "silver" }) );
}
