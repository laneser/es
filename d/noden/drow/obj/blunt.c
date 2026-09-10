#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("blunt","扁擔");
       add("id",({"blunt",}) );
   set_short("扁擔");
       set_long(
@C_LONG
    這是奴役用來挑貨物的長扁擔。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 9 );
    set("type","blunt");
        set( "min_damage", 6 );
        set( "max_damage", 10 );
        set( "weight", 35 );
        set( "value", ({ 80 , "silver" }) );
}
