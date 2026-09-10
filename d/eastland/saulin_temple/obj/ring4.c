#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("ring of cat eye","貓眼石指環");
    add("id",({"ring"}) );
    set_short("貓眼石指環");
	set_long(@C_LONG
貓眼石是一種會隨著陽光變換色彩的寶石, 
用它做成的指環能幫人帶來福氣。
C_LONG
 	        );
	set( "unit", "只" );
	set( "weight", 10 );
        set("material","stone");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "value", ({ 100, "gold" }) );
}
