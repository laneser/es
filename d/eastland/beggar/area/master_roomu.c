#include "/d/eastland/beggar/dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "master_room", "『賞善罰惡廳』" );
	set_long(@C_LONG
這裡是『賞善罰惡廳』的二樓, 這裡算得上佈置的滿精緻的;你右邊的牆壁上
有一幅潑墨的山水畫, 畫對面的牆上有一張連帶虎頭的老虎皮;房間的中央鋪著一
長條的紅色地毯,地毯的兩旁有著八張用繪木做成的椅子; 地毯的盡頭有一張太師
椅,椅上鋪著的是一張大黑熊皮;太師椅後面的牆上供奉著『武聖』關公的肖像,關
公兩旁各是關平和手持青龍偃月刀的周倉。旁邊有一個樓梯可以通往下面。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "down":DBEGGAR"master_room.c"
	]) );
        set( "objects", ([
                      "master of beggar":DMONSTER"master.c",
                             "master Wu":DMONSTER"wu_master.c",         
                               "servant1":DMONSTER"servant.c",
                               "servant2":DMONSTER"servant.c" 
        ]) );
        set_reset(this_object(),21600);
}
void reset()
{
   set_reset(this_object(),21600);
   ::reset();
}
void init()
{
    if ( this_player()->query("class") != "thief" )
        return ;
    if ( !this_player()->query_temp("hidding"))
        return ;
    if ( random(20) > 18 )
        return ;
    this_player()->delete_temp("hidding");
    call_out("recover",1,this_player());
}
void recover(object obj)
{
    obj->block_attack(6);
    obj->set_temp("msg_stop_attack",
           "( 你潛行失敗，被敵人突襲，一陣手忙腳亂！ )\n" );
}