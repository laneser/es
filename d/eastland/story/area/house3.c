#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("屋子");
	set_long( @LONG
這裡是「羽民族大首領  羽後」居住的小屋。屋子有木製成的桌子、椅子和一
張床，以及一簍簍裝滿著剛採下來和曬乾的葡萄的大型籃子。木桌上有放著幾本書
，是「羽後」畢生學習魔法的心得。小屋中收拾的一塵不染，只不過是簡單的擺設
。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "west" : SAREA"village2" 
        ]) );
        set("no_embattle",1);
        set("objects", ([
             "elder" : SMOB"elder1"
        ]) );
	reset();
}
void init()
{
    if ( this_player()->query("class") != "thief" )
        return ;
    if ( !this_player()->query_temp("hidding"))
        return ;
    if ( (int)random(3) > 1 )
        return ;
    this_player()->delete_temp("hidding");
        call_out("back",1,this_player());
}
void back(object obj)
{
    obj->block_attack(6);
    obj->set_temp("msg_stop_attack",
          "( 你潛行失敗，被敵人突襲，一陣手忙腳亂！ )\n" );
}