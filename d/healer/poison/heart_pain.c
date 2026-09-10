#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
	seteuid(getuid());
	set_name("Heart Pain","西施捧心");
	add("id",({"heart","pain"}));
	set_short("西施捧心");
        set_long(
	"這是一種無色無味的藥粉, 據說中毒的人會心痛不止,\n"
	"發作時,症狀有如古代美女西施捧心蹙眉狀,故名之。\n"
	"你可以用 poison <someone> 對某人下毒;用 check 檢查剩餘的份量。\n"
	);
	set( "unit", "盒" );
	set_duration(10);
	set_effect(10);
	set_type("simple_poison");
	set_times(3);
	set_difficulty(65);
	set("poison_msg","%s按著胸口, 好像很難過的樣子..\n");
	set("poison_method","%s從盒子裡沾了一些$P, 彈向%s");
}

