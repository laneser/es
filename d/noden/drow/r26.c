#include "iigima.h"

//inherit DOORS;
inherit ROOM;

void create()
{

        ::create();
        set_short( "perotice's room","檀香房");
        set_long(
        @C_LONG
這裡是一間明亮的廂房，四周傳來陣陣的檀香，想必這裡的主人一
定是個深居簡出的人。角落有一面銅鏡，和一些粉彩，好像都是女生的
東西，左邊牆上掛著一幅人像素描，旁邊還放有一張桌子，上頭有一封
拆開來的信，右邊牆上則掛著一個刻有花紋的盾牌。
C_LONG
        );

        set( "light",1 );
        set( "exits", ([
                     "out": DROW"r25",
        ]) );
        set("objects", ([
             "perotice": DRO"knight",
        ]) );
	reset();
}

int clean_up() { return 0; }
           
