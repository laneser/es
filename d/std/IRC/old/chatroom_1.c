#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Chatroom","聊天室" );
    set_long( @LONG
You are in yet another squared room. This place is barely
decorated. However, it looks very comfortable.
LONG
    ,@C_LONG
這是一間陳設簡單的方形房間, 雖然設備簡單, 看起來卻也滿
舒服的。
C_LONG
    );
    set("exits", ([ "south" : IRC"lobby", ]) );
}
