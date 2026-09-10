#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山腰小徑");
	set_long( @LONG
你走在山腰崎嶇小徑上，小徑兩旁有幾本山松山柏，還有些需要三、四人合抱
的參天的古檜，聳立雲端見底不見頭。在天空中不時有飛鳥吭啼或者停駐在那些高
木枝上剔翎刷羽，其神情極為悠閒自在。在地上，幾盆靈花異卉，花朵之大，馥郁
芬香撲鼻，微風吹來，不禁令你神清氣爽為之一□，無身毫不舒暢，格的是化外之
境。 
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
            "swu","nwd" }) );
	set( "exits", ([ 
       	     "southwestup" : SAREA"wiz1",
           "northwestdown" : SAREA"wiz3",
                     "swu" : SAREA"wiz1",
                     "nwd" : SAREA"wiz3"
        ]) );
        set("objects", ([
           "vendor":SMOB"vendor1"
        ]) );
	reset();
}
