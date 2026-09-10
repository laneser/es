#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("Explored Note","探險筆記本");
    add("id",({"note"}) );
    set_short("探險筆記本");
    set_long(@C_LONG
    這是瓊斯的父親～老亨利瓊斯畢其一生研究所記錄整理的謫仙島筆記，
裡面詳細的記錄了各處的探索心得，平常一定隨身攜帶，絕不輕易外借。 
C_LONG
            );
    set("unit","本");
    set("weight",5);
    set("useless",1);
	set("value",({ 1,"silver" }) );
}
 
void init()
{   
    add_action("do_read","read");
} 

int do_read(string str)
{
    if( !str || !id(str) ) 
    return notify_fail("你要看什麼？\n");
    this_player()->more("/d/island/forest/daemons/contents");
    this_player()->set_explore("island#1");
    return 1;
} 
