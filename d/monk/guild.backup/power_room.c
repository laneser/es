#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","少林大力金剛指習練房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這是一個很寬敞明亮的房間，整個房間瀰漫一股檀香味。由於長久不斷的使用，你發
現地上的石板都被磨成黑色的了。    
這個房間居然沒有人在，只在牆上貼了一張紙(paper) 。  
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           大力金剛指修習資格

       1. 有七十二絕技僧以上之資格。
       2. 力量至少18。  
       3. 基本內功技能至少72。 

       本室之空無大師出寺查案，需多日才可回此。                       
       達到以上資格者，可自行在此習練大力金剛指(practice power-finger) 

       注: 如果你想改練別的絕技，可以散功 (sangon power-finger)，
           你的本絕技經驗點仍會被保留，只是不能用。  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"down" : SAULIN"72" ]) );
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
	if( !arg || arg != "power-finger" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/power-finger") ) )
	     { write(" 你跟本不曾學過大力金剛指! \n");
               return 1;
             }
        else {
        write("你的金剛指力暫時消失了!!! \n"); 
 		me->delete("monk_gonfu/power-finger");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 

int to_study(string arg)
{
	object me;

	if( !arg || arg != "power-finger" ) return 0;

	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公會的人所以不能學此功夫。\n");
	else if( (int)me->query_level() < 15 )
		write("『 你的職級太低，沒資格學。\n");
	else if( (int)me->query_perm_skill("inner-force") < 72 )
		write("『 你的基本內功(inner-force)技巧太差，沒資格學。\n");
	else if( ((int)me->query_perm_stat("str") < 17) 
			  )
		write(" 你的力量不夠，還沒資格學大力金剛指。\n");
	else if( !undefinedp(me->query("monk_gonfu/power-finger")) )
		write("你已經學會大力金剛指了，快去練習吧!\n");
    else if( me->query("monk_learn/72") )
		write("你已經學過一項絕技了!\n");
    else {
		write(@LONG
	
     你翻開 大力金剛指 密笈，開始細細讀了起來... 

     首先先背好內功之要訣... 

     『一切有為法，如夢幻泡影，如霧亦如電，應做如是觀... 金剛波羅密心經 』  
     
     『能剛之力本空，所緣之氣亦寂...』
 
     『外但尋塵，內亦住定，二途俱茫，一性怡然，此乃大力金剛指內功之要也。』

     『意與氣合，氣與力合，起指如風，以勇統之...』 
     
     『虛勢中有玄而若虛，實勢中無力而若實...』 
      ...........................................
      
     『金剛破魔力，乃本指力之終式... 形蘊而力含......』...
      ..................................
      
      你終於學到了 大力金剛指...
 
LONG
 		);  
 		me->set("monk_gonfu/power-finger", 0);
 		me->set("monk_learn/72",1);
 	}  
    return 1;  
} 
