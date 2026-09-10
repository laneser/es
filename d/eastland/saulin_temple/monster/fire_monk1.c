#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "fire monk", "火工頭陀" );
        add ("id", ({ "monk" }) );
        set_short("火工頭陀");
        set("no_attack",1);
        set("unit","位");
        set_long(@C_LONG
火工頭陀自從被你抓來此地之後, 晨昏都受到少林僧侶們頌經的影響,
暴戾之氣大減, 現在他看來已經遠不如你剛見到他時的可怕了。
C_LONG
        );
        set( "inquiry", ([
             "book" : "@@ask_book"  ]));
}

void ask_book(object player)
{
    if ( !(int)player->query_temp("monk_movement") )
    tell_object( this_player(), @ALONG
   火工頭陀說道：不是我不告訴你經書的下落, 而是我真的不知道它在哪兒啊！

         你低頭沈思, 心想也許他真的不知道。一抬頭卻看到火工頭陀眼中閃過一股
         狡詐的光芒, 隨即消失, 回復如常。

         你已經知道他是在說謊, 心想這種人只好靠佛法來感化他了！！！
ALONG
                );
    else
    tell_object( this_player(), @AGREE
    火工頭陀喃喃自語：性在身心存  性去身心壞  佛向性中作  莫向性外求.....
    火工頭陀喃喃自語：前念著境即煩惱 後念離境即菩提......................
    火工頭陀喃喃自語：用即遍一切處 亦不著一切處 但淨本心.................
    火工頭陀喃喃自語：...................................................

    你看到火工頭陀臉上的神色逐漸從迷惑轉為堅定。

    火工頭陀抬起頭來說道：嗯！如今我已決定痛改前非, 我承認經書是我拿的,
                          我將它藏在香積廚裡, 你趁沒人時仔細找找就會找到
                          了。
AGREE
                );
}
