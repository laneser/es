
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The squire of the dwarf village","矮人村落的廣場");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村莊的大廣場上,這裡有著非常和平安詳的氣氛,矮人們經常在此地
遊玩及嬉戲.東邊有一個很大的水塘(pool),是矮人飲用水的來源 ,在水塘的中央有一個
飄浮的房子(house),你不能想像為何它能浮在空中而不掉下來 .在這裡似乎有個小小的
門通往地下,但是你無法確定是否有著危險的事物在底下.
CLong
    );
    set("c_item_desc",([
        "pool":"一個大水塘,由於矮人的飲用水取於此地,所以此水塘禁止游泳.\n",
        "house":"一間飄浮的房子,它有著奇怪的力量,當你注視著它的時候,你發現有一\n"
                "奇異的光線從裡面射了出來.\n"
                ]) ); 
    set("exits",([
                "east":Deathland"/village/v34",
                "south":Deathland"/village/v23",
                "down":Deathland"/village/d01",
             ]));
    create_door("down","up",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"一個小小的木門",
               "c_name":"小木門",
               "name":"small wooden door",
               "desc":"a small wooden door",
               ]) );
    ::reset();
}
