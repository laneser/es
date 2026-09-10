#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "golden button", "金釦子" );
        add( "id", ({ "button" }) );
        set_short(  "金釦子" );
        set_long( @C_LONG
這是一顆純金制的扣子，上面刻著一個『李』。
C_LONG
                );
                set("unit","顆");
                set("weight", 5);
                set("value",({1, "silver"}) );
        set("no_sale", 1 );
}
