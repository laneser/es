#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "snake scale dagger","絞鱗匕首");
        add( "id",({ "dagger" }) );
        set_short( "絞鱗匕首");
        set_long(
@C_LONG
這是把由八歧大蛇的蛇鱗所磨製的鋒利匕首，刀刃的部份黝黑而沒
有任何的光澤，是大蛇的鱗片所獨有的特徵，刀柄並刻有蜘蛛圖形
的文字。
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 22);
        set( "type", "dagger" );
        set( "min_damage", 16 );
        set( "max_damage", 24 );
        set( "weight", 50 );
        set( "bleeding", 10);
        set( "value", ({ 710, "silver" }) );
}
