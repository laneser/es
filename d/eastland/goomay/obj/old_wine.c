#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "quaff_potion", "drink" );
        add_action( "quaff_potion", "quaff" );
}

void create()
{
        set_name("old wine","陳年老酒");
        add( "id" , ({ "wine" }) );
        set_short("陳年老酒");
        set_long(
		 "這是一罈上好的陳年老酒，罈上有著暗黃的泥封，破碎的標籤都難以辨識了。\n");
        set("unit","罈");
        set("weight", 10);
        set("value", ({20, "silver"}) );

}

int quaff_potion(string arg)
{
        if( ! arg || !id(arg) ) return 0;
        write( 
                "你咕嘟咕嘟地喝下一整罈老酒，好像有一把利刃把你從中劈開一般。\n");
        tell_room( environment(this_player()), 
                this_player()->query("c_name")+"咕嘟咕嘟地灌下一整罈老酒，然後醉的滿地亂爬。\n"
		, this_player()
        );
        remove();
        return 1;
}
