#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "icy sword", "玄冰劍" );
	add( "id", ({ "sword" }) );
	set_short( "an icy sword", "玄冰劍" );
	set_long(
		"You see a shortsword made by ice crystal  .\n",
	"這是一把傳說中的奇劍－玄冰劍，通體透明的劍身據說是由萬年玄冰\n"+
	"經過自然強風長年吹襲而成，因而能攻敵不備、無堅不摧，不過，傳\n"+
	"說玄冰劍會自擇其主，如果能得到天時地利人和的配合，會有不可思\n"+
	"議的事情發生。\n"
	);
	set( "unit", "柄" );
	set( "weight", 150 );
	setup_weapon( "shortblade", 30, 15, 30 );
	set( "value", ({ 300, "gold" }) );
        set("no_sale",1);
}
