
#include <mudlib.h>

inherit OBJECT;
void create()
{
	seteuid(getuid());
        set_name("pearl", "幻魔珠");
        add( "id", ({ "pearl","daemon pearl" }) );
        set_short( "幻魔珠" );
        set("long",@LONG
這是撒巴吐卡用塔姆姆秘術所製造出來的寶珠，據說有降伏魔物的神奇力量。
LONG
        );
        set( "weight", 5 );
        set( "unit", "顆" );
}

void init()
{
        add_action("to_say","say");
}

int to_say(string s)
{
        if (s != "ern!-sdl") return 0;

        if ( (this_player()->query_temp("smore_armor/arcold") != 1 )
          || (this_player()->query_temp("smore_armor/elder") != 1)
          || (this_player()->query_temp("smore_armor/knight") != 1)
          || (this_player()->query_temp("smore_armor/minister") != 1)
          || (this_player()->query_temp("smore_armor/las") != 1) )
                return 0;

        tell_object(this_player(),@LONG
你手中的寶珠發出一道光芒照在食肉獸的身上。

你可以趕快企圖去控制(control)它
LONG
        );
        this_player()->set_temp("control_flesh",1);
	this_object()->remove();
        return 1;
}
