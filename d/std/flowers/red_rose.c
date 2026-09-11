#include "flowers.h"
inherit Flowers;
void create()
{
	::create();
	set_name("red roses", "紅玫瑰");
        add ("id",({ "rose","roses"}));
	set_short("紅玫瑰");
	set_long(
		 "這是一束美麗的紅色玫瑰，人們常常用它來表達愛情。\n"
		 "它的花語是：熱愛。\n"
		 "這束花上還系著一張小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

