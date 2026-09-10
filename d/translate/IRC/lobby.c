#include <irc.h>
#define BOARD "/d/std/IRC/irc_board"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Lobby","大廳" );
    set_long(
@LONG
You are in a square shaped, somewhat crude room. There are two
identical metallic doors to the north and east direction. The post
office is to the west. You can hear some noise coming from the south.
 
LONG
@C_LONG
這是一間陳設簡單的方形大廳. 在北, 東兩個方向各有一個完全相
同的金屬門. 西邊是郵局. 南方的房間隱約傳來人聲.
 
C_LONG
    );
    set("exits", ([
    "north"  : RM+"chatroom_1",
    "east"   : RM+"chatroom_3",
    "south"  : RM+"pub",
    "west"   : RM+"irc_post"
                ]) );
    BOARD->frog();
 
}
 
