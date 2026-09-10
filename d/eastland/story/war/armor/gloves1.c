#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wind gloves","風神套");
        add("id",({"gloves"}) );
        set_short("風神套");
	set_long(@C_LONG
一件上繡雲朵的純白色手套，類似用蠶絲編織而成的。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",40 );
	set( "type", "hands" );
        set("material","cloth");
	set( "armor_class", 3 );
	set( "defense_bonus", 2 );
	set( "value", ({ 2000, "silver" }) );
}
