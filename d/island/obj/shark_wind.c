#include "../island.h"

inherit OBJECT;

void create()
{
     set_name("Shark's fin","魚翅");
     add("id",({"fin","shark's fin"}) );
     set_short("魚翅");
     set_long(@ALONG
這是大白鯊的鰭，聽說熬成湯後對治療喉疾很有效哦！
ALONG
     );
     set("unit","片");
     set("no_sale",1);
     set("weight",10);
}     