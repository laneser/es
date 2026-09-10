
#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 10 );
        set_name( "book shop owner", "書店老闆" );
        add( "id", ({ "owner" }) );
        set_short( "the book shop owner", "書店老闆" );
   set_long( @LONG
書店的老闆年約五十, 他在青年時曾立志要成為學者, 但卻因機運
不佳而未能如願--因此以幾十年的積蓄開了此間書店。不過不知道為了
什麼事，老闆最近整天愁眉苦臉，想來生意不太好。
LONG
        );
        set( "no_attack", 1 );
        set( "gender", "male" );
        set( "inquiry", ([
               "trouble" : @TROUBLE
唉，我的煩惱啊? 你買本書看看就知道我所煩為何啦! 唉....唉....
TROUBLE
                ,"help" : @HELP
要幫我的忙? 最大的忙就是來買我的書啦! 謝謝羅!
HELP
 ]) );

        set( "chat_chance", 20 );
        set( "chat_output", ({
"書店老闆說道 : 唉....唉......真是煩惱(trouble)啊....心情鬱悶啊......\n",
"書店老闆自言自語 : 唉.....書店的書都被蟲蛀光了, 還有誰會買呢 ? \n"
        }) );

}
