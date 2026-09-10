#include <../goomay.h>
inherit MONSTER ;

void create()
{
	::create();
	set_level(16);
        set_name( "Old doctor", "老醫生" );
        set_short( "老醫生" );
	add( "id", ({ "doctor" }) );
	set_long(
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
        set( "aiming_loc", "weakest" );
        set( "max_hp", 500 );
        set( "hit_points", 500 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 15 );
        set( "natural_min_damage1", 2 );
        set( "natural_max_damage1", 12 );
        set( "special_defense", ([ "all": 40,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 50 );

        set( "inquiry", ([
                "heal":  "@@ask_heal",
		"hunter" : "@@ask_hunter",
		"jor" : 
@LEG
嗯 !! 傷了腿的人啊 ～～ 對了，前幾天夜裡有一個大漢跛著
腳來找我，他的雙腿腿骨都被打折了，可是他居然還能自己走來，而且一如常
人，我覺得他可能是輕功高手，有練過類似草上飛之類的輕功，在我幫他接好
斷腿之後他就走了，沒有回來過，不過依他的狀況來看，斷腿之後又強行運功\
奔行，縱然有我接骨，若要保住一身輕功不失，可能要休息半個月以上，他肯
定走不遠。對了 !! 最近怡紅院的王八老吳(wu)常常來抓治筋骨損傷的藥，不
知道跟他有沒有關係。
LEG
        ]) );
        wield_weapon( Obj"silvery_dagger" );
        equip_armor( Obj"healer_robe" );

}

int accept_item(object me,object item)
{
	object ob1;
     if ((string) item->query("name") !="amaze root" )
        {
     tell_object(me,
        "老醫生搖搖頭：「謝謝 !! 我不需要這東西 !!」\n");
	command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
@MISSION
老醫生接過藥草，很仔細的看看，然後滿意的點點頭，就開始東抓西抓的配起
藥來，只不過一晃眼的功\\夫，他就包好了幾個大藥包。他把藥包遞給你，然後
道：「吃了這幾帖藥，病人應該就可以起床活動了，趕快給他送去吧 !!」
MISSION
        );
        ob1 = new( Obj"drug_pack" );
	ob1->move(this_object());
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
}

int ask_hunter()
{
	if ( (int)this_player()->query_quest_level("Goddess_statue") > 0 )
	tell_object(this_player(),
	"老醫生搔搔頭說：「誰又病了？我記得我給過你藥了啊 !!」\n");
	else
        tell_object(this_player(),
	"老醫生嘆口氣道：「獵人阿三的病我很清楚啊，但是缺了一味主藥－奇異花的根\n"
	"(root)聽說綠珠姑娘有種了幾棵，可是老頭子我見不著她啊 !!」\n");
		return 1;
}

int tired(object who)
{
	tell_room( environment(), 
	"老醫生打了個哈欠，伸伸懶腰，看起來精神好多了 !!\n" ,
	this_object() );
        set("tired",0);
        return 1;
}

int check_plaster()
{
	if ((int)this_player()->query_quest_level("Goddess_statue") > 0)
	return 1;
        tell_object(this_player(), 
        "老醫生頭也不回的說：「店裡沒藥，我正準備出門採藥呢 ! 抱歉啦 !!」\n");
	return 0;
}
int check_tired()
{
        if ((int)this_object()->query("tired")==1)
	{
        tell_object(this_player(), 
        "老醫生看起來很疲勞，正在打盹，你最好別吵他 !!\n" );
        return 0;
	}
	return 1;
}
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_object(this_player(), 
        "醫生怒道: 不要臉的兇手 !! 打我還叫我醫你 !! 豈有此理 ! \n" );
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (!check_tired()) return 1;
	if (query("hit_points") < query("max_hp"))
	{
        tell_room( environment(), 
        "醫生說道: 哎呀呀 !! 我什麼時候受的傷？趕快包一包 !! ... \n"
	"他開始手忙腳亂的包紮自己，突然間頭一點，咦 ？ 睡著了 ？？\n",
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
	tell_object( this_player(), 
	"醫生說道: 我看你是頭殼有問題 !! 想耍我 ... \n" );
	return 1;
	}
	num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail( 
	"醫生搖搖頭道：「你沒有那麼多金幣 !! 我這可不是義診。」\n");

	tell_object( this_player(), 
	"醫生說道：「好 !! 看我的 !」他輕聲的唸誦一段奇特的咒文，你突然感到\n"
	"全身精力充沛。他笑咪咪的看著你，突然間頭一點，咦 ？ 睡著了 ？？\n" );
	this_player()->set("hit_points",hpmax);
	set("tired",1);
	call_out("tired", 300+random(90),this_object());
	return 1;

}
