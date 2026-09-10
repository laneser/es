#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wind cloth","風神衣");
        add("id",({"cloth"}) );
        set_short("風神衣");
	set_long(@C_LONG
一件上繡雲朵的純白色衣服，類似用蠶絲編織而成的，看起來有些透明。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}
