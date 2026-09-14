#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("小型殿堂");
	set_long( @LONG
地面是整片黃金製成的，除卻東北出口外，其餘皆被瓊閣所包圍，彼此交相掩
映，壯麗非常。殿堂內陳設皆是精金美玉，珠翠珊瑚所制，富麗堂皇；四角落矗立
著四根巨大玉柱，美侖美奐，上面雕工精緻，刻畫之物活脫活現；柱頂各盞琉璃天
燈，旋轉丈許晶瑩白光，照耀滿堂通明。殿內之事，窮極美工富麗之限，令人嘆為
觀止，直所未睹。
LONG
	);
        set("light",1);
        set("exits" , ([
           "northeast" : SPALACE"x3",
        ]) );
	reset();
}
