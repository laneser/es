#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("blade of hell", "修羅刀");
	add ("id", ({ "hell","blade" }) );
	set_short( "修羅刀" );
	set_long(@C_LONG
這是達摩院首席虛渡大師最鍾愛的兵器，相傳它原本是某位江洋大盜的兵器，
不知道已經沾染了多少鮮血，最後他被大師感化，於是將這把刀送給大師，大
師也以此刀自戒自勉。
C_LONG
                 );
	set("type", "longblade");
	set("weapon_class", 35);
	set("min_damage", 20);
	set("max_damage", 37);
	set("weight", 200);
	set("value", ({ 755, "silver" }) );
	set("no_sale", 1);
}
