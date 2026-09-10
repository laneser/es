#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("書房");
	set_long( 
@C_LONG_DESCRIPTION
這是一個打掃得相當乾淨的書房，四周的傢俱擺設、懸掛的字畫等等，在在都顯示出此
間主人的品味高尚。牆邊的書架上放滿了各種文字的書籍，大多數都是你看不懂的文字。一
陣陣嫋嫋的煙自書桌上的小香爐飄起，淡淡的檀香令你覺得十分舒服。你看到書桌上有一些
七彩的石頭(stones)三三兩兩的放著，似乎有點兒古怪。
C_LONG_DESCRIPTION
	);

	add( "c_item_desc" , ([
		"stones" : @STONE_DESC
當你注視著這些石頭時，感到一陣頭暈目眩而看不清楚。
STONE_DESC
,  
	]) );
	set( "exits", ([ 
		"south" : TOMB"/house2",  ]) );
	set( "objects", ([
		"master" : MOB"/master" ]) );
	reset();	
}

void init() 
{
	object *obj;
	int i;
	
	obj = all_inventory(this_object());
		i = sizeof(obj);
	if( random(7) > 2 ) {
		while( i-- ) {
			if( (int)obj[i]->query("player_invisible") ) 
				obj[i]->set("player_invisible",0); }
		tell_room(this_object(),"桌上的七彩石發出陣陣的波動....\n");
	}
}

int clean_up() {return 0;}