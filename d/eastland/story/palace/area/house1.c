#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("水晶殿堂");
	set_long( @LONG
這是一座通體水晶建成的小型殿堂，除卻東南出口，其餘皆被瓊閣所包圍，彼
此交相掩映，一派壯麗非常。殿堂內陳設皆是精金美玉，珠光寶氣，富麗堂皇；四
角落矗立著四根巨大玉柱，美侖美奐，上面雕工精緻，刻畫之物活脫活現；柱頂各
盞琉璃天燈，旋轉丈許晶瑩白光，照耀滿堂通明。大祗殿內之事，窮極美工富麗之
限，令人歎為觀止，從所未睹。
LONG
	);
        set("light",1);
        set("exits" , ([
           "southeast" : SPALACE"x1",
        ]) );
        set("pre_exit_func",([
           "southeast":"can_pass"]));
        set("objects" , ([
           "northgod" : SPMOB"northgod",
        ]) );
	reset();
}
int can_pass()
{
    if ( !query("cast") ) return 0;
    if ( !this_player()->query_attacker() ) return 0;
    write("漫天冰雪阻擋了你的去路！！\n");
    return 1;
}
