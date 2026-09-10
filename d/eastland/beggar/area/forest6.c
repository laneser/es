#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "forest1", "竹林" );
	set_long(@C_LONG
你身處在一片綠油油的竹林裡,這裡很安靜,用來讀書的好地方。竹森的一角有著
一堆似乎被挖掘著的痕跡。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
	        "southeast":DBEGGAR"forest5"
        ]) );
     reset();
}
void init()
{
    add_action("do_search","search");
}
int do_search(string arg)
{
    object obj;
    if ( !arg || arg != "hole" ){
        tell_object(this_player(),"你在找什麼東西？\n");
        return 1;      
    }
    if ( !present("a white dog",this_object()) ){
        tell_object(this_player(),"你在找什麼東西？\n");
        return 1;
    }      
    if ( this_object()->query_temp("be_searched") ){
        tell_object(this_player(),"這裡似乎被別人找過了。\n");
        return 1;
    }
    this_object()->set_temp("be_searched",1);
    obj=new(DITEM"toad");
    obj->move(this_player());
    tell_object(this_player(),"嚇!你找到一隻玉火蟾蜍!!\n");    
    return 1;
}