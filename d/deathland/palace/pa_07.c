
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("???","廣場");
  set_long(@Long
Long
,@CLong
一個很大的廣場,地上長滿了一些綠色的植物.你抬頭一望,只見一個很大很大
的洞通向地上. 似乎那個洞是人工挖掘的,但你不能確定 .在廣場的中央有一口井
(well),一些僕人正在井旁打水.另外有一些奇怪的生物飛翔在你的上空,而一些矮
人戰士騎在上面控制著.經由過去的聽聞你得知那些奇異的生物應該就是傳說中才
會出現的獅鷹(griffon).
CLong
);
set("exits",([
               "west":Deathland"/palace/pa_06",
             ]) );
set("c_item_desc",([
    "griffon":@Cgriffon
長著一對翅膀,有著像獅子的頭的奇異生物
Cgriffon
    ,"well" : "@@to_look_well",
    ]) );
set("objects",([
    "warrior":Monster"/warrior",    
    ]) );
    
::reset();
}

string to_look_well()
{
     write("當你看著這口井,忽然你的腳滑了一下,你跌進了井裡.\n"
          );
     say(this_player()->query("c_name")+"在井旁消失了.\n");
     this_player()->move_player(Deathland"/palace/well01","SNEAK","");
     return "這井的深度並不深,你應該能很容易的爬出去\n";
}

