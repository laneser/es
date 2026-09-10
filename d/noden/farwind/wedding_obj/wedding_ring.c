#include <mudlib.h>
inherit ARMOR;
void create()
{
	set_name( "wedding ring", "結婚戒指" );
	add( "id", ({ "ring" }) );
   	set_short( "結婚戒指" );
	set_long(
	"這是一個燦爛美麗的鑽石戒指，不過更美麗的是它所代表的意義: 永恆\n"
	"不變的愛情。\n");
	set("prevent_drop",1);
	set("no_sale",1);
        set("material","cloth") ;
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
   	set( "weight", 8 );
   	set( "value", ({ 5000, "silver" }) );
}

int query_auto_load()
{
	if ( !environment() ) return 1;
// change by Ruby ... can't use this_player() at here ..
// 	because no this_player() while logind checking auto_load
	if( environment()->query("spouse") )
        	return 1;
	return 0;
}

int stop_equip()
{
        if( !this_player()->query("spouse") ) {
	        printf("等你結婚後再戴吧!\n" );
	        return 1;
	}
	return 0;
}
