
#include </u/b/boss/demogorgon/mudlib.h>
#include </u/b/boss/demogorgon/stats.h>
#include </u/b/boss/demogorgon/guilds.h>
#include <ansi.h>

#define BOARD "/u/b/boss/demogorgon/board"

inherit GUILD;

void create()
{
        ::create();
      set_short( "魔神公會" );
set_long(
"你現在來到魔神進修的樂地，了是整個東方大陸最邪惡的地方。雖然這是邪
惡的地方。但同公會中的人是很友好，中間有一把邪劍(sword)上面好象有
字（runes),你不知不覺的想去看它。\n",
        );

        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/guild1.c",
    "south" : "/u/b/boss/demogorgon/shop.c",
    "west" : "/u/b/boss/demogorgon/guild2.c",

        ]) );

        set("item_desc", ([
                "runes" : CYN
" —————————————————————————————
   歡迎來本會一遊，這兒是一些高級玩完的快土(如果你是低級玩家
   請要不傷心。努力奮鬥一定能平步青雲，出人頭地的,那時本公會
   歡迎你加入。)如果想了解本公會的能力請打(help guilds)。
   (help damogorgon)。
   ————————————————————————————— \n"NOR,
                "sword" : HIB "這邪神劍似乎具有某種不可思議的魔力。\n" NOR
        ]) );


       // set_guild("mage");
        set_guild("/u/b/boss/demogorgon/dema.c");
        BOARD->frog();
        reset();

}

#include </u/b/boss/demogorgon/mudlib.h>
#include </u/b/boss/demogorgon/stats.h>
#include </u/b/boss/demogorgon/guilds.h>
#include <ansi.h>

#define BOARD "/u/b/boss/demogorgon/board"

inherit GUILD;

void create()
{
        ::create();
      set_short( "魔神公會" );
set_long(
"你現在來到魔神進修的樂地，了是整個東方大陸最邪惡的地方。雖然這是邪
惡的地方。但同公會中的人是很友好，中間有一把邪劍(sword)上面好象有
字（runes),你不知不覺的想去看它。\n",
        );

        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/guild1.c",
    "south" : "/u/b/boss/demogorgon/shop.c",
    "west" : "/u/b/boss/demogorgon/guild2.c",

        ]) );

        set("item_desc", ([
                "runes" : CYN
" —————————————————————————————
   歡迎來本會一遊，這兒是一些高級玩完的快土(如果你是低級玩家
   請要不傷心。努力奮鬥一定能平步青雲，出人頭地的,那時本公會
   歡迎你加入。)如果想了解本公會的能力請打(help guilds)。
   (help damogorgon)。
   ————————————————————————————— \n"NOR,
                "sword" : HIB "這邪神劍似乎具有某種不可思議的魔力。\n" NOR
        ]) );


       // set_guild("mage");
        set_guild("/u/b/boss/demogorgon/dem.c");
        BOARD->frog();
        reset();

}
