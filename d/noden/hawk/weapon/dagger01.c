
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "golden dagger","鍍金扁鑽" );
        add( "id",({ "dagger","daggercheck" }) );
        set_short( "鍍金扁鑽" );
        set_long(@C_LONG
這是錢形次郎專用的扁鑽，聽說錢形次郎每殺一個人，就會在扁鑽上鑲朵
金色的櫻花，現在扁鑽的握柄已經鑲滿金色的花朵，實在太血腥了。不過
自從錢形次郎退出江湖以後，這把扁鑽就久不現江湖，想不到在今天又被
你給碰上了............仔細一看，上面的金色花朵竟然是假的
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 30);
        set( "type", "dagger" );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
        set( "weight", 40 );
        set( "value", ({ 150, "gold" }) );
        set( "second" , 0 );
}

