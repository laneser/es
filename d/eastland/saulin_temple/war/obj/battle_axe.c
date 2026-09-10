
#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("bonze battle axe","銅戰斧");
       add("id",({"axe",}) );
       set_short("銅戰斧");
       set_long(
           "這是一把用來砍樹還差不多的短斧。\n"
        );

        set( "unit", "把" );
        set( "weapon_class", 14 );
	set("type","axe");
        set( "min_damage", 7 );
        set( "max_damage", 14 );
	set( "min_damage", 9 );
        set( "max_damage", 16 );
	set( "weight", 65 );
        set( "value", ({ 30, "gold" }) );
}
