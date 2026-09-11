
#include "../zeus.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "dun gin", "斷情" );
        add("id",({"dun","gin"}));
        set_short( "斷情");
        set("unit","位");
        set_long( @LONG
斷情是一位霸氣四溢的人，早年在他行走江湖的時候的震囁了不少的宵
小，著實令動□不安的江湖平靜了一段時間，可是英雄難過美人關由於
上蒼的捉弄，他最愛的紅顏因他而遭人遷怒，不幸魂歸離恨，他在萬念
俱灰之際，毅然退出江湖來到段家，斬斷一切情絲的糾纏改名－斷情．
LONG
        );
        set_perm_stat("str",25 );
        set_perm_stat("dex",24 );
        set_natural_weapon(40, 25, 30);
        set_natural_armor( 60, 20 );
        set( "max_hp",700);
        set( "hit_points",700);
        set ("gender", "male");
        set ("race", "dwarf");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(ZOBJ"/thunder_blade");
        equip_armor(ZOBJ"/white_robe");
        equip_armor(ZOBJ"/fire_cloak");
        equip_armor(ZOBJ"/six_shoe");

        set("inquiry",([
        
           "net": 
                "這些網子是用來兜住所流下來的木頭的，我們所開採的鐵礦用木頭\n"
                "來運送可省下不少時間，懂嗎？\n",     
           "river": 
                "那是我們運木頭的管道，如果你不怕死的話，可以下去遊遊(swim)看．\n",
           "ghost":"@@ask_ghost",
                
      ]));
}
int ask_ghost()
{   if(this_player()->query_temp("ask_ghost")){
    tell_object(this_player(),
@AA

哪裡有鬼，我看你一定是虧心事做太多了，大廳的南方是我們段家所設的一
間機關房而已，有什麼好大驚小怪的，只要往南邊的牆一推就可以進去了，
去去去，別來煩我．
AA
);
}else{
tell_object(this_player(),
@BB

你不要在這邊擾亂人心，我們這裡可是很乾淨的喔！再亂說小心我ｋ你！！
BB
);
}
return 1 ;
}
   