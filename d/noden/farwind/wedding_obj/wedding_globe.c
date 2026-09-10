#include <mudlib.h>
inherit ARMOR;
void create()
{
   set_name( "wedding globe", "結婚護盾圓球" );
	add( "id", ({ "globe" }) );
	set_short( "結婚護盾圓球" );
	set_long(
	"這是一個看起來又圓又可愛小球球,不過重要的是它所代表的意義: \n"
	"永遠不能再結婚.......:p  \n");
	set("prevent_drop",1);
	set("material","element");
	set( "type", "globe" );
	set( "armor_class", 20 );
	set( "defense_bonus", 6 );
	set( "weight", 50 );
   set( "value", ({ 8000, "silver" }) );
}
/*
int query_auto_load()
{
   if( !environment() ) return 1;
   if( environment()->query("spouse") )
        return 1;
   return 0;
}
*/
int stop_equip()
{
        if( !this_player()->query("spouse") ) {
        printf(
               "等你結婚後再戴吧!\n" );
        return 1;
        }
   return 0;
}
