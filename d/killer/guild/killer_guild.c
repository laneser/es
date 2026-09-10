//sage修改於：98-6-12 ////#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <org.h>
#include "../killer.h"

#define BOARD KILLER"killer_board"

inherit NEW_GUILD;
inherit DOORS;
void create()
{
    object guild_master;

        ::create();

    set_short("殺手公會");
        set_long(
                 @C_LONG_DESCRIPTION
    你進了一間烏燈黑火的房間，一陣寒風吹來，不覺打了個哆嗦，你的第六
感告訴你，在房子的某個角落，正有一雙狼一樣的眼睛在盯著你，只要你一放
鬆警戒，這雙眼睛就會向你撲來。然而在這間房子裡，卻看不到半個人影。
    一本書懸掛在房子的正中間。
    在角落裡有一張已經發黴的紙(paper)，你用盡所有精力，才依稀看出一點
眉目。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "paper" : @LONG_TEXT
———————————————————————————————————
破紙上寫著:
    本公會為世上最強之公會，加入後能學到世上無雙的武功，可以稱霸世界，
名額有限，欲入從速。
    
    詳細入會情形請用 help guild 閱讀說明。
———————————————————————————————————
LONG_TEXT
,
                 "book":"這是一本關於殺手公會限制與情形的書。你可以read它。\n"
 ]) );
    set("exit_suppress",({"east"}));
    set( "exits", ([
                  "north": "/u/s/sage/guild/gc",
                  "west" : "/d/killer/guild/killer_guild1",
                  "east" : "/d/killer/guild/killer_guild3",
        ]) );


        set( "pre_exit_func", ([
                "west" : "check_killer" ]) );
    guild_master=new("/d/killer/monster/blowblood");
    guild_master->move(this_object());
       create_door("north", "south", ([
                    "keyword"       : ({ "tree door", "door" }),
                    "name"          : "tree door",
                    "c_name"        : "木門",
                    "c_desc"        : "一扇破爛的木門",
                    "status"        : "closed",
        ]) );

        set_guild("killer");
        BOARD->frog();
        reset();
}
void init()
{
        ::init();
        add_action( "do_read", "read" );
}
int do_read(string arg)
{
        if( !arg || arg!="book" ) return 0;
        write("    殺手是本世紀頭號敵人，全世界的英雄無時無刻都想殺之而後快，但他們\n"
              "    實在是太厲害，殺手擁有超強的戰鬥力，他們對每重生物的生理構造都十\n"
              "    分清楚，所以能給對手一擊致命的傷害，他們在戰鬥中不會考慮自己的安\n"
              "    全，直到把對手殺死為止。當他們完成一個任務，或者殺死一個敵人，都\n"
              "    會拿到任務點，任務點越高，他就越會有機會成為公會中的領導人物。\n\n"
              "    殺手視殺手公會為家，只要有人對公會做出一些他們認為對他們名譽、安\n"
              "    全有影響的事，他們就會全力反擊，直到肇事者消失為止。\n\n\n"
              );
      return 1;
}
