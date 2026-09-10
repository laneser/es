#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士團副隊長室" );
   set_long(@ANGEL
在你來到武士團副隊長星卡的住所，雖說星卡是武士城堡中的第二號
人物，但是他的住所卻非常的樸素，只有一張床和桌椅，沒有其他多餘的
傢俱，牆上則是掛滿了感謝狀，這些都是星卡立功時所得到的獎勵，床的
旁邊則是星卡收放防具的箱子．
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"si_ka":MOB"si_ka"
	]));		
        set( "exits", ([
    "south"  :MR"inn04",    
                ]) );
                            
         reset();                     
}

