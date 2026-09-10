#include "nodania.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create();
	set_short( "王記商行" );
	set_long(@CLONG
你現在正站在一間充滿東方風味的的商店中，這家店據說是當年
那位第一個踏上諾頓王國土地的東方人開的，店主人王富就是他的後
代。這家店現在已經是諾達尼亞城中牌子最老，信譽卓著的老字號了
，你在這裡絕對不必擔心被騙或買到次級品。
CLONG
	);
	set( "light", 1);
	set( "exits", ([
		"east" : NODANIA"nodania_r1"
	]) );
	set( "objects", ([ "trashcan": "/obj/trashcan" ]) );
	storeroom()->set( "objects", ([
		"bag#1" : "/obj/bag" ]) );
	replace_program(SHOP);
}
