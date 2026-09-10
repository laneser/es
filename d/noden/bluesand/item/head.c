// /u/m/mad/parry/head.c

#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name("head", "奧斯塔的人頭");
   set_short("奧斯塔的人頭");
	set_long(
"這是一顆奧斯塔的人頭。\n"
	);
   set("unit", "顆");
   set("weight", 80);
}
