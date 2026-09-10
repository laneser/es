// File: /d/noden/asterism/path01.c

#include "../asterism.h"

inherit ROOM;

int be_searched;
void create()
{
	::create();
	set_short("halfling tower", "半身人高塔的地下室");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中半身人高塔的地下室,堆積著一堆雜七雜八的廢棄物,讓這地
方顯得十分混亂.
C_LONG_DESCRIPTION
	);

//	set( "light", 1 );
	set("search_desc",([
	    "here":"@@to_search_here",
	    ]));
	set( "exits", ([ 
		"up" : ASTR"tower1-1",
		]) );
	reset();
}

string to_search_here()
{
    if (be_searched==0)
       {
         be_searched=1;
         
         if(((int)this_player()->query_level()<13)||
            ((int)this_player()->query_perm_stat("kar")<random(21)))
             return "你在廢棄物中到處亂翻, 但是找不到有用的東西。\n" ;

         add("exits",([
             "down":DUNGEON"path02",
             ]) );
         add("exit_msg",([
             "down":"$N進入了艾斯特律恩的下水道.\n",
             ]) );    

         return "在這些雜亂無章的廢棄物中,你花費了許多的時間,終於在一個大木箱下\n"
                "找到一個往下的通道.\n";
        }
    else 
       return "這地方已經有人早你一步來過了.\n" ;         

}

void reset()
{
    ::reset();
    be_searched=0;
    set( "exits", ([ 
		"up" : ASTR"tower1-1",
		]) );
    set( "exit_c_msg",([]) );
}

