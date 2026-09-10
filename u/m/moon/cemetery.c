//#pragma save_binary

#include "farwind.h"

inherit ROOM ;

void create ()
{
        object obj ;

        ::create();
//      set_outside("farwind") ;
        set_short("露天英雄紀念館");
        set_long(@C_LONG
你現在位於遠風鎮的露天英雄紀念館。在草地中央有一座無名英雄
駐劍遠眺的銅像(statue)，相傳遭到意外而不幸死亡的靈魂，如果到這
裡祈禱(Pray)的話，就有機會獲得肉體再造的能力。
C_LONG
                );
        set( "light", 1 );
        set ("exits", ([
                "west" : FARWIND"bazz4",
                "east" : FARWIND"charch"
        ]) );
        set( "objects", ([
                "scroll": FARWIND"items/scroll" ]) );
        set( "no_monster", 1 );
        set( "PK_ZONE",1);
        set("item_desc",(["statue" :@C_WORD
這是一座威武的銅像，英雄的雙眼眺望遠方，堅毅的臉上泛著幾許落寞憂傷。
在銅像的底座鑲著一面銅牌，上面寫著：

        英雄？什麼是英雄？
        我只祈禱神啊 !! 要賦予每一個跌倒的人都有再爬起來的勇氣，
        要讓每一個在生死邊緣掙扎的人能保留有微笑面對命運的信心。

                                        艾柏魯斯 於 毀滅之日後
C_WORD
        ]));
   reset();
}

void init()
{
        add_action("revive_player","pray") ;
}

int revive_player(string str)
{
    object player;

    player = this_player();
    if( str && member_group(geteuid(player), "admin") ) {
        player = find_player(str);
        if( !player )
                return notify_fail("沒有這個人!\n");
        if( !player->query("ghost") ) 
                return notify_fail( player->query("c_name")+
                        " 現在是活生生的人!\n" );
        tell_object( this_player(), 
          "\n你使用你無上的法力，一陣奇蹟似的光芒攏罩著"+
          player->query("short")+"。\n"
        );
        tell_object( player, 
          "萬能的神 "+this_player()->query("c_name")+" 使用他無上的法力"+
          "，一陣奇蹟似的光芒攏罩著你。\n"
        );
        tell_room( this_object(), 
          "萬能的神 "+this_player()->query("c_name")+" 使用他無上的法力"+
          "，一陣奇蹟似的光芒攏罩著"+player->query("short")+"。\n" , 
          ({ player, this_player() })
        );
        player->set_temp("skip_dead",1);
    }
        else if(!player->query("ghost")) {
                write("你佇立在英雄們的銅像前祈禱，希望能成為他們的一份子。\n");
                player->save_me();
                "/adm/daemons/backup"->user_backup(player);
                return 1;
        }
        else if( player->query_temp("skip_dead") )
          player->revive(1);
        else
          player->revive();
        return 1;
}
