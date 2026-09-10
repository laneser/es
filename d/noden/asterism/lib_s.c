// File: /d/noden/asterism/lib_s.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("storage room", "藏書室");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
這裡是艾斯特律恩城的圖書館藏書室。與魔族戰爭曾將所有圖書館藏書幾乎完全
摧毀殆盡。地精將戰後能找到的所有殘本全收集到這裡。一個個的書架整整齊齊
的排在牆邊。一塊鑲在牆上的牌子鏤刻著幾個字 "應用類" 。 
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["shelves":
             "架子上放著一堆堆蓋滿塵埃的卷軸，被火薰黑燒過的書。也許到處找找會\n"
             "有些收穫。\n" ,
             "shelf":
             "架子上放著一堆堆蓋滿塵埃的卷軸，被火薰黑燒過的書。也許到處找找會\n"
             "有些收穫。\n" ,
             ]));       
	set( "exits", ([ 
		"north":ASTR"lib01"
		]) );
	reset();
	
}                         

void init()
{
       add_action("do_search","search") ;
       add_action("do_read","read") ;
}

int do_search(string s)
{
    int checkflag ;
    
    checkflag = this_player()->query_temp("check_s_lib") ;
    
    if ( !s || (s!="shelves"))
        return notify_fail(can_read_chinese()?
          "你要找什麼？\n" : "What are you looking for ?\n"  ) ;
         
    if ( !checkflag || checkflag != 1 )
       { 
         write(can_read_chinese()?
           "你在目錄中找到了幾本你覺得感興趣的書，它們分別是:\n"
           " 1. 種花的藝術\n"   
           " 2. 召喚儀式\n"
           " 3. 神聖的力量\n" :
           ""  )  ;
         this_player()->set_temp("check_s_lib",1) ;
         return 1;
       }
       
    else 
       { 
         write(can_read_chinese()? 
          "你除了剛剛的那些書外，再也找不到其它有趣的了。\n":
          "" ) ; 
         return 1 ;
       }      
}

int do_read(string s)
{
    int checkflaga,no ;
    string str ;
    
    checkflaga = this_player()->query_temp("check_s_lib") ;
    
    if ( !checkflaga|| checkflaga != 1 )
         return notify_fail(can_read_chinese()?   
           "你不知道你要幹什麼。\n" : "You don't know what do you wanna do.\n "
              ) ;                       

    if(s=="1") no =1 ;
    if(s=="2") no =2 ;
    if(s=="3") no =3 ;

    if(!(!no))
      {      
        switch(no)
          {
             case(1) : str="planting" ;
                      break ;
          
             case(2) : str="summons" ;
                      break ;
          
             case(3) : str="ceremory" ;
                      break ;
                    
            }    
        this_player()->more(BOOKS+str,0,1) ;    
        return 1 ;                 
       }
   return notify_fail(can_read_chinese()?
             "你想要讀什麼東西？\n" : "What do u wanna read ?\n" ) ;
                     
}   



