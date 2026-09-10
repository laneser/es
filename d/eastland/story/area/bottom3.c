#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("溪谷沙岸");
	set_long( @LONG
你立足之處是一溪谷裡的沙岸，前面溪水緩緩從東北流向西南而去。這溪谷兩
岸都是千仞高的山峰，除非脅生兩翼、步縱萬尺，否則斷難攀越而過。這溪谷上方
不時有鳥類飛過或時而停在山壁老枯枝上引吭高歌，發出的聲音引起山壁相互共鳴
。東北處有塊大石，大石一半底下長滿了青苔，地上有些風乾了的魚餌，並非是個
人煙俱滅的地方。
LONG
	);
        set("light",1);
	set( "exits", ([ 
          "southwest" : SAREA"bottom2"
        ]) );
        set("objects", ([
             "fisher" : SMOB"fisher1"
        ]) );
	reset();
}
void init()
{
    add_action("do_up","神恩如海天威如嶽繫系矩忙羅");
}
int do_up(string arg)
{
    object player;
    player=this_player();
    write("\n忽然，從你腳底下颳起一陣風把你吹了上去，旋即把你亂丟！\n\n");
    tell_room(this_object(),sprintf(
      "\n忽然一陣怪異的風把%s往上吹去！\n",player->query("c_name")),player);
    player->move_player(SAREA"stone1","SNEAK");
    return 1;
}
