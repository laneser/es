#include "/d/eastland/beggar/dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "hospital1", "藥鋪二樓" );
	set_long(@C_LONG
這裡是藥鋪的二樓, 是『一代神醫 小雪子』用來醫治病患的地方。這個房間
裡最醒目的就是放在房間中央, 供小雪子練習針灸的銅人模型,上面標示著一大堆
的經脈和術語。房間的右邊是一個小小的書桌, 雖然上面凌亂不堪,但放著的都是
很有用的醫書。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "down":DBEGGAR"hospital.c"
	]) );
     
        set( "objects", ([
                         "uki" : DMONSTER"uki.c",
                         "ahtu": DMONSTER"ahtu.c" 
                         ]) );
     reset();
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
