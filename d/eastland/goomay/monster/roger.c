
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(12);
        set_name( "Jor the roger", "左無心" );
        add ("id",({ "jor","roger"}));
        set_short( "左無心");
        set("unit","個");
        set_long(
@C_LONG
他就是最近鬧的滿城風雨的大盜左無心，一個十分魁梧的漢子，卻有著
銳利的眼神，他正倚在洞穴的另一端，肆無忌憚的打量著你。
C_LONG
);
        set("alignment",-550);
        set("wealth/gold",30);
        set_perm_stat("str",20);
        set_perm_stat("dex",25);
        set_perm_stat("int",17);
        set_natural_armor( 72, 11 );
        set_natural_weapon( 20, 13, 20 ); 
        set_skill("dodge",65);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
        set( "special_defense", ([ "all": 20 ]) );

        set( "inquiry", ([
                "statue": "@@ask_statue",
        ]) );

}
int ask_statue()
{
        tell_object(this_player(),
	"左無心邪笑道：「知道我在這裡，你就領死吧 !! 任何事對你都不重要了 !!」\n" 
		    );

		command("kill "+(string)this_player()->query("name"));
		return 1;
}
void die()
{
	object killer;
	killer = this_object()->query("last_attacker");
	tell_room( environment(), 
	"左無心慘叫一聲，摔倒在地，再也爬不起來了，他惡狠狠地瞪著你，可是卻無力再戰 ...\n\n" ,
	this_object() );
        tell_object(killer,
@C_STATUE
左無心突然大聲狂笑：「被打敗了 ...哈哈哈 ...你還要問嗎？我說的話你會信嗎？
自從偷了那一尊見鬼的神像後老子就倒了楣了，我真是鬼迷了心竅才會滿屋子金銀財
寶不拿，偏偏抱著那尊神像亂跑，每天被一些奇奇怪怪的妖魔鬼怪追來追去，最後我
被兩隻怪物打敗了，一隻全身冒著火焰，一隻人頭蛇身，他們以為我昏迷了，開始商
量該怎麼利用我，我記得那個聲音，後來我又聽到那個聲音了－在我受審的時候，那
是縣太爺的聲音，這就是我為什麼拼了老命都要逃的原因，小偷被逮大不了幾年牢飯
，可是落在妖怪的手裡... 就算不死也要變成妖怪了。至於那尊神像，早就被他們拿
去了，我還留著它做什麼？妖怪們留我一條狗命，只不過要利用我引開別人的注意力
罷了。信不信由你，老子現在兩手空空，早知道會被王八老吳給賣了。」

他的笑聲越來越低，最後頭一歪，倒在地上，死了 !!
C_STATUE
                        );
        killer->set_temp("meet_jor",1);
	::die(1);

	return;
}
