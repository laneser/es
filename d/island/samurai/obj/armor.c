#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "ninja clothes", "忍者衣");
        add( "id", ({ "ninja","clothes"}) );
        set_short("ninja clothes", "忍者衣");
        set_long(@AAA
一件忍者們穿的防護衣，適用極輕的材質做成的，以方便人的行動，只
是因此也減少了防護力        

        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 16 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 90 );
        set( "value", ({ 760, "silver" }) );
}
