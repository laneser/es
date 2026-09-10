#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("Valor Amulet", "勇氣徽章");
        add( "id", ({ "valor amulet","amulet" }) );
        set_short( "勇氣徽章" );
        set("long","這是一個精美的小徽章，上面刻了一顆小小的心。\n");
        set( "weight", 5 );
/*	 set( "prevent_drop", 1);
	 set( "prevent_insert", 1);	*/
        set( "unit", "枚" );
}

