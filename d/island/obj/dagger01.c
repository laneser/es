
#include <mudlib.h>
inherit WEAPON;

void create()
{
#include <compress_obj.h>
        set_name( "golden dagger","鑲金扁鑽" );
        add( "id",({ "dagger","daggercheck" }) );
        set_short( "鑲金扁鑽" );
        set_long(@C_LONG
這是錢形次郎專用的扁鑽，聽說錢形次郎每殺一個人，就會在扁鑽上鑲朵
金色的櫻花，現在扁鑽的握柄已經鑲滿金色的花朵，實在太血腥了。       
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 39);
        set( "type", "dagger" );
        set( "min_damage", 27 );
        set( "max_damage", 35 );
        set( "weight", 40 );
        set( "value", ({ 150, "gold" }) );
        set( "second" , 0 );
}

