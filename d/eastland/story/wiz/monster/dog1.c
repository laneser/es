#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "white dog Lucky", "小白狗 吉利" );
	add("id",({"dog","lucky"}));
	set_short( "小白狗 吉利" );
	set_long(@C_LONG
一隻全身純白毫無雜毛的小狗。它原是護國師孫女兒養的，前幾天因為追逐著某東
西卻不幸掉在這裡，受傷沈重，奄奄一息。它正不停地舔著傷口，哀哀作響，可憐
極了。如果你有籃子，或著可以把它裝著帶上去。   
C_LONG
        );
        set("unit","只");
        set("no_attack",1);
        set("lucky",1);
        set("max_hp",100000);
        set("hit_points",1);
        set("chat_chance",10);
        set("chat_output",({
           "嗚～嗚～嗚～～\n"
       }) );
}
