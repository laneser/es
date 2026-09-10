// /d/ocean/ocean.c

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "空房間");
	set_long(
		"This is a simple room created by roommaker.\n",
		"這是一個用房間編輯器造出來的空房間。\n"
	);
}
