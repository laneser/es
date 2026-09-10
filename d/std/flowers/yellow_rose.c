#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("yellow roses", "黃玫瑰");
	add ("id",({ "rose","roses"}));
	set_short("黃玫瑰");
	set_long(
		 "這是一束美麗的黃色玫瑰花，人們常常用它來表達嫉妒的心痛。\n"
		 "它的花語是：嫉妒。\n"
		 "這束花上還系著一張小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

