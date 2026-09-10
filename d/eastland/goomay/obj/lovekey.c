#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Necklace of love","情關意鎖");
        add("id",({"necklace"}) );
         set_short( "Necklace of love","情關意鎖");
	set_long(
"This is a magic necklace , it is growing and you feel you got a strong mind .\n",
"這是一條系著一把金色鑰匙的項□，這把奇異的鑰匙散發出一種憾人心絃\n"+
"的光芒，看到了它，你覺得在也不□徨了。\n"
	);
	set( "no_sale",1);
	set( "unit", "條" );
	set( "weight", 20 );
        set("material","light_metal");
	set( "type", "misc" );
	set( "armor_class", 0 );
        set( "defense_bonus", 6 );
	set( "value", ({ 200, "gold" }) );
        set("special_defense",(["mental":30, ]));
        set("extra_stats",(["con":-1 ]));

}
