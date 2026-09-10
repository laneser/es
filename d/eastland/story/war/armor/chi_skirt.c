#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's skirt","蚩尤綁腿");
        add("id",({"skirt"}) );
        set_short("蚩尤綁腿");
	set_long(@C_LONG
一件用布料縫製而成的護具，上面沾滿了許多血漬，還有許多五條朱線做一起的符
號，那是蚩尤用來記算每殺五個人的辨別。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",60 );
	set( "type", "legs" );
        set("material","cloth");
	set( "defense_bonus", 1 );
	set( "value", ({ 1000, "silver" }) );
}
