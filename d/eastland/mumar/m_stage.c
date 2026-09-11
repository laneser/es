#include "mumar.h"
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("鏡中的收藏室");
  set_long( @CLong
進入鏡內，你看不見原本應該反映在鏡中的珠寶、瓷器、珍奇古玩。鏡外那個奢
華的房間在這兒竟是家徒四壁，就好像剛被強盜洗劫過一樣，除了一面破舊而不起眼
的鏡子外只有一些空箱子、空架子了。
CLong
);
set("light",1);
set("c_item_desc",([
    "mirror":"@@to_mirror"
     ]) );
 
set("exits",([
               "down":MUMAR"m_square"
             ]));
}
 
void init()
{
    add_action("to_touch","touch");
    if(this_player()) this_player()->set_explore("eastland#25");
}
 
int to_touch(string arg)
{
   if( !arg || arg != "mirror" ) return 0;
   else  {
        write("在你摸著鏡子的同時，你感到一股強大的吸引力把你拉進了鏡內。\n");
        this_player()->move_player(MUMAR"stage07",({
        "",this_player()->query("c_short")+"被吸入了鏡子\n。",
        "",this_player()->query("c_short")+"進入了這個世界。\n",
        }),"");
        }
   return 1;
}
 
string to_mirror()
{
   return "這面鏡子閃耀著一種奇異的光芒，深深地吸引著你去摸它。\n";
}
