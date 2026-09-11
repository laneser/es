#include "flowers.h"
inherit Flowers;
void create()
{
	::create();
	set_name("laurel", "月桂葉");
	add ("id",({ "laurel"}));
	set_short("月桂葉");
	set_long(
		 "這是一束芬芳的月桂葉。人們常用它來表達堅貞的情感和對英雄的崇敬。\n"
		 "它的花語是：真情至死不渝、最崇拜的英雄。\n"
		 "這束花上還系著一張小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

