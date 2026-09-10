#include <mudlib.h>
#include "/d/eastland/legend/legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "mountain1", "山巔" );
    set_long(@C_LONG
你翻過剛才那面峭壁(bluff)之後來到了山的另一邊。 你現在正走在一條山巔
的山路上，山路崎嶇不平，地上長了些稀稀疏疏的野草，旁邊有一顆大樹。這裡的
視野很好，你俯視下去可以看到一面大湖。
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
      "follow-bluff"}) );
    set("c_item_desc",([
      "峭壁":"@@do_look",
      "bluff":"@@do_look",
      "光滑的峭壁":"@@do_look"
    ]) );               
    set( "exits", ([
      "follow-bluff":LAKE"mountain3",
     "west":LAKE"mountain5"
    ]) );
    reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
   tell_object(this_player(),"你找到了一面光滑的峭壁( bluff )\n"); return 1;
}
string do_look()
{
    return "一面很陡的峭壁，你可以沿著它 ( follow-bluff ) 到山的另一邊。\n";
}