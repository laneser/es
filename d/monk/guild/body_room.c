#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("少林金剛不壞體神功習練房");
	set_long( @LONG_DESCRIPTION
一進入房間，你的目光首先被房中一個看起來很瘦的老僧所吸引，角落中用草書
寫著『少林金剛不壞神功』。你可以發現大部份的絕技都是攻擊用的，少數如金剛不
壞體神功則是純粹防禦用的功夫。要學哪一種則完全是你的選擇了。 
牆邊貼了一張的紙條(paper)，上面似乎寫了一些字，北邊可回七十二絕技房。
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper" : @BOOK
                         
                           金剛不壞體神功修習資格

       1. 有七十二絕技僧以上之資格。
       2. 敏捷到達18。  
       3. 個性溫和，不喜濫造殺孽者。       

       達到以上資格者，可在此習練金剛不壞體神功\(practice body-def)

       注: 如果你想改練別的絕技，可以用散功\ (sangon body-def)，
           你的本絕技經驗點仍會被保留，只是不能用。  
BOOK
	]) );
	set("light", 1 );
	set("exits", ([ 
		"north" : SAULIN"72" ]) );
	set("objects", ([
		"Monk" : SAULIN_MONSTER"kon-gem" ]) );
	reset();
}

void init()
{
	add_action("to_study", "practice");
	add_action("to_delete","sangon");
}

int to_delete(string arg)
{
	object me;
	if( !arg || arg != "body-def" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/body-def") ) )
	     { write(" 你跟本不曾學過金剛不壞體神功\! \n");
               return 1;
             }
        else {
        write("你的金剛不壞體神功暫時消失了!!! \n"); 
        write("但如重練時舊經驗值仍然不變 \n\n"); 
 		me->delete("monk_gonfu/body-def");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;
	
	if( !arg || arg != "body-def" ) return 0;

	me = this_player();	
  	if( !wizardp(me) && (string)me->query("class") != "monk" )
  		write("你不是本公會的人所以不能學此功夫\。\n");
  	else if( (int)me->query_level() < 15 )
		write("空見搖頭說: 你的位階太低，不該練金剛不壞體神功\。\n\n");
	else if( (int)me->query_perm_stat("dex") < 18 )
		write("空見說: 你的敏捷不夠，沒辦法教你。\n\n");
	else if( (int)me->query("alignment") < 1000 )
		write("空見合十道: 阿彌陀佛... 施主殺孽太重, 不宜習此武功\!。\n\n" );
	else if( !undefinedp(me->query("monk_gonfu/body-def")) ) {
		if((int)me->query("monk_gonfu/body-def")==35) {
			write("空見說道: 你已經完全瞭解金剛不壞體神功的精義了，可以再去鑽研另一種絕技。\n\n");
			me->set("monk_learn/72",0); }
		else write("空見嘆了一口氣說: 你已經學過金剛不壞體神功了，要專精就快去練習!。\n\n" ); }
        else if( me->query("monk_learn/72") )
		write("空見雙手合十道: 不行，你已經學過一項絕技了。\n\n" );
	else {
		write( @LONG

  好! 那我現在就教你金剛不壞體神功的口訣吧! 空見笑道:
   
      身法八要... 起落進退反側收縱...
      
      足法... 起落翻掙，忌踢宜踩....
      
      意與氣合，氣與力合，起身如風，以意統之...
      ...........................................
      
      虛勢中有玄而若虛，實勢中無玄而若實....
      ...........................................
      
      御氣於檀中，駕意於百匯，屯神於氣海.....
      
      空見大師一句句的向你解釋著練功的要訣...                
      ..................................

      你終於學完了金剛不壞體神功了...
      
LONG
		);
		me->set("monk_gonfu/body-def", 0);
		me->set("monk_learn/72", 1);
	}
	return 1;
} 
