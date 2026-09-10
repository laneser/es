#include "ruin.h"
inherit ROOM;
inherit DOORS;

void create()
{
	::create();
  set("light",0);
  set_short("深山小徑");
  set_long(@CLong
小徑由東南往西蜿蜒而行, 幽暗的樹林一路上始終掩蓋著頭上的陽光, 
使得這裡格外的神秘。不過附近似乎有塊平臺 (plate), 你想或許可以過去
眺望一下附近的地形, 順便享受一下久違的陽光。
CLong
);
set("exits",([
              "west"		: RUIN"first",
              "southeast"	: RUIN"first",
             ]));

set("item_desc",([
			"plate"	:@C_DESC_1
從這邊看過去那塊平臺似乎不大, 不過進去那裡看看應該有助於弄清
自己現在的所在地。
C_DESC_1
			]) );			
                          
  ::reset();
}

void init()
{
	add_action("enter_plate", "enter");
}

int enter_plate(string s)
{
	if (!s || strcmp(s,"plate")) {
		return notify_fail ( "你想去哪裡?\n" );
	}	
	this_player()->move_player( RUIN"plate", 
	({  "%s走了過來。\n","%s向那塊平臺走去。\n"}) );
	return 1;
}
