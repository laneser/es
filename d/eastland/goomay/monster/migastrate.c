#include "../goomay.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level( 9 );
        set_name( "Shu the migastrate of goomay", "縣太爺" );
        add( "id", ({ "migastrate","shu" }) );
        set_short( "縣太爺" );
        set_long(
@LONG
他就是現任的古梅鎮縣太爺－史耀前，肥肥胖的身材配上眯眯的眼睛，你不禁
有些懷疑他是不是真的只認識錢，雖然如此，當年他可是三元及第的紅狀元，
還娶他的恩師－步太師的女兒瑤蓮小姐，可是當時讀書人的羨慕對象。他這幾
年升官不多、發財不少，十足的財運亨通。
LONG
        );
        set( "gender", "male" );
		set("race","elf");
        set_natural_armor( 40, 10 );
        set_natural_weapon( 20, 9, 22 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set("tactic_func","kill_me");
        set( "hit_points", 200 );
        set( "max_hp", 200 );
		set( "wealth/gold",30);
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
                "statue"  : "@@ask_statue",
        ]) );

}
void disappear()
{
	tell_room(environment(this_object()),"縣太爺趁亂溜到內堂了。\n",this_object());
	this_object()->remove();
}
int kill_me()
{
    object ob1,ob2,victim;
    if ( query("killed") ) return 1;
    victim = this_object()->query_attacker();
    tell_room( environment(this_object()),
   		"站在一邊的捕快叫道：「竟敢對太爺不禮貌 !! 兄弟們 !! 把這個不知死活的傢伙砍成八塊 !!」。\n"
      ,this_object() );
                                                 
 	ob1 = new(Mob"cop" ); 
 	ob1 ->move_player( environment(this_object()), "SNEAK" ); 
 	ob2 = new(Mob"cop");
    ob2 ->move_player(environment(this_object()), "SNEAK" );
	ob1 -> kill_ob(victim);
	ob2 -> kill_ob(victim);
	this_object()->set("killed",1);
	call_out("disappear",2);
	return 1;  
}
int ask_statue()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue") > 2 )
        {
	tell_object(me,
	"縣太爺道：「月神像不是已經找回來了嗎？不過還是謝謝您救我一命 !!」\n"
		);
	return 1;
	}
        else
        {
	if (this_player()->query_temp("meet_jor"))
	{	
        tell_object(me,@C_STATUE
縣太爺用一種很興奮的眼光看著你道：「嘿嘿 !! 左無心那□的話也能信嗎？欽差
大人啊 !! 你要怪就要怪你生了一副聰明腦袋吧 ... 哈哈哈 !!! 」他獰笑著向你
走過來，身上漸漸冒出一陣陣的火花，驀然，「轟隆」一聲，他變身成為一隻渾身
冒著火焰的怪物。
C_STATUE
        );
        clone_object( Mob"fire_monster" )->move_player(environment(this_object()), "SNEAK");
        me->remove();
                return 1;
	}
	else
	{
        tell_object(me,@C_STATUE
縣太爺用一種很遲緩的語調說道：「大人 !! 左無心那□窮兇極惡，下官已經通令
各捕房全力追捕了，大人代天巡守，日理萬機，本鎮穿窬小賊之事，就請大人不用
掛懷，小縣一定盡力辦案以報天恩。」
C_STATUE
        );
                return 1;
	}
}
}
