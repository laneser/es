#include "../ekravia.h"

inherit MONSTER;

void create()
{
	object	staff;

	::create();
	set_level(5);
	set_name( "The old Shilator", "老席洛特" );
	add( "id", ({ "man", "shilator" }) );
	set_short( "老席洛特" );
	set_long(@LONG
你看到一個帶著□杖的老人, 他安詳地看著你。他似乎懂得很多事情, 或
許你可以請他幫你解除心中的疑難。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 200 );
	set( "wealth/silver", 100 );
	
	wield_weapon( OBJ"staff" );
}
