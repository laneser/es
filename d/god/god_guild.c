#include <mudlib.h>
#include <stats.h>
#include <org.h>
#include "../god.h"
#include <ansi.h>

#define BOARD GOD"god_board"

inherit NEW_GUILD;
void create()
{
    object guild_master;

        ::create();

    set_short("魔神公會");
        set_long(
                 @C_LONG_DESCRIPTION
你現在來到魔神進修的樂地，了是整個東方大陸最邪惡的地方。雖然這
是邪惡的地方。但同公會中的人是很友好,中間有一把邪劍(sword)上面
好象有字（runes),你不知不覺的想去看它。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "runes" : @LONG_TEXT
    ——————————————————————————————
      歡迎來本會一遊，這兒是一些高級玩完的快土(如果你是低級玩家
      請要不傷心。努力奮鬥一定能平步青雲，出人頭地的,那時本公會
      歡迎你加入。)如果想了解本公會的能力請打。
              (help guild)。             (read book)。
      ——————————————————————————————
LONG_TEXT
,
                "sword" : HIB "這邪神劍似乎具有某種不可思議的魔力。\n" NOR
 ]) );
    set( "exits", ([
                  "east" : "/d/god/guild/pk.c",
                  "south" : "/d/god/guild/shop.c",
                  "west" : "/d/god/guild/tech.c",
        ]) );
        set_guild("god");
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
        write("
"+HIY"積力量和智慧於一面，邪惡的是它的生命只有PK
玩家才能得到真正的力量。\n"
"如果想要用經驗來做到成功，可能一百年都不可
能(ES的時間)所以殺玩家。\n"
"是唯一生長最快的的“經驗”。\n\n\n"
"公會所提供的屬性提升上限為:(可能少了請POST)\n\n"
   "      力量: 30            智慧: 40\n"
   "      敏捷: 35            體質: 25\n"
   "      虔誠: 10            運氣: 30\n"+NOR""
              );
        return 1;

}
