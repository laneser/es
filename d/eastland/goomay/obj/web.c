#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name("Love web","柔絲情網");
        add( "id", ({ "cloak","web" }) );
        set_short("a Love web", "柔絲情網");
        set_long(
 "這是一件散發出晶瑩光芒的披肩，就像是一面用世上所有少年男女對愛情
的美麗憧憬所編織成的網。 \n"
        );
        set("no_sell",1);
        set("unit","面");
        set( "type", "cloak" );
        set("material","element");
        set( "armor_class", 2 );
        set( "defense_bonus", 9 );
        set( "weight", 70 );
        
        set( "value", ({ 1400, "silver" }) );
}
