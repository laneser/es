
#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name( "occult club", "神秘棍" );
        add( "id",({ "club" }) );
        set_short( "神秘棍" );
        set_long(
            "這是神秘樹的中心精華，擁有舉世無匹硬度。\n"
        );
        set("layuter_club",1);
        set( "unit", "棵");
        set( "weight", 400 );
        set( "value", ({ 0, "gold" }) );
}
