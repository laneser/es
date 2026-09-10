#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Cold jade armor","玄天玉甲");
        add("id",({"armor","jade"}) );
        set_short( "玄天玉甲");
        set_long(
"這是一件深綠色的玉甲，你可以感覺到它透著絲絲的寒意。\n"
        );
        set( "unit", "件" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "armor_class", 37 );
        set( "defense_bonus", 5 );
        set( "value", ({ 320, "gold" }) );
        set( "special_defense", ([ "fire": 10 , "cold":  -10]) );
        set("no_sale",1);
 }

