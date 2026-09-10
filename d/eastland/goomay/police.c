#include "goomay.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "捕房" );
        set_long(
@LONG
這裡是捕快們休息辦案的地方，本鎮由於常有幫派人物出入，所以捕快也就
特別多，並且只要到了每年比武大賽，為了保護皇上，更會由各地抽調人手來幫
忙，所以捕頭的責任就更加重了。不過現任的古梅鎮總捕頭是人稱「追魂尺」的
段飛鷹，他一向主張嚴刑逼供，在他眼下，你最好還是乖乖的做良民吧。
LONG
        );
        
        set( "exits", ([ 
                "east" : Goomay"jail",
		"west" : Goomay"office",
        ]) );
        set( "objects", ([
                "master" : Mob"chief_cop",
        ]) );

      create_door("east","west",
            ([  "keyword" : ({"gate"}),
                "name"    : "Iron gate",
                "c_name"  : "鐵柵門",
                "c_desc"  : "這是一扇有著粗大鐵欄的鐵柵門",
                "status"  : "locked",
		"lock"    : "JAIL_DOOR",
                ]) );


        reset();
}

