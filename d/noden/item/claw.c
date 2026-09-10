#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silver claw", "銀爪" );
	add( "id", ({ "claw", "cybilas" }) );
   set_short( "賽比拉斯銀爪" );
	set_long(
		"這副銀爪就是傳說中古賽比拉斯人的武器，你可以看到銀爪上鑲著一顆\n"
		"賽比拉斯紅寶石，旁邊圍繞著七顆完美的珍珠。\n"
	);
	set( "unit", "副" );
	set( "type", "unarmed" );
	set( "weapon_class", 36 );
	set( "min_damage", 14 );
	set( "max_damage", 28 );
	set( "second", 1 );
	set( "weight", 70 );
	set( "value", ({ 540, "silver" }) );
	set( "bleeding", 15 );

	set_c_verbs( ({ "用%s往%s一抓", "%s劃出一道漂亮的銀光，掃過%s",
		"的%s發出「嗤」的一聲，往%s劃去" }) );
}
