
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The flying room","飄浮之屋");
    set_long(@Long
Long
,@CLong
一間簡簡單單的房屋,但是最奇怪的是它沒有門,四邊的牆壁都是落地窗,除此之外房子
的中間有一張書桌,而書桌的上面擺設著一顆水晶球(crystalball),除此之外並沒有其它的
東西了.
    有一個樓梯通向樓上的一間小房間,似乎是長老的休息室.
CLong
    );
    set("c_item_desc",([
        "crystalball":"一顆神秘的水晶球.\n",
                ]) ); 
    set("exits",([
                "up":Deathland"/village/vr9",
             ]));
    ::reset();
}

void init()
{
     add_action("to_touch","touch");
}

int to_touch(string str)
{
    if (!str|| (str!="crystalball"&&str!="ball")) return 0;
    else 
      {
        write("一股寒意湧上了你的心頭,忽然一陣柔和的光線籠罩著你,你的人忽然被傳送置別處了.\n");
        this_player()->move_player(Deathland"/village/v32",
         ({"%s被傳送走了.\n",
         "%s伴隨著一陣光出現在這裡.\n"}) );
        return 1;  
      }
}  
   
