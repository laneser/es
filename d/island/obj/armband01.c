#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("life armband", "懸命之巾");
        add( "id", ({"armband" }) );
        set_short("命懸之巾");
        set_long(@C_LONG
這是錢形次郎每次作案時專門綁在臂上的手巾，「一生懸命」其實就是錢形次郎的寫照。        
C_LONG
        );
        set( "unit", "條");
        set( "type", "arms" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "material","cloth" );
        set( "weight", 20 );
        set( "value", ({ 500 , "silver" }) );
}
