#include "../tsunami.h"

inherit OBJECT;

void create()
{
     set_name("Red Crystal","紅色的小水晶");
     add("id",({"crystal"}) );
     set_short("紅色的小水晶");
     set_long(@LONG
這是魎皇鬼幻化而成的水晶，它不斷地發出喵喵喵的叫聲，加上不斷的泛著紅色
的閃光，使你覺得愛不釋手！
LONG
              );
     set("unit","顆");
     set("weight",10);
     set("no_sale",1);
     set("give_to_sasami",1);
 }