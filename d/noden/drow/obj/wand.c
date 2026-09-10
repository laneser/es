#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "snake eye wand", "蛇眼石之杖");
        add( "id", ({ "wand" }) );
        set_short( "蛇眼石之杖");
        set_long(
@C_LONG
　　　　這是一把由蛇眼石嵌在杖柄的銅杖，雕刻的手藝細膩而美觀，但是
　　　　奇怪的是，它上面鑲的蛇眼石並沒有散發耀眼的光芒，反而有一種　　
　　　　股深青色的微弱光線隱藏其中。
C_LONG
                );
        set( "unit", "把" );
        set( "type", "wand" );
   set( "weapon_class", 16 );
        set( "min_damage", 9 );
        set( "max_damage", 15 );
        set( "power_on", 1);
        set( "weight", 45 );
        set( "value", ({ 1000, "silver" }) );

        set( "hit_func", "wand_hit" );
        set( "charge_left", 10 );
        set( "max_charge", 10 );
        set( "special_damage_type", "electric" );
        set( "special_damage", 15 );
        set( "special_c_msg", "的蛇眼張開，激射一道電光！");
}
