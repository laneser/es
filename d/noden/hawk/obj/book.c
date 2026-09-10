#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("book", "飄流詩集");
        add( "id", ({ "poet book","p_book" }) );
        set_short( "飄流詩集" );
        set("long","這本詩集是某詩人的心血結晶，不知道為啥會在這裡。\n");
        set( "weight", 40 );
        set( "unit", "本" );
}

void init()
{
        add_action("to_read","read");
}

int to_read(string s)
{
        if (s != "book") return 0;
        tell_object(this_player(),
                "你翻開這本書，嚇然發現整本書寫的密密麻麻....不過你只"+
                "看得懂幾行字....\n\n"+
                "英雄自古誰無屎，誰能大便不用紙？\n若你大便不用紙，"+
                "難道你都用手指？\n\n....你看完以後，不禁聞聞自己的手指"+
                "......惡....\n");
        return 1;
}
