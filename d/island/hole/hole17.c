#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "崗哨" );
	set_long(@LONG
在這個巨大的洞穴中，居然有另一個小洞，洞口邊還放了許多岩石，
哦～～！是了，原來這兒是蜥蜴人的哨站，平時會輪流派人在此駐守以防
止武士堡或魔族的軍隊，或者其他可怕的生物趁機偷襲。	
LONG
		);
	set( "exits",([
			"up" : HOLE"hole16",
			"southwest" : HOLE"hole18"
		]) );
	set( "objects",([
			"guard#2" : HMONSTER"sentry",
			"guard#1" : HMONSTER"sentry"
			]) );
	reset();
#include <replace_room.h>
}
