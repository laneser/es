#include "../goomay.h"
#include <stats.h>
#include <move.h>
inherit MONSTER ;
inherit DAEMON ;

string *c_msg = ({
"老醫生說 ：「什麼？你出疹？我看沒有啊？」\n",
"老醫生說 ：「要出診啊？真的是重病嗎？老夫老嘍，體力不夠了，嗯 ..\n"+
  "救人一命 ... 好吧 !! 你帶路 !! 老夫若是體力不濟會自己回來的。」\n" ,
"老醫生說 ：「誰生小孩啦？我老啦 !! 沒力氣接生了 !!」\n",
"老醫生說 ：「過來 !! 眼睛張開.. 嗯 ...耳朵過來.. 啊～～～～～煩死了」\n",
"老醫生說 ：「你說什麼？」\n",
"老醫生說 ：「別老是問啊 !! 我老人家這不是跟著你了嗎？」\n",
"老醫生說 ：「咦 !! 我記得漁夫小乙的病不是好了嗎？你耍我啊 !!」\n",
});
string *msg = ({
"The Doctor says : What ?? you get sick ?? Hmm.. I don't think so ...\n",
"The Doctor says : Goto help others ? ok !! I will follow you ! \n",
"The Doctor says : Who take baby ?? Oh ! no ! I am no more young ..\n",
"The Doctor says : well !! your eyes .. open .. good ..ears .. WAAAAAAA\n",
"The Doctor says : Excuse me ??\n",
"The Doctor says : Okok ! I am coming !! don't ask same question all the way\n",
"The Doctor says : Hmm .. I remember Fishman is pretty health now !! \n",
});

void create()
{
	::create();
	set_level(16);
        set_name( "Old doctor", "老醫生" );
        set_short( "Old doctor", "老醫生" );
	add( "id", ({ "doctor" }) );
	set_long(
		"You see a very old doctor.\n",
@C_LONG
你看見一個年紀很大的老醫生，他銀白色的眉毛長長的垂在眼睛的兩側，
眯眯的眼睛幾乎都快看不見東西了，他似乎有些糊塗，可是脾氣卻強的
很，本鎮的大財主錢不多屢次出高價要買下他的藥鋪，他說什麼也不讓，
真不知道他是不是得了老年痴呆症。
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
	set_perm_stat("str",25);
	set_perm_stat("con",25);
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "dagger", 75 );
        set_skill( "anatomlogy", 80 );
	set("defense_type","dodge");
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 400 );
        set( "hit_points", 400 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "all": 30,"none":20]) );
        set( "alignment", 1500 );
	set("pet_master","xxyyxx");
        set( "wealth/gold", 50 );

        set( "inquiry", ([
                "out" : "@@ask_out",
                "heal": "@@ask_heal",
		"clot": "@@ask_clot",
		"cure": "@@ask_cure",
		"jor" : ({ "EMPTY.\n",
@LEG
嗯 !! 傷了腿的人啊 ～～ 對了，前幾天夜裡有一個大漢跛著
腳來找我，他的雙腿腿骨都被打折了，可是他居然還能自己走來，而且一如常
人，我覺得他可能是輕功高手，有練過類似草上飛之類的輕功，在我幫他接好
斷腿之後他就走了，沒有回來過，不過依他的狀況來看，斷腿之後又強行運功\
奔行，縱然有我接骨，若要保住一身輕功不失，可能要休息半個月以上，他肯
定走不遠。對了 !! 最近怡紅院的王八老吳(wu)常常來抓治筋骨損傷的藥，不
知道跟他有沒有關係。
LEG
		})
        ]) );
        wield_weapon( Obj"silvery_dagger" );
        equip_armor( Obj"healer_robe" );

}

void relay_message(string class1, string msg)
{
        string who,dir,master;
master=(string)this_object()->query("pet_master");

if( sscanf( msg, "%s leaves %s.\n", who,dir )==2 && lower_case(who) == master)
        {
        command("go "+lower_case(dir));
        if ((string)environment(this_object())->query("c_short")=="破落的小屋")
	{
        tell_room( environment(), ({
        "The Doctor begin to diagnose for the poor fishman ....\n"+
	"After he finish his job, he says : He is in dangerous , you save his life\n"+
	"and he will recover . \n",
        "老醫生一個箭步衝上前去開始為可憐的漁夫把脈，然後用極快的手法取出\n"+
	"幾枚銀針紮在漁夫的身上，併為他作緊急的心肺按摩，果然，漁夫發出了\n"+
	"幾聲呻吟慢慢的從無盡的昏迷中醒了過來，醫生趁機□了他幾味藥。一面\n"+
	"回頭對你說：「還好有你，不然他這條小命就報銷了，不過他的情況還是\n"+
	"很危險，他的病倒是不難治，問題是他太虛弱了，恐怕藥力不易發揮，你\n"+
	"要好好照顧他，我會常常過來看看的」說完，他留下一些藥，說明了服用\n"+
	"的方法後就走了。\n" }),
        this_object() );
        tell_object(this_player(),can_read_chinese() ?
        "於是你留下來照顧病人，在你的細心照料下，漁夫也慢慢的恢復健康。\n"+ 
	"漁夫對你十分感激，願意隨時聽候你的差遣 !! \n" :
	"So you stay and take care the fishman . under your care , the fishman recover \n"+
	"very well and want to do anything for you . ");

        this_player()->set("goomay/fishman",1);
        set("pet_master","xxyyxx");
        set("tired",1);
        call_out("tired", 120,this_object());
        this_object()->move(Goomay"plaster_shop");

	}
        return;
	}
        return;
}

int tired(object who)
{
	tell_room( environment(), ({
	"The Doctor wake up and look not so tired.\n",
	"老醫生打了個哈欠，伸伸懶腰，看起來精神好多了 !!\n" }),
	this_object() );
        set("tired",0);
        return 1;
}

int back_home(object who)
{
	tell_room( environment(), ({
	"The old Doctor sighs and says : I am too old !! need some rest .\n",
	"老醫生苦笑著說道：「啊 ! 老頭子累了 !! 得回去休息休息。」，他自己回去了。\n" 
	}),this_object() );

        set("pet_master","xxyyxx");
	set("tired",1);
	call_out("tired", 300,this_object());
        this_object()->move(Goomay"plaster_shop");
        return 1;
}
int check_plaster()
{
	if (this_player()->query_temp("green_pearl") 
	    || this_player()->query("goomay/fishman"))
	return 1;
        tell_room( environment(), ({
        "The old Doctor sighs and says : I hope I can help you .. but I need herb.\n",
        "老醫生苦笑著說道：「不是老頭子不肯幫你，而是店裡沒藥，我一點辦法也沒有。」\n"
	}),this_object() );
	return 0;
}
int check_tired()
{
        if ((int)this_object()->query("tired")==1)
	{
        tell_room( environment(), ({
        "The Doctor looks very tired and fall asleep ! please don't wake him.\n",
        "老醫生看起來很疲勞，正在打盹，你最好別吵他 !!\n" }),
        this_object() );
        return 0;
	}
	return 1;
}
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), ({
        "The doctor says: Damn !! You ask me heal such a killer like you ? \n",
        "醫生怒道: 不要臉的兇手 !! 打我還叫我醫你 !! 豈有此理 ! \n" }),
        this_object() );
        return 1;
	}
	return 0;
}

int ask_out()
{
	int i;
	string who;

	if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
	if (!check_plaster()) return 1;
        i=random(5);
	who=(string)this_player()->query("name");
        if ((string)this_object()->query("pet_master") == who)
	{
		tell_object(this_player(),can_read_chinese() ?
			    c_msg[5] : msg[5]);
		return 1 ;
	}

	tell_object(this_player(),can_read_chinese() ?
		    c_msg[i]: msg[i]);

		if (i==1)
		{
		if (this_player()->query("goomay/fishman"))
			tell_object(this_player(),can_read_chinese() ?
				    c_msg[6]: msg[6]);
		else
		{
			set("pet_master",who);
			call_out("back_home", 30,this_player());
		}
		return 1 ;
		}
		return 1 ;
}

int ask_heal()
{
int num,hpmax,hp;

	if (!check_tired()) return 1;
	if (query("hit_points") < query("max_hp"))
	{
        tell_room( environment(), ({
        "The doctor says: Sorry !! I must heal myself first.\n",
        "醫生說道: 哎呀呀 !! 我什麼時候受的傷？趕快包一包 !! ... \n"+
	"他開始手忙腳亂的包紮自己，突然間頭一點，咦 ？ 睡著了 ？？\n"}),
        this_object() );
	set("hit_points",query("max_hp"));
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;
	}
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;
	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), ({
	"The doctor says: You are pretty health.\n",
	"醫生說道: 我看你頭腦有問題 !! 想耍我 ... \n" }),
	this_object() );
	return 1;
	}
	num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
	"醫生搖搖頭道：「你沒有那麼多金幣。」\n": 
	"The doctor shakes his head and say  :You don't have that many gold coins.\n" );

	tell_room( environment(), ({
	"The doctor says: ok !! let me heal you ... he utter a strange word\n"
	"and you feel all your wound are cured !!\n",
	"醫生說道：「好 !! 看我的 !」他輕聲的唸誦一段奇特的咒文，你突然感到\n"+
	"全身精力充沛。他笑咪咪的看著你，突然間頭一點，咦 ？ 睡著了 ？？\n" }),
	this_object() );
	this_player()->set("hit_points",hpmax);
	set("tired",1);
	call_out("tired", 300+random(90),this_object());
	return 1;

}
int ask_cure()
{
int num;

        if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;
        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/simple_poison"))
        {
        tell_room( environment(), ({
        "The doctor says: You are pretty health.\n",
        "醫生說道: 我看你頭腦有問題 !! 想耍我 ... \n" }),
        this_object() );
        return 1;
	}
        num=20;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
        "醫生搖搖頭道：「你沒有那麼多金幣。」\n":
        "The doctor shakes his head and say  :You don't have that many \n"+
	"gold coins.\n" );

        tell_room( environment(), ({
        "The doctor says: ok !! let me heal you ... he utter a strange word\n"
        "and you feel your poison are cured !!\n",
        "醫生說道：「好 !! 看我的 !」他取出幾支金針飛快地紮在你的穴道上，你感到\n"+
	"體內毒素神奇地消失。他笑咪咪的看著你，突然間頭一點，咦 ？ 睡著了 ？？\n" }),
        this_object() );
        this_player()->delete("conditions/simple_poison");
        set("tired",1);
        call_out("tired", 240+random(60),this_object());
        return 1;

}

int ask_clot()
{
int num;

        if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;

        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/bleeding"))
        {
        tell_room( environment(), ({
        "The doctor says: You are pretty health.\n",
        "醫生說道: 我看你頭腦有問題 !! 想耍我 ... \n" }),
        this_object() );
        return 1;
	}
        num=10;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
        "醫生搖搖頭道：「你沒有那麼多金幣。」\n":
        "The doctor shakes his head and say  :You don't have that many gold coins.\n" );

        tell_room( environment(), ({
        "The doctor says: ok !! let me heal you ... he utter astrange word\n"
        "and you feel your bleeding have stop !!\n",
        "醫生說道：「好 !! 看我的 !」他細心的為你包紮傷處，你的失血漸漸地\n"+
	"停止了。他笑咪咪的看著你，突然間頭一點，咦 ？ 睡著了 ？？\n" }),
        this_object() );
        this_player()->delete("conditions/bleeding");
        set("tired",1);
        call_out("tired", 240+random(60),this_object());
        return 1;

}
