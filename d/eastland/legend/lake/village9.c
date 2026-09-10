
#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("井邊");
        set_long( 
@LONG
這口水井 (well) 是漁村日常生活賴以為生的水源地，平時，村裡都會派人來
巡視一番，並且定期做維修的工作，以免水井受到汙染。所以，這口井看起來雖然
老舊，依然保持著乾淨的供水。井旁邊不時有婦女在洗服，話東家長聊西家短的，
說不定你可以從其中打聽到什麼重要的消息也說不定。道路往東、北邊延申；南、
西邊是一面牆。
LONG);
    set( "light",1);
    set("exits",([
       "north":LAKE"village10",
        "east":LAKE"village11"
    ]) );   
    set("c_item_desc",([
      "well":"一口清澈的水井，令你有股想跳下去 (jump) 的衝動。\n",
    ]) );         
    set("objects",([
       "woman#1":LMONSTER"woman",
       "woman#2":LMONSTER"woman",
       "woman#3":LMONSTER"woman",
    ]) );
    ::reset();
}
void init()
{
    add_action("do_jump","jump");
}
int do_jump(string arg)
{
    if ( ! arg || arg !="well" )
       return 0;
    write("你毫不猶豫地脫光服往井一跳!\n\n只見井底一股吸力把你卷往下面 ...\n\n\n");
    this_player()->move_player(LAKE"village5",({
       "%s脫光衣服往井一跳 。\n",
       "%s從底下的池水浮上來.\n"}),"");
    return 1;
}