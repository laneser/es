#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("手術室");
	set_long(@C_LONG_DESCRIPTION
這裡是行醫者公會最自豪的地方, 因為有許多行醫者就在這裡, 將其他玩
家從鬼門關拉了回來, 你在這裡看到有最先進的手術檯, 無影燈, 旁邊的櫃子
裡整齊的放著手術刀、止血鉗等手術必備工具及應用藥品, 如果能在這裡動手
術,相信成功的機會一定比在野外要高的多了。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );

	set( "exits", ([ 
		"north" : "/d/healer/building/healer_guild" 
		]) );
	set( "op_room",1);	
	reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_sneak", "sneak");
}

int do_search()
{
    write("牆角似乎有個狗洞，可以鑽 (sneak) 過去。\n");
    return 1;
}

int do_sneak()
{
    if (this_player()->query("class") != "healer" || this_player()->query("alignment") > 0)
        return notify_fail("突然有個在你耳邊迴繞著：好不害臊的大膽小賊！\n");

    write("你鑽過狗洞，進入行醫者書房。\n");
    this_player()->move("/d/healer/building/healer_troom");
    return 1;
}
