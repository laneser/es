#include "../dgnisld.h"

inherit OBJECT;

void create()
{
        set_name( "Dragon ball", "龍珠" );
        add( "id", ({ "ball" , "dragon ball" ,}) );
        set_short( "Dragon ball", "龍珠");
        set_long(
            "This is the Dragon ball in old legend. \n",
            "這就是傳說中的龍珠。它散發出微弱的光芒，很像一顆夜明珠。\n"
            "在它裡面隱隱的可以看到六顆小星。\n");
        set("weight", 5 );
        set("prevent_insert",1);
        set("value", ({ 1 , "gold" }) );
        set("dgnball", 1);
        set("unit", "顆");
}           
