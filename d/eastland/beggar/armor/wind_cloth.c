#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind cloth","束雲白袍");
        add("id",({"cloth"}) );
        set_short("束雲白袍");
	set_long(@C_LONG
束雲白袍是由震八方喬峰死去的妻子用天然蠶絲編織而成的,因上面繡有一大片浮雲而
命名的。因為是絲製品,所以對於防火而言總有那麼一點缺陷。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 32 );
	set( "defense_bonus",3 );
	set("special_defense",
	     (["fire":-20,"cold":10]) );
	set( "value", ({ 4800, "silver" }) );
	set("no_sale",1);
}
