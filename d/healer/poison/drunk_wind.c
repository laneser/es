#include <mudlib.h>

inherit "/d/healer/poison.c";
void create()
{
	seteuid(getuid());
	set_name("Drunk Wind","沈醉東風");
	add("id",({"wind"}));
	set_short("沈醉東風");
        set_long(
                "這是東方殺手組織擅用的一種無形無色迷藥。"
                "雖然沒有強大的毒性,\n但可使人全身痠軟,"
                "任你是武林高手,至少也須一盞茶才能復元。\n"
        	"你可以用 poison <someone> 對某人下毒;用 check 檢查剩餘的份量。\n"
	);
	set( "unit", "瓶" );
	set_duration(20);
	set_effect(10);
	set_type("slow");
	set_times(5);
	set_difficulty(40);
	set("poison_msg","%s似乎無法順利的移動..\n");
	set("poison_method","%s打開一瓶$P, 輕輕地往%s吹");
}

