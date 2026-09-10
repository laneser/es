#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","少林般若掌習練房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這是一個很寬敞明亮的房間，整個房間瀰漫一股檀香味。由於長久不斷的使用，你發
現地上都是一個個的腳印。    
般若掌是少林七十二絕技中最常被使用和學習的武技，虛合大師修練般若掌已有四十多年
的火候了，你可以放心向他請教。當然牆上的須知(paper) 你不妨先看看。  
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "paper":@BOOK
                         
                           般若掌修習資格

       1. 有七十二絕技僧以上之資格。
       2. 敏捷超過16，力量至少17。  
       3. 基本內功技能至少70。 
                       
       達到以上資格者，可在此習練般若掌(practice bolo-fist)之少林絕技 

       注: 如果你想改練別的絕技，可以用散功 (sangon bolo-fist)，
           你的本絕技經驗點仍會被保留，只是不能用。  
BOOK
       ]));         
	set( "light", 1 );
	set( "exits", ([ 
		"east" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"shi-hur" ]) );
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
	if( !arg || arg != "bolo-fist" ) return 0;
	me = this_player();
	if( undefinedp(me->query("monk_gonfu/bolo-fist")) )
        {	write("虛合搖了搖頭說: 你跟本不曾學過般若掌!\n");
                return 1;
        }
        else {
               write("好吧那我就成全你!!!! \n\n");
               write("虛合大力往你背上一拍，你的般若掌力暫時消失了!!!\n\n");
               write("『放心吧! 下次再來練般若掌時你目前的經驗值並不會失去!』\n\n");
 		me->delete("monk_gonfu/bolo-fist");
 		me->set("monk_learn/72",0);
                return 1;  
              }
} 

int to_study(string arg)
{
	object me;
	if( !arg || arg != "bolo-fist" ) return 0;
	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("你不是本公會的人所以不能學此功夫。\n");
	else if( (int)me->query_level() < 15 )
		write("『虛合曰: 你的職級太低，沒資格學般若掌。\n");
	else if( (int)me->query_perm_skill("inner-force") < 70 )
		write("『虛合曰: 你的基本內功(inner-force)技巧太差，沒資格學般若掌。\n");
	else if( ((int)me->query_perm_stat("str") < 17) ||
			 ((int)me->query_perm_stat("dex") < 16) )
		write("虛合笑道: 你的力量或敏捷不夠，還沒資格學般若掌。\n");
	else if( !undefinedp(me->query("monk_gonfu/bolo-fist")) )
		write("虛合搖了搖頭說: 你已經學過般若掌了，快去多練習吧!\n");
    else if( me->query("monk_learn/72") )
		write("虛合搖一搖頭說: 你已經學過一項絕技了!\n");
    else {
		write(@LONG
	
	『好! 那我現在就教你般若掌的口訣和招式吧』虛合滿意的點點頭道...

     首先先背好內功之要訣... 

     『卻將紛飛之心，以究紛飛之處，究之無處，則紛飛之念何存... 』  
     
     『能照之智本空，所緣之境亦及寂...』
 
     『外不尋塵，內不住定，二途俱茫，一性怡然，此乃般若掌內功之要也。』

     『身法八要... 起落進退反側收縱...』         
     
     『意與氣合，氣與力合，起掌如風，以勇統之...』 
     
     『虛勢中有玄而若虛，實勢中無玄而若實...』 
      ...........................................
      
     『天衣無縫 乃右掌力微而實，左掌力沉而虛...』...
      ..................................
      
      你終於學完了般若掌法...
 
LONG
 		);  
 		me->set("monk_gonfu/bolo-fist", 0);
 		me->set("monk_learn/72",1);
 	}  
    return 1;  
} 
