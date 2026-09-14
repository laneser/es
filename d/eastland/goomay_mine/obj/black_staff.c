
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( " balck staff", "黑山神杖");
        add ("id",({ "staff" }) );
        set_short("a black staff", "黑山神杖");
        set_long(@AA
這是段鐵為酒境守衛所打造的武器，雖然它並不鋒利而且沒有魔法的特殊攻擊
但由於是摻有些許魔法磁鐵礦的精華，加以淬煉而成的武器，故堅硬異常是不
錯的攻擊武器．
AA
);
        set( "weapon_class", 30 );
        set( "min_damage", 15);
        set( "unit","把");
        set( "max_damage", 26);
        set( "type", "blunt");
        set( "weight", 130 );
        set( "value", ({ 400, "silver" }) );
        }