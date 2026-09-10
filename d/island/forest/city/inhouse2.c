#include "../tsunami.h"

//inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("正殿");
    set_long(@LONG
這兒是正殿，也是遙照天皇平時聽取國政，處理朝綱的地方。只見一張
坐墊放在前方稍高的臺階中央，兩旁的牆上掛著幾張山水畫，倒像是魔族全
境的版圖，後方的牆上則是平平整整的掛著族徽，象徵著舊時代的光榮。雖
然乍看之下不覺得壯觀，但是其恢復帝國的企圖，仍是表露無遺。
LONG
             );
    set("exits",([
        "west":CITY"inway3",
        "south":CITY"inhouse3",
        "north":CITY"inhouse1"]) );
    set("light",1);
 /*   create_door("south","north",([
         "keyword":({"oak door","door"}),
         "status":"closed",
         "name":"Oak door",
         "c_name":"橡木門",
         "c_desc":"一扇厚重結實，刻工精美的橡木門"
         ]) );*/
    reset();
}