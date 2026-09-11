
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("the college of studing trolls' attack mode","巨人攻擊模式研究室");
  set_long(@Long
Long
,@CLong
這裡充滿了一些奇奇怪怪的模型(model),和一大堆的記錄(notes),上面記載著巨人的
種種攻擊模式及弱點.
CLong
);

set("c_item_desc",([
    "model":"主要是巨人的模型,上面畫了全身的穴道及弱點.\n",
    "notes":"一堆雜亂無章的計錄,沒有幾個人能從其中找出的重要資料.\n",
    ]) );
set("exits",([
               "out":Deathland"/dwarf/village_04",
             ]));
set("objects",([
    "general":Monster"/general",
    ]) );
::reset();
#include "../replace_room.h"
}

