#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "keeper's room", "管家的屋子" );
	set_long(@C_LONG
這裡是管家霍先生的屋子。這裡面沒有什麼貴重的東西,空空洞洞的顯示主人
不怎麼精心於佈置之類的,亦或許是主人本身就很貧窮吧。牆角落裡有幾支零零落
落的酒瓶;有的是空的有的則是半滿的; 對於整個屋子而言顯得有點不太搭調。屋
子裡邊還有一張紡織機, 機上有幾根梭穿插在其中,想必是女主人用的, 不過卻不
見女主人的蹤影。
C_LONG
	);
	set( "light",1);
	set( "exits", ([
                      "out":DBEGGAR"west4.c"
	]) );
        set( "objects",([
                      "keeper":DMONSTER"keeper.c"
        ]) );              
     reset();
}

