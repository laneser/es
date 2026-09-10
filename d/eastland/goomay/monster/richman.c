
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "Chang the richman", "錢不多" );
        add ("id",({ "chang","richman"}));
        set_short( "錢不多");
        set("unit","個");
        set_level(10);
        set_long(
@C_LONG
你看到一個矮小削瘦的人，他的年紀大約五十來歲，雖然除了一雙炯炯
有神的眼眸之外沒有其他特別引人注意的地方，但是他卻是大名鼎鼎的
本鎮第一首富－錢不多。他最大的興趣就是賺錢，現在他正在和他的手
下討論他們的賺錢計劃，如果沒事的話，你最好不要打擾他們。
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
        set ("tactic_func","kill_me");
}
void disappear()
{
	tell_room(environment(),"錢不多揮揮拳，叫道 : 給我狠狠地揍他 !! 然後就走了。\n",
			this_object());
	this_object()->remove();		
}
int kill_me()
{
	object ob1,ob2,victim;	
	if ( query("killed") ) return 1;
	victim = this_object()->query_attacker();
        tell_room( environment(), 
         "錢不多生氣地叫道：「來人啊 !! 把這個不知死活的傢伙轟出去 !!」。\n"
        ,this_object() );

        ob1 = new(Mob"bodyguard" );
        ob1 ->move( environment() );
        ob2 = new(Mob"watchdog" );
        ob2 ->move( environment() );
		ob1->kill_ob(victim);
		ob2->kill_ob(victim);
		this_object()->set("killed",1);	
		call_out("disappear",2);
        return 1;
}

