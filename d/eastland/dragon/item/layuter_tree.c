
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult tree", "神秘樹" );
        add( "id",({ "tree", "layuter_tree" }) );
        set_short( "神秘樹" );
        set_long(
            "這是一棵會隨著時光的轉換，以五行之術移動的樹。\n"
        );
        set( "unit", "棵");
        set( "weight", 18000 );
        set( "value", ({ 0, "gold" }) );
}
