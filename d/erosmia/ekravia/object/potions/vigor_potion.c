#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "vigor potion", "活力藥水" );
	add( "id", ({ "potion", "vigor" }) );
	set_short( "活力藥水" );
	set_long( @LONG
這是一瓶透明無色的藥水, 藥瓶瓶底的標籤這麼寫著:
「你覺得疲憊不堪嗎? 那麼這瓶奇異的藥水可以使你虛弱的身體立刻恢復
  活力!」
LONG
	);
	set_healing( 5 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 15 );
	set( "value", ({ 500, "silver" }) );
	set( "medication", -90 );
	set( "effect_critical", 0 );
}
