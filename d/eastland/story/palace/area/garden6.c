#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("八音玲瓏亭");
	set_long( @LONG
玲瓏亭高兩層，每一層都有四面，但一二樓層卻不是吻合的，反而相差四十五
度。此亭通體由紅玉建成，粉壁朱牆，鑲嵌著許多造型各異，花紋多樣的琉璃構件
，八腳攢尖頂，頂上貼滿琉璃瓦，琉瑩生輝，光彩奪目。亭內笙簧交奏，琴瑟叮冬
，絲竹之聲不絕於耳，竟不知從何而來，內中八音，清鏗絕殊天上人間，卻不曉何
物所奏。
LONG
	);
        set("light",1);
        set("exits" , ([
               "out" : SPALACE"garden5",
        ]) );
        set("no_embattle",1);
        set("objects" , ([
              "king" : SPMOB"king1",
          "gardener" : SPMOB"gardener2",
        ]) );
	reset();
}
