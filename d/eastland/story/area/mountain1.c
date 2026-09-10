#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山頂");
	set_long( @LONG
在這山頂北方的遠處是層巒疊峰，好似一幕幕的綠布不住往天際延伸，南邊則
是一斷崖，白茫茫的一片深不見底。頭上的白雲離頂只不過尺許高度，一抹抹如條
素色的被子，像要壓將下來。往西一眺，不遠處有灣白灘，在陽光照射下白星點點
；往北俯視，與對山之間銜接著一個溪流，急湍澎湃，「刷刷」有聲，不知高度若
何，否則大可一遊而盡興。東邊蜿延著崎嶇的山路，西邊的下面是塊山壁，另外在
路旁有塊石碑(stone)。　
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "east" : SAREA"mountain2",
        ]) );
	set("c_item_desc",([
	  "stone":@LONG
石碑上寫著：
　　　　　　仁人君子請愛惜自己的生命，不要輕易往底下的溪谷跳下去( jump down ) 
           ，以免發生危險。　　
LONG	  
	]) );
	reset();
}
void init()
{
   add_action("do_jump","jump");
}	
int do_jump(string arg)
{
    if ( !arg || arg!="down" ) return 0;
    write(@LONG
    
你往北邊的溪谷一跳，身子落下數百丈，迎面的風壓得你喘不過
氣來，令你無法做任何動作．．

LONG
    );
    this_player()->set_temp("block_command",1);
    call_out("back",5,this_player());
    return 1;
}
void back(object player)
{
    write(@LONG

眼看你就要摔的粉身碎骨，忽然，空氣中有一無形的力量把你託
了上去使你安全到達地面絲毫無損！！

LONG
    );    
    player->delete_temp("block_command");
    player->move_player(SAREA"bottom2",({
        "%s往北邊的溪谷一跳。\n",
        "%s從高空中落了下來。\n"}),"");
    return ;
}
