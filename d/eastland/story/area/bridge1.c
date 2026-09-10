#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("浮橋");
	set_long( @LONG
你站在浮橋上往四周觀望，底下是一溪谷，急湍澎湃，「刷刷」有聲，不知高
度若何，否則大可一遊而盡興。北方的遠處是層巒疊峰，一幕幕的綠布不住地往天
際延伸；抬頭一望，白雲只不過離頭頂數尺高度，好似一條素色的被子，像將要壓
下來。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "hole"}) );
	set( "exits", ([ 
               "east" : SAREA"mountain4",
       	      "south" : SAREA"mountain2",
        ]) );
	set("exit",({"east"}));
	reset();
}
