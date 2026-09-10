#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("禪房");
	set_long( @C_LONG_DESCRIPTION
這是一間不算大的房子，房子的北邊放著一張大通鋪，上面整整齊齊的
擺著十幾條棉被，四面的牆壁看起來斑駁不堪，應歷經一段長久的歲月了，
房子雖然老舊但卻一塵不染，由此可知少林僧律己之嚴，此處是小沙彌及知
客僧的房間。   
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
    set("objects",([
	"monka" : SAULIN_MONSTER"little_monk",
	"monkb" : SAULIN_MONSTER"little_monk",
        "monkc" : SAULIN_MONSTER"greet_monk",
        "monkd" : SAULIN_MONSTER"greet_monk",
    ]) );
	set("exits", ([
		"east" : SAULIN"stone_path0",
	]) );
	reset();	
#include <replace_room.h>
}
