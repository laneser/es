#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("archmaster's mark","令牌");
        set_short( "令牌");
        set_long(@C_LONG
一個玉做的小巧令牌，上面刻有「護國師　巫真」五個字，擁有這個令牌就可以自
由出入皇宮了。
C_LONG  );      
        set("unit","個");
        set("weight",10);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
