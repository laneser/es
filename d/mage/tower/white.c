//#pragma save_binary
#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
        ::create();
        set_short("A white room", "白魔法圖書室");
        set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
你現在來到銀色之塔中藏書最豐富的一間圖書室，這裡所收藏有關白魔法的
經典和書籍是任何地方也比不上的，除了目前魔法師們廣為使用的幾種魔法
之外，有些書籍上所記載的法術到現在還沒有人能看懂，你可以翻閱第一個
書架上的索引(index)，看看目前有哪些法術可以參考,往西是通往圖書館大
廳的通道。
C_LONG_DESCRIPTION
        );
    set( "no_monster", 1);
        set( "light", 1 );
        set( "exits", ([ 
        set( "item_func", ([
            "index" : "view_catalog" ]) );
        set_spells( ([
                "antidote"       : ({ "white-magic", 40, 4, 15, 150 }),
                "heal"    : ({ "white-magic", 40, 4, 15, 150 }),
                "paralyze"       : ({ "white-magic", 40, 4, 15, 150 }),
    "power-boost" : ({ "white-magic", 40, 4, 15, 150 }),
      "protect"    : ({ "white-magic", 40, 4, 15, 150 }),
        ]) );
        reset();
}
