
#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("少林龍爪手習練房");
	set_long( @LONG_DESCRIPTION
這是一個寬闊的大房間，牆上龍飛鳳舞的寫著一個『龍』字，你發現牆壁和樑柱上有
許多被強勁指力劃過的痕跡。
角落坐著一個高大的僧人，地上放著幾塊破舊的蒲團，老僧似乎完全沒有注意到你的存在
 ，仍然在閉目打坐運功\。你發現牆邊貼了一張泛黃的紙片(paper)，上面似乎寫了一些字
。老僧打坐的蒲團邊放著一本書，你隱約看到有個龍字。西邊回到七十二絕技房。 
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           龍爪手修習資格

       1. 有七十二絕技僧以上之資格。
       2. 敏捷超過16，力量至少16。  
       3. 基本內功技能至少72。 
                       
       達到以上資格者，可在此習練龍爪手(practice dragon-claw)之少林絕技 

       注: 如果你想改練別的絕技，可以用散功\ (sangon dragon-claw)，
           你的本絕技經驗點仍會被保留，只是不能用。  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"west" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"kon-shin" ]) );
	reset();
}

void init()
{
	add_action("to_study","practice");
	add_action("to_delete","sangon");
}

int to_delete(string arg)
{
	object me;
	if( !arg || arg != "dragon-claw" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/dragon-claw") ) )
	     { write(" 你跟本不曾學過龍爪手! \n");
               return 1;
             }
        else {
        write("你的龍爪手功力暫時消失了!!! \n"); 
        write("但如重練時舊經驗值仍然不變 \n\n"); 
 		me->delete("monk_gonfu/dragon-claw");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;

	if( !arg || arg!="dragon-claw") return 0;

	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公會的人所以不能學此功夫\n");
    else if( (int)me->query_level() < 15 )
		write("『空性說: 你的等級太低，沒資格學龍爪手』\n\n");
    else if( (int)me->query_perm_skill("inner-force") < 72 )
		write("『空性說: 你的基本內功\(inner-force)技巧太差，沒資格學龍爪手』\n\n");
    else if( ((int)me->query_perm_stat("str") < 16) ||
    		 ((int)me->query_perm_stat("dex") < 16) )
		write("『空性說: 你的力量或敏捷不夠，沒資格學龍爪手』\n\n");
	else if( !undefinedp(me->query("monk_gonfu/dragon-claw")) ) {
		if((int)me->query("monk_gonfu/dragon-claw")==35) {
			write("空性說道: 嗯，你學的還不錯。好吧，讓你再去練別種絕技。\n\n");
			me->set("monk_learn/72",0); }	
		else write(" 空性從圃團上看看你，大罵一聲:\n"
			"『你真白痴啊! 你已經學過龍爪手了，要專精就快去練習啊!』\n\n" ); }
	else if( me->query("monk_learn/72") )
		write(" 空性從圃團上看看你，大罵一聲:\n"
			"『你真貪心啊! 你已經學過一項絕技了，快去練習啊!』\n\n" );
	else { 
		write( @LONG

  『好! 那我現在就教你龍爪手的口訣和招式吧』空性站起來笑道...
 
     『身法八要... 起落進退反側收縱...』
              
     『足法... 起落翻掙，忌踢宜踩.....』
     
     『意與氣合，氣與力合，起爪如風，以勇統之...』 
      ........................................... 
 
     『虛勢中有玄而若虛，實勢中無玄而若實...』 
      ........................................... 
      
     『飛龍搶珠下返上』，『神龍撈月環圈探』... 
     
     『補風捉影勢如風』....                
      .................................. 
      
      你終於學完了三十六式龍爪手了...
      
LONG
		);  
        me->set("monk_gonfu/dragon-claw", 0);
        me->set("monk_learn/72",1);
	}
	return 1;  
} 

int clean_up() { return 1 ;}
