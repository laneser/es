#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master Tenshin", "天心大師" );
	add( "id", ({ "monk", "tenshin", "master", }) );
	set_short( "天心大師" );
	set_long(
@LONG_DESC
你看到一位慈眉善目的老和尚，他就是藥王殿的長老－天心大師，大師年紀已經
很老了，可是由於養生有道，體力仍然不減。他最大的樂趣就是鑽研醫藥以濟世
救人，也由於他精通經脈氣血之道，大師的點穴功夫冠絕少林，有時候連方丈都
會來向他請益。他現在正在清點藥草(herb)的數目。
LONG_DESC
	);
    set( "inquiry", ([
         "herb" : 
@HERB
阿彌陀佛! 施主有所不知，近日天候異常，藥圃中的回陽草竟
              然乾枯殆盡，回陽草是炮製九轉回陽膏的必需藥物，又是極有
              用的救急續命藥，實在是一日不可或缺，老納心急如焚偏又病
              患如潮，實在沒有時間去尋它，記得當時老納曾在後山試植一
              株，不知現下如何了？可否請施主前往一探，倘若僥倖存活，
              麻煩施主將它移回藥圃，敝寺上下同感大德! 阿彌陀佛...
HERB
	     ,
	"heal" : "@@ask_heal",
]));
	set("race", "human");
	set("gender", "male");
	set_perm_stat("int", 30);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 30);
	set_skill("dodge", 100);
	set_skill("dagger", 100);
	set_skill("anatomlogy", 100);
	set("aiming_loc", "weakest");
	set("max_hp", 987);
	set("max_fp", 543);
	set("force_points", 543);
	set("hit_points", 987);
	set_natural_armor( 50, 40 );
	set_natural_weapon( 5, 15, 25 );
	set("special_defense", ([ "all": 50, "none":30 ]) );
	set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
	set("alignment", 1500);
	wield_weapon( SAULIN_OBJ"holy_dagger2" );
	equip_armor( SAULIN_OBJ"cloth2" );
	equip_armor( SAULIN_OBJ"boot2" );
}

void init()
{
	::init();
	add_action("report_master","report");
}

int tired(object who)
{
        tell_room( environment(), 
        "天心大師從運功中醒來，看起來精氣十足 !!\n" ,
        this_object() );
        set("tired",0);
        return 1;
}

int check_tired()
{
        if ((int)this_object()->query("tired")==1)
        {
        tell_room( environment(), 
        "天心大師正在運功\，你最好別吵他 !!\n" ,
        this_object() );
        return 0;
	}
        return 1;
}

int I_hate_killer()
{
        if ( this_player() == query_attacker() || (this_player()->query_temp("saulin_killer")) ) 
        {
        tell_room( environment(), 
        "天心大師合十道: 施主滿手血腥，請及早回頭，恕老僧不能助紂為虐 !!\n",
        this_object() );
        return 1;
	}
        return 0;
}
int check_quest()
{
        if (this_player()->query("quest/Tenshin's_herb"))
        return 1;
        tell_room( environment(), 
		"天心大師合十道：「不是老僧不肯幫你，而是老僧有是在身 !! 請施主見諒 !」\n"
	,this_object() );
        return 0;
}
int ask_heal()
{
	int num,hpmax,hp;

        if (!check_tired()) return 1;
        if (query("hit_points") < query("max_hp"))
        {
        tell_room( environment(), 
        "天心大師笑道: 咦？老僧什麼時候受的傷？趕快療傷 !! ... \n"
        "他坐下來開始運功療傷。\n",
        this_object() );
        set("hit_points",query("max_hp"));
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;
	}
        if (I_hate_killer()) return 1;
        if (!check_quest()) return 1;
        command("look "+(string)this_player()->query("name"));
        hpmax=this_player()->query("max_hp");
        hp=this_player()->query("hit_points");
        if (hpmax==hp)
        {
        tell_room( environment(), 
        "天心大師笑道: 可是施主您很健康啊 ... \n" ,
        this_object() );
        return 1;
	}
        num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail(
        "你突然想起身上沒帶足夠的香油錢... 不好意思開口請大師醫療\n");

        tell_room( environment(), 
        "天心大師說道：「好 !! 請施主安心 !」他的雙手搭在你的背心，你突然感到\n"
        "兩道強勁的真氣開始環繞全身，剎時你覺得全身說不出的舒暢。\n"
	"他笑咪咪的看著你，然後頭一點，咦 ？ 入定了 ？？\n" ,
        this_object() );
        this_player()->set("hit_points",hpmax);
	tell_object(this_player(),
	"為了感謝大師的辛勞，你很誠心的捐了些香油錢。\n" );
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;

}

int report_master(string arg)
{
	string who, type;
	
    if( !arg || (sscanf(arg, "%s to %s", type, who) != 2) )
    	return notify_fail( 
    	  "回報什麼事給(to)誰？\n" );
    if( !id(who) )
    	return notify_fail(
    	  "你要向誰報告啊! 這裡沒這個人\n" );

	if( type=="herb" ) {
        tell_object( this_player(), @REPORT
        
天心大師說: 阿彌陀佛! 善哉善哉! 施主此舉真乃是造福萬民，敝寺倘有濟世
            微名全賴施主之功\。只是老納有一事不明，回陽草生長迅速，何
            以在數日之間枯死殆盡？又藥圃中之水井又何以一夜間乾涸見底
            ？種種疑問令人不解，施主有興可否前往一探(explore)？
			
REPORT
        );
	return 1;
	}
	if( type=="mushroom" ) {
		tell_object( this_player(),@MUSHROOM
		
天心大師說: 阿彌陀佛! 善哉善哉! 原來如此，自來靈山自有靈物，靈芝家
            族能擇少林而居，難道我等竟不捨一井之水嗎？更何況上天有
            好生之德，且讓它們安居於此吧! 灌溉之水老納再另想辦法就
            是了 !! 多謝施主辛苦 !! 日後施主若有需要醫療(heal)老僧
	    願效綿薄之力。
			
MUSHROOM
        );
		return 1;
	}
	return 1;
}

