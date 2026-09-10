#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "claw of sigh", "嘆息之爪" );
	add( "id", ({ "claw", "claws" }) );
	set_short( "嘆息之爪" );
	set_long(@C_LONG
這是一雙非常美麗的爪子，爪身是由不知名的銀白色金屬製成
從不同的角度反射出炫麗的色彩，在護手的地方，鑲滿了美麗
的綠寶石，美的令人屏息，難怪製造它的人將它命名為嘆息之
爪。不光是為它的美麗嘆息，窮人更為它的價值而嘆息。	
C_LONG
	);
	set( "unit", "副" );
	set( "type", "unarmed" );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 43 );
	set( "second", 1 );
	set( "weight", 50 );
	set( "value", ({ 15420, "silver" }) );
	set( "bleeding", 17 );

	set_c_verbs( ({ "用%s往%s一抓","一個轉身，手中%s往%s一畫",
	        "%s劃出一道漂亮的銀光，掃過%s", 
		"的%s發出一聲好像嘆氣的聲音，往%s劃去" }) );
}
