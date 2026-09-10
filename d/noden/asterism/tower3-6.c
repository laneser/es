// File: /d/noden/asterism/tower3-6.c

#include "asterism.h"////#pragma save_binary

inherit ROOM;

void create()
{
        object mob ; 	
	::create();        
        
	set_short("地精高塔的頂樓");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中地精高塔的最頂層。矮人和半身人為這片土地本來的
主人建築了這麼一座外觀宏偉的住所。這兒四周的牆璧,被各式各色的寶石鑲點
得五彩繽紛。而這一層就是傳說中地精長老院首席的住處。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"down": ASTR"tower3-5",
		]) );
	set("pre_exit_func",(["down" : "check_cast" ]) ) ;
	
        set("no_embattle",1) ;
	set("cast_block",0) ;  

        mob = new(MOB"gnome_archelder") ;
        mob -> move( this_object() ) ;

}

int clean_up() { return 0; }

int check_cast()
{  
     object victim,elder ;
     int aa ;
          
     elder = present("archelder") ;
     if(!elder) return 0 ;
     aa = elder->query_temp("cast_busy");

     if( aa && (int)this_player()->query_temp("once_k_archelder") )
       {
//         tell_room(this_object(),"been blocked.\n",) ;
         write(
               "一陣藍光擋住你的去路，你被這神秘的力量反彈回來。\n"
                ) ;
         return 1 ;
        }
     return 0 ;
}

