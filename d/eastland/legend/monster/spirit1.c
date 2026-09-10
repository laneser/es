#include "../legend.h"
#include "../magic.c"

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "wood spirit","神木上人" );
	add ("id", ({"spirit"}) );
	set_short("神木上人");
	set_long(@C_LONG
你眼前所見是一位面目慈祥，和靄可親的老者。雖然，他看起來約有六、七十歲的
年紀，卻感受不到任何蒼老的訊息，反而帶給你一種活潑的泉源。神木上人原本是
天界的仙人，但八百年前犯了過錯因而被貶下凡間，他似乎遇到麻煩了，因而眉目
深鎖。
C_LONG
	);
        set("be_asked",0);
	set("unit", "名" );
        set("no_attack",1);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        set( "inquiry", ([
             "mistake":"@@ask_mistake",
             "過錯":"@@ask_mistake",
             "trouble":"@@ask_mistake",
             "麻煩":"@@ask_mistake"
        ]) );
}
void ask_mistake( object asker )
{
     object lock;
     if ( query("be_asked") ) {
        tell_room(environment(this_object()),
         "神木上人說道:我把鐵鎖交給別人了，希望你們一們合力消除了「無支祈」。\n");
        return ; 
     }
     set("be_asked",1);
write(@C_LONG
神木上人嘆道:八百年前，我一時疏乎把水怪「無支祈」給放出，因此被貶下凡間。
 　　　　　　一直以來，因為我神功未成，屢次挑戰「無支祈」都沒辦法使那支畜
 　　　　　　牲伏誅，希望你能幫助我。對了，當你殺死「無支祈」之後記得拿鐵
 　　　　　　鎖 ( iron_lock ) 它，不然它又會活過來。大恩不言謝。

神木上人從身上掏出一件大鐵鎖。
C_LONG
      );
      lock=new(LITEM"iron_lock");
      lock->move(environment(this_object()));  
      call_out("recover",300,this_object());
}
void recover(object obj)
{ obj->set("be_asked",0);}
