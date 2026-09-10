#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("paradise dagger", "仙鶴神針");
        add ("id",({ "dagger",}) );
        set_short("仙鶴神針");
        set_long(
"傳說中天上仙人所用的武器，形狀類似匕首。你可以看到它周圍隱約閃耀著
藍光，相當耀眼。\n"
        );
        set( "unit", "柄" );
        set( "weapon_class", 40 );
        set( "type", "dagger" );
        set( "min_damage", 25 );
        set( "max_damage", 35 );
        set( "weight", 50 );
        set( "no_sale", 1);
        set( "value", ({ 2600, "silver" }) );
        set( "bleeding", 8 );
}
