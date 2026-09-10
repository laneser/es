#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓二樓" );
   set_long(@ANGEL
在你來到千川樓二樓，這裡的構造和一樓比起來大致相同，只是通道變窄了
許多，據說這是為防止敵人大量入侵而設計的，地板改成用較易發出聲音的木材
做成，只要有人一進入二樓，其發出的聲音一定會被在二樓守衛的武士們聽見，
空氣中還飄有一股黑檀木的香氣．
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"zark":MOB"zark"
	]));		
        set( "exits", ([
    "up"  :MR"inn3-1",    
    "south" :MR"inn2-5",
                ]) );
        set("pre_exit_func",([
        "up":"to_up"
        ]));                            
         reset();                     
}
int to_up()
{
 if(!present("zark")){
 return 0;
 }
else{
 write(@AAA
 札克站在你面前擋住你，並說道：小子．你不把我當人呀!隨隨便便就想上去!
AAA
 );
 return 1;
 }
 }
 
