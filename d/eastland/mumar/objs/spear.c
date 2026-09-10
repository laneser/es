#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("snake spear", "蛇矛");
        add ("id",({ "spear" }) );
        set_short("蛇矛");
        set_long(
            "一支蛇矛，矛頭像蛇般彎曲，彷佛要吞噬敵人。\n"
        );
        set( "unit", "支" );
        set( "weapon_class", 17 );
        set( "type", "thrusting" );
        set( "min_damage", 8 );
        set( "max_damage", 18 );
        set( "weight", 190 );
        set( "value", ({ 500, "silver" }) );
}
