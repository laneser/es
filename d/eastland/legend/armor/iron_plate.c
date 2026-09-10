#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silver_dragon vest", "銀龍戰甲" );
	add( "id", ({ "vest", "plate" }) );
	set_short( "銀龍戰甲" );
	set_long(@LONG
諸保昆委託東方大陸名鑄造師段鐵幫忙冶□他在苗疆所得到的一塊玄鐵礦，段鐵用
這塊玄鐵礦煉製了數樣防禦力非凡的護具，最後將剩餘的玄鐵製成一片片的鱗片，
嵌入段鐵的一件家傳銀龍甲冑之中，而製成的戰甲，有超凡入聖的防禦力，不過非
常沈重。
LONG	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 35 );
	set( "defense_bonus", 1 );
	set( "weight", 270 );
	set( "value", ({ 2500, "silver" }) );
}
