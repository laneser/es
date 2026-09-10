// Deathland/holyplace/h16.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);	
  set_short(" A strange place","陰暗的虛無飄渺處");
  set_long("need work .\n",
"一處陰暗的地下世界,四處的黑影無聲無息地向你侵襲而來.這裡的寂靜令人感到害怕,\n"
"讓你不自主的想要發出一些聲音.沒有風聲,沒有水聲,甚至你無法聽到自己的腳步聲,你不\n"
"禁懷疑自己處在一個虛無的地方.你的視野越來越小,似乎你的眼睛被一些黑色的\"霧\"擋住\n"
"了視線.在這個危險的地方,你最好提高警覺,因為隨時都有可能從黑暗中走出邪惡的生物.\n"
"這個地方似乎是個封閉的區域,北南西三個方向都是厚厚的巖壁,東邊的唯一出口也窄窄的\n"
".而最奇怪的事,這地方似乎有著亮光(light).\n"
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    "light":"@@to_look_light",
    "plate":"@@to_look_plate",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h15",
             ]));
reset();
}

string to_look_fog()
{
     return "是霧嗎?你懷疑著,你能很清楚地看到一些懸浮粒子飄散在你的周圍.\n"
            "\或許是一種邪惡的物質,你能感覺到有著邪惡的成份參雜其中.\n" ;
}

string to_look_light()
{
    return "那道微微的亮光似乎來自西邊的巖璧上面,仔細一看,原來西邊的巖壁上面.\n"
           "有一個平臺(plate).\n";
}

string to_look_plate()
{
      return "一個小小的平臺,但是由於地勢太高,所以你無處法清楚地看清上面有甚麼東西.\n";
}
