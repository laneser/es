#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
        seteuid(getuid());
        set_name("dinosaur_act","東施效顰");
        add("id",({"dino","dinosaur_act"}));
        set_short("東施效顰");
        set_long(
        "這是一種帶有惡臭的藥粉, 據說中毒的人會嘔吐不止,\n"
        "你可以用 poison <someone> 對某人下毒;用 check 檢查剩餘的份量。\n"
        );
        set( "unit", "盒" );
        set_duration(10);
        set_effect(10);
        set_type("simple_poison");
        set_times(3);
        set_difficulty(65);
        set("poison_msg","%s吐了你一身.... 惡~~~~\n");
        set("poison_method","%s從盒子裡沾了一些$P, 彈向%s");
}

