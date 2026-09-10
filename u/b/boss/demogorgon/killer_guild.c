//#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include </u/s/sage/guild/mudlib.h>
#include </u/s/sage/guild/stats.h>
#include </u/s/sage/guild/guilds.h>

#define BOARD "/u/s/sage/guild/killer_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object guild_master;

        ::create();

    set_short("鬼屋");
        set_long(
                 @C_LONG_DESCRIPTION
    你進了一間烏燈黑火的房間，一陣寒風吹來，不覺打了個哆嗦，你的第六
感告訴你，在房子的某個角落，正有一雙狼一樣的眼睛在盯著你，只要你一放
鬆警戒，這雙眼睛就會向你撲來。然而在這這間房子裡，卻看不到半個人影。
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
    有關本公會的限制與情形請用 help healers。
———————————————————————————————————
LONG_TEXT
 ]) );
    set( "exits", ([
                  "north": "/u/s/sage/guild/gc",
                  "west" : "/u/s/sage/guild/killer_guild1",
        ]) );


        set( "pre_exit_func", ([
                "north" : "check_healer" ]) );
    //guild_master=new("/u/s/sage/test/");
    //guild_master->move(this_object());
       create_door("north", "south", ([
                    "keyword"       : ({ "tree door", "door" }),
                    "name"          : "tree door",
                    "c_name"        : "木門",
                    "c_desc"        : "一扇破爛的木門",
                    "status"        : "closed",
        ]) );

       // set_guild("monk");
        set_guild("/u/s/sage/guild/killer.c");
        BOARD->frog();
        reset();
}


