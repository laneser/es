// File: /d/noden/asterism/train_field.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("座騎訓練場");
	set_long(
		@C_LONG_DESCRIPTION
這裡是矮人們訓練座騎的地方,抬頭就可以看到數十隻獅鷲獸盤旋在半空中。
而地上則是正在接受基本訓練的年輕獅鷲獸。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
/*	
	set( "objects", ([
	        "trainer"   : MOB"trainer",	
	        "griffon#1" : MOB"griffon",
	        "griffon#2" : MOB"griffon",
	              ]) ) ;
*/	              
	set( "exits", ([
		"east"  : ASTR"patha",
		]) );
		
// #include "replace_room.h"
}

void reset()
{
      int i ;
      object mob,*clone ;
      clone = children(MOB"griffon") ;
      
      for(i=0;i<sizeof(clone);i++)
         { 
            if(environment(clone[i])==this_object())
                destruct(clone[i]) ;
           }
      if(mob = present("trainer")) destruct(mob) ;
      
      mob = new(MOB"trainer") ;
      mob->move(this_object()) ;         
      mob = new(MOB"griffon") ;
      mob->move(this_object()) ;      
      mob = new(MOB"griffon") ;
      mob->move(this_object()) ;
}



