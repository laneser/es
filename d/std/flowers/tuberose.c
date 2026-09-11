#include "flowers.h"
inherit Flowers;
void create()
{
	::create();
	set_name("tuberose", "夜來香");
        add ("id",({ "tuberose"}));
	set_short("夜來香");
	set_long(
		 "這是一束芬芳□麗的夜來香。\n"
		 "它的花語是：危險的快樂。\n"
		 "這束花上還系著一張小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

