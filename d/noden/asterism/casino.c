// This is casino of asterism  by  Indra on 94.10.9
// File: /d/noden/asterism/casino.c

#include "asterism.h"

inherit ROOM;
inherit "gamble.c" ;

void create()
{
	::create();
	set_short("A Casino", "撲克俱樂部");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城最著名的賭場。艾斯特律恩在戰爭後,由於
三族的通力合作,使得這個城能極迅速的由廢墟中重建。在閒暇之餘,人們總喜歡
到酒館小酌及小賭一番。久之,酒店老闆乾脆擴大規模,開起賭場來了。
在這個大聽中央,是玩梭哈(Poker)的臺子,靠左邊是比21點(Black Jack)的場地,
靠右邊是擲骰子(Dice)的地方。而在你正前方那堵牆上似乎有張規則(rule)。
及一張玩法說明(explain)。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : ASTR"city21",
		]) );
 	set("pre_exit_func",([ "north" : "check_gamble" ]) ) ;
        set("c_item_desc",(["rule":"1.禁止作弊。\n"
                                   "2.禁止偷竊。\n"
                                   "3.禁止強奪。\n違者一律以私刑伺候。\n",
                            "explain":
                                   "" ,
                            ]) ) ;        
	reset();
}

void init()
{
   add_action("do_gamble" , "play");
   add_action("do_draw","leave");
}

int poker()
{
     this_player()->set_temp("astr_gamble/poker",1); 



     return 1 ;
}

int jack()
{
     this_player()->set_temp("astr_gamble/jack",1);

      
     return 1 ;
}

int dice()
{
     this_player()->set_temp("astr_gamble/dice",1); 


     return 1 ;
}

int do_gamble(string arg)
{
    int i,j ;
    string game,cgame,msg,cmsg,mas1,cmsg1 ;
    
    if(!arg) return notify_fail(can_read_chinese()?
                   "玩啥碗糕啊 ??\n":"What do u wanna play?\n");
                         
//    if(lower_case(arg)=="poker")    ;
//    if(lower_case(arg)=="black jack")   ;
//    if(lower_case(arg)=="dice")   ;            
//    else return notify_fail(can_read_chinese()?
//                   "玩啥碗糕啊 ??\n":"What do u wanna play?\n");
                   
    switch(lower_case(arg))                   
     {  
       case "poker" :
                 game = "Poker" ;
                 cgame= "梭哈" ;
                 play_game(game,cgame) ;
                 poker() ;
                 break ;
       case "black jack":
                 game = "Black Jack" ;
                 cgame= "二十一點" ;
                 play_game(game,cgame) ;
                 jack() ; 
                 break ;
       case "dice" :
                 game = "Taiwan Dice" ;
                 cgame= "西八啦" ;
                 play_game(game,cgame) ;
                 dice() ;
                 break ;
       default: return notify_fail(can_read_chinese()?
                  "抱歉,本賭場不提供這種玩法。\n":"Which kind do u wanna play?\n");
                break ;
      }
    
                  
    return 1 ;               
}

