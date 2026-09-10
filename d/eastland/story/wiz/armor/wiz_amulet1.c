#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("The Archmaster's amulet","護國師□符□");
        add( "id", ({ "amulet" }) );
        set_short( set_color("護國師□符□","HIY"));
        set_long(@C_LONG
一張不時閃耀著五色祥雲的護符，上面有些彎彎曲曲的蝌蚪型文字。
C_LONG
        );
        set("unit","張");
        set( "type", "misc" );
        set("material","cloth");
        set( "defense_bonus", 8 );
        set( "weight", 5 );
        set("special_defense",
           (["evil":30,"poison":30,"fire":-30,"cold":-30]) );
        set( "value", ({ 5050, "silver" }) );
}



