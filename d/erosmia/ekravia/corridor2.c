#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("迴廊一角");
	set_long(
@CLong
這裡是走廊的轉角, 一道樓梯 (stairs) 通往樓上的客房。由樓梯走
下來正好面對著一扇窗子 (window), 透過窗戶可以看到外面的大街。
    往南可以回到旅館的大廳。
CLong
);

	set( "c_item_desc", ([
		"stairs"	: @ITEM_STAIRS
你看到一道木頭作的樓梯, 一邊靠著牆壁, 另一邊則有一道扶手, 中間
約有可容兩人並行的寬度。由這道樓梯可以通往樓上的客房, 樓梯下面
的空間則被封起來, 側面開了一道木門 (wooden door)。你想那應該是
一間小儲藏室。 
ITEM_STAIRS
		, "window"	: @ITEM_WINDOW
這是一扇木窗, 可以分兩邊向外推開。窗臺離地面大概一公尺左右, 從
窗戶看出去, 你可以看到外面的大街與街上來往的行人。
你注意到窗子上的鎖似乎被撬壞了。
ITEM_WINDOW
	]) );

	set("exits", ([
		"up"		: HERE"corridor2",
		"south"		: HERE"tavern",
		]));
	set("pre_exit_func", ([
		"up"		: "make_bedroom",
		]) );
}

int		make_bedroom()
{
	object	ob;
	object	bedroom;
	
	ob = present( "copper key", this_player() );
	if (ob && (base_name(ob) == OBJ"tavern_key"))
	{
		printf("%s", "你走上樓, 找到了你的房間, 用老闆給你的鑰匙打開房門。\n");
		bedroom = clone_object( HERE"bedroom" );
		this_player()->move_player(bedroom, "", "up");
		return 1;
	}
	
	ob = present( "silver card", this_player() );
	if (ob && (base_name(ob) == OBJ"silver_card"))
	{
		printf("%s", "你上樓, 走進自己的房間。\n");
		bedroom = clone_object( HERE"bedroom" );
		this_player()->move_player(bedroom, "", "up");
		return 1;
	}
	
	printf("%s", "你還沒訂房間, 上去了也沒有用。\n");
	return 1;
}