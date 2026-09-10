#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "basket", "藤籃" );
	set_short( "藤籃" );
	set_c_open_long(@C_LONG
這是江南最有名的藤器店--王記 出品的藤籃，籃子本身編得相當精巧，
看來十分耐用, 而且應該能裝不少東西, 是進香客常攜帶裝供品的東西。
C_LONG
 	);
	set( "weight", 15 );
    set( "weight_apply", 60);
	set( "max_load", 300);
	set( "value", ({ 413, "silver" }) );
    set( "prevent_insert",1);
}
