#include <mudlib.h>

inherit TEACHER;
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Dalifore", "戴利佛" );
	add ("id", ({ "captain", "knight", "dalifore" }) );
	set_short( "精銳騎士長 戴利佛 伯爵");
	set_long(@CLONG
戴利佛是諾頓騎士團中僅次於雷思團長的第二號人物，他擅長的武器非常
多，因此國王派他負責訓練皇家騎士們的武器技巧。
CLONG
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
   set_skill( "tactic", 100 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "block", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 800 );
	set( "max_hp", 800 );

	set_natural_weapon( 15, 5, 20 );
	set_natural_armor( 70, 30 );
	
   set( "tactic", "flank" );
   set("special_defense",(["all":30]));
    set("aim_difficulty",([ 
    	"critical":80,"vascular":50,"weakest":50,"ganglion":50 ]) );
	
	wield_weapon( "/d/noden/nodania/obj/markara" );
	equip_armor( "/d/noden/nodania/obj/steel_plate" );
	equip_armor( "/d/noden/nodania/obj/steel_leggings" );
	equip_armor( "/d/noden/nodania/obj/steel_gauntlets" );
	equip_armor( "/d/noden/nodania/obj/shield" );
	equip_armor( "/d/noden/nodania/obj/steel_boots" );
	equip_armor( "/d/noden/nodania/obj/steel_helmet" );
	set( "inquiry", ([
		"lucksis" : "@@ask_lucksis",
		"yamor" : ({
			"亞默？.... 沒錯，我是答應過要訓練(train)他的公會成員 ....。\n" }),
		"train" : ({
"我可以教你長刃型武器(longblade)及戰術運用(tactic)的技巧。\n" }),
	        "tactic" : ({
			"還問!?再羅唆我就不教了!\n" }),
		"longblade" : ({
			"沒—錯！你再羅唆我就不教了！\n" })
	]) );
	set_lessons( ([
	   "tactic" : ({ 200, 45 }),
           "longblade" : ({ 150, 55 })
	]) );
}

void ask_lucksis(object who)
{
     if ( !(who->query_temp("lucksis_quest")) || 
     	  !(who->query_temp("lucksis_quest/ask")) ) 
       tell_object(who,"戴利佛說道: 對不起,我正在訓練士兵.\n");
     else {
         tell_object(who,
         	"戴利佛說道: 你是拉克希絲派來的?\n"
            "那是一段往事了, 當時她正被怪物攻擊, 而我救了她。\n"
            "正如我往常的工作, 只不過她與其他人不同的是..\n"
            "她對我糾纏不已, 原諒我這麼說, 但是實在是如此,\n"
            "為此我還特別向國王請求, 派我前往遙遠的死亡大地。\n"
            "與矮人王莫拉德會面做雙邊的外交。這樣我才逃過她\n"
            "的糾纏。\n戴利佛說完後,繼續訓練士兵。\n\n\n"
            "你覺得戴利佛與拉克希絲的關係似乎是落花有意, 而流水無情。\n"
         );
         who->set_temp("lucksis_quest/dalifore",1);             
     }
}

void init()
{
   teacher::init();
   npc::init();
}

int check_trainee(object trainee)
{
	if( (string)trainee->query("class")!="adventurer"
	|| (int)trainee->query_level()<5 ) {
		return notify_fail(
		"戴利佛搖搖頭，說道: 根據當初和亞默的約定，我只教 5 級以上的冒險者。\n"
	); 
      }
	return 1;
}
