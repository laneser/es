#include "irc.h"
#define BOARD "/d/std/IRC/irc_board"

inherit ROOM;

void create()
{
    ::create();
    set("light", 1);
    set_short( "Lobby","大廳" );
    set_long( @LONG
You are in a square shaped, somewhat crude room. There are
four identical archways to the north, west and east directions.
You can hear some noise coming from those.
LONG
	, @C_LONG
這是一間陳設簡單的方形大廳。在南, 北, 東, 西四個方向各有一個
完全相同的拱門。各個房間均隱約傳來人說話的聲音。
C_LONG
    );
    set("exits", ([
    	"north"  : IRC"chatroom_1",
    	"east"   : IRC"deck_3",
    	"south"  : IRC"chatroom_4",
    	"west"   : IRC"chatroom_2",
    ]) );
    BOARD->frog();
}
