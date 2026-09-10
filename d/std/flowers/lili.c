#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("lily", "白百合");
	add("id",({"lily"}) );
	set_short("白百合");
	set_long(
		 "這是一支清新高雅的白百合，人們常常用它來象徵純美的少女。\n"
		 "它的花語是：純潔無邪。\n"
		 "這支花上還系著一張小卡片。\n");
	set("unit", "支");
        set ("value", ({ 10, "silver" }) );
}
