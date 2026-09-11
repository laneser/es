#include "flowers.h"
inherit Flowers;
void create()
{
	::create();
	set_name("ironweed", "紫苑草");
        add ("id",({ "ironweed"}));
	set_short("紫苑草");
	set_long(
		 "這是一束美麗的紫苑草，人們常常用它來表達對往事的回憶。\n"
		 "它的花語是：回憶點點滴滴。\n"
		 "這束花上還系著一張小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

