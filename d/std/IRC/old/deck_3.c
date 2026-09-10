#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Cliff","懸崖邊" );
    set_long(
"You are standing on top of a cliff. One more step will take\n"+
"you to the deep darkness below. However you are quiet safe here,\n"+
"as long as you don't jump over to it. You noticed there is a bolt\n"+
"pinned near the edge.\n",
"你站在懸崖頂上, 往下看去是一片漆黑, 不知道有多深? 但只要你不\n"+
"靠近邊緣或自己跳下去, 這個位置實在是風景最棒的地方. 你注意到邊緣\n"+
"釘著一根鋼釘(bolt)。\n"
    );
    set("exits", ([ "west" : IRC"lobby", ]) );
	set("item_desc",([
    	"bolt": "A bolt with a rope tide to it.\n\n",
    ]) );
    set("c_item_desc",([
    	"bolt": "一根綁著繩子的鋼釘。\n\n",
    ]) );
    set("busy",0);
}
 
void init()
{
    add_action("jump_down","jump");
}
 
int jump_down(string str)
{
	int i;
	if( !str || str!="down" ) return 0;
	if( query("busy") ) {
      write( can_read_chinese()?
        "有人在用繩子.. 等會再跳吧? 除非你想去死!\n" :
        "Someone is hanging down there, wait for your turn.\n" );
      return 1;
    }
    set("busy",1);
    write(can_read_chinese()?
        "你拾起繩子將之綁在腰間, 縱身往下跳。\n":
        "You pick up the rope and tide to yourself, then jump down.\n");
	tell_room(environment(this_player()),({
	  this_player()->query("cap_name")+" tides the rope and jump over the cliff\n",
	  this_player()->query("c_cap_name")+"拾起繩子將自己綁住, 然後縱身往下一跳。\n"
	  }),this_player()
	);
	this_player()->move_player(IRC"midair.c","SNEAK");
	return 1;
}
