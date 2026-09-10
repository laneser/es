#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "長長的巖隙" );
	set_long(
	"這是在山間自然生成的巖隙，兩旁緊迫的山璧使你有一種透不過氣的感覺，\n"
	"一條條的鐘乳從你的頭頂垂下，雖然你一方面讚歎大自然的鬼斧神工，另一\n"
	"方面你卻又暗自咒罵它們使你的通行更加困難。再加上地上溼漉漉的，你必\n"
	"須更小心的前進以免滑倒。\n"
	);
        set( "exits", ([
                "southeast" : TROOM"underjail3"
        ]) );
        reset();
}
int clean_up() { return 0; }
