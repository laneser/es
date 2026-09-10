#include <mudlib.h>
inherit OBJECT;
void create()
{
	set_name("cage key","竹籠鑰匙");
	add("id",({"key"}));
	set_short("竹籠鑰匙");
	set_long("這是用來開啟竹籠子的鑰匙。\n");
	set("to_lock","WANG");
	set("weight",4);
	set("value",({15,"silver"}));
}

