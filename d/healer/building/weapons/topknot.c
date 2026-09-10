#include <mudlib.h>
inherit WEAPON;
void create()
{
        set_name("phoenix topknot", "鳳頭釵");
        add( "id", ({ "topknot" }) );
        set_short("鳳頭釵");
        set_long(
                "這是刑老爹送給刑老媽的定情之物, 上面有一隻很精緻的鳳凰。\n"
        );
        set("unit","支");
        set( "type", "dagger" );
        set( "weapon_class",35);
        set( "min_damage", 15);
        set( "max_damage",30);
        set( "weight", 30 );
        set( "value", ({ 450, "gold" }) );
}



