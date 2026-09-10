#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "break jade", "碎玉佩" );
        add( "id", ({ "jade" }) );
        set_short( "碎玉佩" );
        set_long( @C_LONG
這是一塊上好的翠玉，不過似乎並不是完整的一整塊。上面用篆字刻著一個『罪』字。
C_LONG
                );
        set("unit","塊");
        set("weight", 10);
        set("sky_guilt_jade2",1);
        set("value",({10, "silver"}) );
        set("no_sale", 1 );
}
