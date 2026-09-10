#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼澤地底洞穴");
    set_long(@LONG
這裡已經是在地下超過三十丈深的地方，牆壁上的『曙薇』明顯少了許多，不過
有更多奇奇怪怪，連名字也叫不出植物參差和『曙薇』長在一起。有些跟『曙薇』一
樣發出淡淡的螢光，有藍，橙等顏色的；有些開著小小的花朵散著馥郁的芳香。正前
方小紅花叢中一隻無可明狀的透明生物傳來『嚶』、『嚶』的細微聲響，好像在對你
示好一般。
LONG
    );
    set("light",1);
    set("exits",([
            "westup":LAKE"swamp_d2",
    ]) );
    set("objects",([
      "shapeshifter":LMONSTER"shapeshifter1"
    ]) );  
    ::reset();
}

