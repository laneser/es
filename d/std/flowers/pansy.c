#include "flowers.h"
inherit Flowers;
void create()
{
	::create();
	set_name("pansy", "三色堇");
	add ("id",({ "pansy"}));
	set_short("三色堇");
	set_long(
		 "這是一束美麗的三色堇，人們常常用它來表達思念之意。\n"
		 "它的花語是：思念。\n"
		 "這束花上還系著一張小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

