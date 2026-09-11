#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "涼亭" );
	set_long(
	"這是一座精巧的涼亭，完全由青竹製成，雖然不是說雕樑畫棟，但純樸\n"
	"的裝飾卻更能與自然融為一體，涼亭中央放著一張棋盤(chess)，□殺的正\n"
	"激烈，一名中年文士正專心的研究棋局，完全沒注意到你的到來。\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set( "c_item_desc", (["chess":
        "你看到一張青石所制的圍棋棋盤，上面有一場未決生死的棋局，你的好奇心\n"
        "促使你仔細的看著(behold)這棋局。\n"
        ]));
        set( "exits", ([
                "out" : TROOM"yard2",
        ]) );
        set( "objects",([
                "wuyong" : TMONSTER"wuyong",
        ]));        
        reset();
}
void init()
{
    add_action("do_behold","behold");
}
int recover(object player)
{
player->set_temp("block_command",0);
write (
"經過好久好久，你好不容易恢復神志，決定放下屠刀，金盆洗手，去當巫師去吧:D\n");
return 1;
}  
int do_behold(string arg)
{
if (!arg ||arg !="chess")
return notify_fail(
"看什麼?\n");
write (
"你仔細的看著這棋局，只見死中有活，劫中有劫，錯綜複雜，不知勝敗歸於何方?\n"
"你看的眼花撩亂，冷汗直流...................\n\n\n"
"你又想起你這一生的殺伐罪業，恩怨情仇，突然大喊一聲，昏死在地。\n");
this_player()->set_temp("block_command",1);
this_player()->set_explore("eastland#24");
call_out("recover",40,this_player());
return 1;
}
int clean_up() { return 0; }
