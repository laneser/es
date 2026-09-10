#include "../../story.h"
inherit MONSTER;
inherit "/std/seller";
void create()
{
    ::create();
    set_level(6);
    set_name( "vendor", "路邊小販" );
    set_short( "路邊小販" );
    set_long(@LONG
一個看起來很友善的小販，如果你有需要的話，可以向他購買物品，只要問他價錢
(price)，他就會讓你看他的貨物。除此之外，這裡還販賣「巫咸國」的特產之一
－無底袋，保證讓你滿意。
LONG    
    );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set_inventory( ({
	({ "/obj/bandage", 20, 20 }),
        ({ SWITEM"bag1", 10, 5}), 
        ({ SWITEM"crystal1",45,10 }),
    }) );
    set( "inquiry", ([
	"price" : "@@show_menu"
    ]) );
}
void init()
{
    npc::init();
    seller::init();
}

