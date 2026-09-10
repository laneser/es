#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("wineskin","牛皮酒袋");
        set_short("酒袋");
        set( "weight", 10);
        set( "value", ({ 5, "silver" }));
        set("long", "一個牛皮縫的大酒袋，大概裝得八、九升的酒。\n");
        set("unit", "個");

}
void init()
{
        add_action("to_drink","drink");
}
int to_drink(string arg)
{
	object me;

        me = this_player();

        if( !arg || arg=="" || arg !="wine")
                tell_object(this_player(),
                "你想幹什麼?\n"
                );
    else {
        tell_object(this_player(),
        "你一仰頭,咕嚕咕嚕地喝了幾口酒.\n"
        );
        tell_room(this_object(),
                me->query("c_name")+"一仰頭,咕嚕咕嚕地喝了幾口酒．\n"
                , me);
	}
        return 1;
}

