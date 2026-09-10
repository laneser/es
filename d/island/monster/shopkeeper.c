#include <mudlib.h>
#define ISLAND "/d/island/"
#define IOBJ  "/d/island/obj/"

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	object ob1,ob2,ob3,ob4; 

	::create();
	set_level(1);
	set_name("Shopkeeper","錢掌櫃");
	add("id",({"keeper"}) );
	set_short("錢掌櫃");
	set_long(@LONG
錢掌櫃是為約莫四十出頭的中年男子，嘴邊掛著一撮小鬍子，外加兩顆咪咪眼
，十足的精明幹練模樣。不過他的脾氣有點古怪，外傳他曾是風聞一時的大盜
，所以最好不要問他有關小偷(thief) 的事情哦，免得他動怒！另外呀，他觀
察力可是一流的哦，能在短時間內算清你身上所有的傷痕(scar)哦，那怕是衣
服遮住的，一樣無法逃出他的慧眼！
LONG
		);
	set("unit","位");
	set("gender","male");
	set("alignment",-500);
	set("race","daemon");
	set("no_attack",1);
	set("inquiry",([
			"thief":"@@ask_thief",
			"scar" :"@@ask_scar",
			]) );
/*	set("aiming_loc","critical");
	ob1=new(IOBJ"boots03");
	ob1->move(this_object());
	ob2=new(IOBJ"cloth02");
	ob2->move(this_object());
	ob3=new(IOBJ"armband01");
	ob3->move(this_object());
	ob4=new(IOBJ"dagger01");
	ob4->move(this_object());        
*/
}
void ask_thief()
{
    write("錢老闆說:我不幹大哥已經很久了, 懶得理你！\n");
    return;
}
    
/*void ask_thief(object victim)
{
	object env;

        if(query_attackers()) return ;
	env = environment(this_object());
	if( victim->query_level() < 8 ) {
		tell_object( victim,"錢掌櫃拍拍你的肩膀說: 小孩子要學好，別學做小偷喔。\n" );
		return 0;
	}
	write( "錢掌櫃臉色一沉，突然他丟下一煙霧彈，一道煙霧後只見一團黑影向你衝了過來！！\n" );
	tell_room( env,"\n突然一陣煙霧，只見一道黑影向"+victim->query("c_name")+"撲了過去！\n",victim );
	tell_room( env,"錢形次郎掏出隨身的扁鑽。\n" );
	tell_room( env,"錢形次郎從櫃檯後面拿出幾件東西戴上。\n" );
	set_skill( "dagger",100 );
	command( "wear all",this_object() );
	command( "wield daggercheck",this_object() );
	set_level(18);
	set( "aim_difficulty",([ "weakest":35,"vascular":30,"ganglion":30 ]) );
	set( "stun_difficulty",30 ) ;
	set_perm_stat( "con",20 );
	set_perm_stat( "str",23 );
	set_perm_stat( "dex",22 );
	set_perm_stat( "kar",22 );
	set_perm_stat( "pie",30 );
	set( "max_hp",650 );
	set( "hit_points",650 );
	set_name( "Great Thief","錢形次郎" );
	add("id",({ "thief" }) );
	set_short( "大盜  錢形次郎" );
	set_long(@LONG
原來錢掌櫃果真是風聞一時的妙手大盜啊，只見他全身勁裝，一幅
氣急敗壞的模樣，臂上綁了一條手巾，寫了四個字『一生懸命』。
LONG
		);
	set( "no_attack",0 );
	set( "c_killer_msg","\n突然一陣煙霧，只見一道黑影向你撲了過來！\n" );
	set( "tactic_func","my_tactic" );
	set_skill( "dodge",100 );
	set_skill( "anatomlogy",100 );
	set( "chat_chance",20 );
	set( "att_chat_out",({
	"錢形次郎大喝: 臭小子，竟敢道破我最不想讓人知道的過去，我給你″死″！！\n"
			}) );
	set_natural_weapon( 45,25,40 );
	set_natural_armor( 65,30 );
	set( "special_defense",(["mental":90,"cold":80,"evil":70,"fire":65,"none":55,"energy":15])); 
	kill_ob( victim );
	set( "killer",1 );
} 

int my_tactic()
{
	object env,victim;
	string him;
	
	env = environment(this_object());
	if( !(victim=query_attacker()) ) return 0;
	him = victim->query("c_name");
	if( random(20) < 2){
		tell_object(victim,"\n錢形次郎順手一揮，數枚暗器向你射了過來，但都被你接住了.......\n"
				   "哇～～金幣耶，快收起來！\n\n" );
		tell_room( env,"\n錢形次郎偷偷地向"+him+"放暗器。奇怪？！"+him+"被打到竟然在偷笑！\n\n",victim );
		victim->add( "wealth/gold",2 );
		return 1;
	}
	
	else if( random(25) < 5){
		tell_object( victim,"\n突然「咻咻咻」數聲，次郎手中射出幾件暗器打在你身上，哇！好痛！！\n\n" );
		tell_room( env,"\n錢形次郎順手一揚，數件暗器激射而出，全打在"+him+"身上！\n\n",victim );
		victim->receive_special_damage("evil",30);
		report( victim );
		return 1;
	}
	else return 0;
}

void ask_scar()
{
	int jus;
	
	jus = (int)this_player()->query("justice");
	if( !jus ){
		write( "錢掌櫃指著你大笑道：你全身乾乾淨淨的, 一點傷痕也沒有, 你真的是勇者嗎?????\n" );
		return ;
	}
	write( "錢掌櫃拍手稱讚說：哇!!閣下全身上下佈滿大小傷痕"+jus+"道, 乃真神人是也!!\n" );
	return ;
}
*/