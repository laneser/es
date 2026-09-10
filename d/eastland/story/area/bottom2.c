#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("溪谷沙岸");
	set_long( @LONG
你立足之處是一溪谷裡的沙岸，前面溪水從東北打個折，緩緩流向西北而去。
這溪谷兩岸都是千仞高的山峰，除非脅生兩翼、步縱萬尺，否則斷難攀越而過。這
溪谷上方不時有鳥類飛過或時而停在山壁老枯枝上引吭高歌，發出的聲音引起山壁
相互共鳴。你赫然發現地上有根半截的斷技，上面纏著些許白色細線，原來是一釣
根，想必這裡曾經有人留連，而不是個人煙俱滅的地方。
LONG
	);
        set("light",1);
	set( "exits", ([ 
         "northwest" : SAREA"bottom1",
         "northeast" : SAREA"bottom3"
        ]) );
	reset();
}
