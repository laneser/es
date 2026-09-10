#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(5);
        set_name("Young man Pan","青年潘恩" );
        add ("id", ({"drow", "pan","man" }) );
        set_short( "青年潘恩" );
        set("unit","位");
        set_long(
@C_LONG
這位勇敢的青年最近因為女朋友蒂德(Teeder)被神官送往神壇活祭而
傷心愈絕，他手上拿著一把鋒利的短劍，誓言要救出自己的愛人。
C_LONG
        );
        set ("gender", "male");
        set( "no_attack", 1 );
     set( "chat_chance", 16 );
        set( "chat_output", ({
               "潘恩激動的說道: 我一定要救出蒂德!\n",
               "潘恩緊握著小刀，神情緊張地跺步著.....\n"
                       }));
        set( "inquiry", ([
         "teeder" : ({ "蒂德是我的女朋友啦~那個可惡的神官竟然將我的蒂德抓去活祭..嗚\n"
                    })
                          ]) );
   wield_weapon("/d/deathland/weapon/dagger01");
}
