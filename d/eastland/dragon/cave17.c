
#include "../layuter.h"

inherit ROOM;
int knife_control;
  
void create()
{
	::create();
	set_short("地下城");
	set_long( @C_LONG_DESCRIPTION
此處是一個古老的地下城房間，此處的牆壁及地板都是以大理石鋪設成的同時牆上正
有幾隻火把燃燒著，這個房間裡面到處堆滿了許多的竹簡書，以及一張上面擺滿奇怪道具
的桌子，看起來像是一座祭壇，屋子的東側有一個櫃子，上面擺著一些動物的頭骨以及其
裝著看去似蜥蜴類小動物□體的罐子，北側則有一個龍形巨神像，無論以前有多豐富的旅
行經驗，當你初次見到這房間時，都不免有驚怖的感覺。
C_LONG_DESCRIPTION
	);
	set("item_desc",([
	    "table":"這是一個擺滿各式各樣奇特東西的桌子,它的物品中有一樣發出奇特的光芒\n"])); 
	set( "light", 1 );
	set( "exits", ([
		"south" : Lcave"cave15"
	]) );
	set("objects",([
	    "flamen" : Ldmonster"flamen"])); 
	reset();
}

void init()
{
 add_action("do_search","search");
 }
void reset()
{
	::reset();
	knife_control=1;
}

int do_search(string arg)
{
	object obj;

	if( !arg || arg!="table" )
		return notify_fail( 
		"你在這裡中找來找去，但並沒有找到任何奇特的東西。\n"
		);
	if( knife_control ) {
		write( 
			"你仔細搜索桌子，結果找到一把奇特的鏟子。\n"
		);
		obj = new(Lditem"shovel");
		obj->move(this_object());
                this_player()->set_explore("eastland#2");
		knife_control = 0;
		return 1;
	} else {
		write( 
			"你把整個桌子都翻遍了，但沒有發現任何奇特的東西。\n"
		);
		return 1;
	}
}
