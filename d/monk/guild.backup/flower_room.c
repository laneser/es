#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","少林拈花指功習練房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
佛祖拈花微笑，以此為名創此指法，講究的是王道平和慈悲，制敵而不殺人。   
這是一間比較小但很溫暖的房間，整個房間瀰漫一股寧靜祥和的味道。角落坐著一
位胖胖的和尚，他滿臉的笑容宛如一尊彌勒佛。木牆上有許多的小洞，看來似乎是  
被某種暗器刺穿的痕跡，難道這就是久聞的拈花指力?   在向這位傳功師父請教前
你可以先看看一邊的白紙(paper) 。南方可回去七十二絕技房。    
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           拈花指修習資格

       1. 有七十二絕技僧以上之資格。
       2. 心地平和，不好勇鬥狠者。      
       3. 力量至少須達到20。      
         
       達到以上資格者，可在此習練拈花指(practice keep-flower)之少林絕技 

       注: 如果你想改練別的絕技，可以用散功\ (sangon keep-flower)，
           你的本絕技經驗點仍會被保留，只是不能用。  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"kon-fan" ]) );
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
	if( !arg || arg != "keep-flower" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/keep-flower") ) )
	     { write(" 你跟本不曾學過捻花指! \n");
               return 1;
             }
        else {
        write("你的捻花指力暫時消失了!!! \n"); 
        write("但如重練時舊經驗值仍然不變 \n\n"); 
 		me->delete("monk_gonfu/keep-flower");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;

	if( !arg || arg != "keep-flower") return 0;
	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公會的人所以不能學此功夫\n");
    else if( (int)me->query_level() < 15 )
		write("『空凡笑道: 你的職級太低，還不該學拈花指』\n\n");
    else if( (int)me->query_perm_stat("str") < 20 )
		write("『空凡笑道: 你的力量仍稍有不足』\n\n");
	else if( !undefinedp(me->query("monk_gonfu/keep-flower")) )
		write(" 空凡笑道:\n"
			"『你已經學過拈花指了，我已不能多教你什麼，快去多練習吧!』\n\n" );
	else if( me->query("monk_learn/72") )
		write("空凡搖一搖頭笑著說\n"
			"『你已經學過一項絕技了!武學在精不在多啊!』\n\n" );
	else {
		write(@LONG

  『好! 那我現在就教你拈花指的口訣和招式吧』空凡滿意的點點頭道...

      首先先背好內功之要訣... 
      
     『力源於心，惟取極靜，由靜力固，永斷煩惱... 』  
     
     『人生之遇本空，所緣之境亦如虛無之境...』  
     
     『以寂滅力，資於至靜，寂靜思惟，修行如是，此乃拈花指內功之要也。』

     『身法八要... 起落進退反側收縱...』         
     
     『意與氣合，氣與力合，起指如風，以仁統之...』 
     
     『虛勢中有玄而若虛，實勢中無玄而若實...』 
      ........................................... 
      
      空凡大師右手食中二指輕輕搭住，做拈花之狀。溫和的向你說明武功細節... 
      .................................. 
      
      你終於學完了捻花指法...心中一片祥和寧靜 
      
LONG
		);  
        me->set("monk_gonfu/keep-flower", 0);
        me->set("monk_learn/72",1);
	}  
	return 1;  
}
