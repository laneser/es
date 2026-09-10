#include "ekravia.h"
inherit SHOP;

void	create()
{
	::create();
	set_light(1);
	set_short("shop","商店");
	set_long(@Long
這裡是專門賣出與收購各種旅行冒險裝備的雜貨店, 你可以在這裡找
到有名的冒險者們所留下來的裝備。許多傳說中的名劍名鎧都曾在這家商
店出現過, 更有不少的傳奇故事是從這家商店開始的。
Long
);
	set("exits", ([
		"east"		: HERE"maple_street4",
	]));
	set("objects", ([
		"trashcan"	: "/obj/trashcan",
	]) );
	reset();		                                                                        
}
