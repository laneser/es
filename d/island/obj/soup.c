#include "../island.h"

inherit OBJECT;

void create()
{
    set_name("Soup of Shark's Fin","魚翅湯");
    set("id",({"soup","Soup"}) );
    set_short("魚翅湯");
    set_long(@LONG
這是一大碗香噴噴，熱騰騰的清湯！
LONG
             );
    set("unit","大碗");
    set("weight",10);
    set("value",({5,"copper"}) );
}

    