#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "eagle bracers", "銀鷹功力護腕" );
	add( "id", ({ "bracers" }) );
	set_short( "銀鷹功力護腕" );
	set_long(@C_LONG
這是鷹爪門的鎮門之寶，相傳它能夠提升一個人的基本內功能力。
它看起來是由某種黑色的絲綢做成的，上面繡著一隻銀色的鷹。
C_LONG
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "no_sale", 1 );
	set( "armor_class", 1 );
	set( "extra_skills", (["inner-force":5]) );
        set("material","cloth");
	set( "weight", 70 );
	set( "value", ({ 1760, "silver" }) );
}
