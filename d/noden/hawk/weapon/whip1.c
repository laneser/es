#include <mudlib.h>
#include <daemons.h>
#include <explore.h>

inherit WEAPON;

string C_NAME=("寂然長鞭");
void create()
{
        set_name( "Silent Whip",C_NAME );
        add( "id",({ "whip","silent whip"}) );
        set_short( C_NAME );
        set_long(@LONG
這是長老多年前在東方遊歷時無意間發現到的鞭子，看起來並不起眼
不過好像隱藏了一股神秘的力量，不知道誰能將這股力量發揮出來
LONG
                );
        set( "unit","條" );
        set( "type","whip" );
        set( "weapon_class",35 );
	set( "min_damage",17 );
	set ("max_damage",30 );
        set( "weight",90 );
        set( "value",({ 2300,"silver" }) );
        set( "wield_func","wi_func");
        set( "unwield_func","unwi_func");
}

void wi_func()
{
        int explore,allexp,power;
        explore = (int)this_player()->query_explore_points();
	allexp = (int)EXPLORE_D->query_total_explore();
	power = explore/allexp; // from 0% -- 100%
        set("min_damage",15 + power*10);
        set("max_damage",30 + power*10);
}

void unwi_func()
{
	set( "min_damage",15);
	set("max_damage", 30);
}

