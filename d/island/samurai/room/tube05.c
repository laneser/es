
#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("牆內密室");
	set_long(@AAA
這是一間牆壁內的密室，牆上掛了許多張地圖，你仔細觀看一下發現這
些地圖是這附近區域的戰力分佈圖，看來居住在此的人一定是武士團的重要
人物，不然他不可能擁有著這些機密資料．而其中有一張地圖(map) 看起來
比其他的要來的舊，而且破損很多．	
AAA
	);
        set("light",1);
        set("objects",([
        "kola":MOB"kola"
        ]));
	set( "c_item_desc", ([ 
		"map" : @LONG_TEXT
這張地圖你仔細觀察之後，發現地圖後面還有一個按鈕(button)，似乎可
以按按看(push)
LONG_TEXT
 ]) );
	set("exits",([
	   "out":MR"tube04"
	   ]));
	reset();
}

void init()
{
	add_action( "do_push", "push" );
}

int do_push(string arg)
{
	if( !arg || arg!="button" )
		return notify_fail( "你是在練油壓還是指壓？手指到處亂按！\n" );
	write("你一按按鈕，天花板就開了一個出口，你奮力一跳就跳出這間密室了\n"
		 );
	this_player()->move_player( MR"cac05", "SNEAK" );
	return 1;
}

