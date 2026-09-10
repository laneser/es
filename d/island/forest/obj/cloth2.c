#include "../tsunami.h"

inherit ARMOR;

void create()
{
     set_name("Practice cloth","武道服");
     add("id",({"cloth"}) );
     set_short("武道服");
     set_long(@LONG
這是普通的武道服，一般練武術的人都會著這種服裝來練武！
LONG
             );
     set("unit","件");
     set("type","body");
     set("material","cloth");
     set("armor_class",10);
     set("defense_bonus",0);
     set("weight",100);
     set("value",({50,"silver"}) );
 }
