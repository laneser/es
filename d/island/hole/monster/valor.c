#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Lizardman Valor","蜥蜴人勇士" );
	add( "id",({ "lizardman","valor" }) );
	set_short( "蜥蜴人勇士" );
	set_long(@LONG
    這是蜥蜴人最近才挑選出來的第一勇士，不過它正為
了領袖給他的任務而悶悶不樂，獨自一人正喝著悶酒。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",500 );
	set_natural_armor( 90,25 );
	set_natural_weapon( 70,28,60 );
	set_natural_weapon2( 65,24,50 );
	set( "max_hp",800 );
	set( "hit_points",800 );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "kar",25 );
	set_skill( "parry",100 );
	set_skill( "tactic",100 );
	set_skill( "axe",100 );
	set_skill( "dodge",80 );
	set( "tactic","assault" );
	set( "wealth/silver",700 );
	set( "special_defense",([ "all":38,"none":20 ]) );
	set( "aim_difficulty",([
				"weakest":70,"critical":70,
				"vascular":45,"ganglion":80
				]) );
	set( "stun_difficulty",60 );
	set( "inquiry",([ "trouble" : "@@ask_trouble" ]) );
	set( "chat_chance",15 );
	set( "chat_output",({
	"蜥蜴人勇士神智不清地說：唉～酒入愁腸，愁～更～愁～\n"
			}) );
}

void init()
{
	::init();
	add_action( "to_help","help" );
}

int to_help(string str)
{
	object player;
	string who;
	int wine;
	
	player=this_player();
	wine=player->query_temp("lizard_quest/valor");
	if( !str || sscanf(str,"%s",who)!=1 || who!="valor" ){
	tell_object( player,"你想幫助誰？\n" );
	return 1;
	}
	if( undefinedp(wine) ){
	tell_object( player,"蜥蜴人勇士說：少羅嗦，陪我喝酒吧。\n" );
	return 1;
	}
	if( wine < 7 ){
	tell_object( player,"蜥蜴人勇士說：我們再來喝!\n" );
	return 1;
	}
	if( wine==7 ){
	tell_object( player,@HELP
蜥蜴人勇士興奮地說：
你真的想幫我？如果你真的想幫我，你可以去找布倫希多
領袖，告訴他是我要你去找他的，他就會告訴你詳細的情
形。
HELP
		);
	player->set_temp("lizard_quest/leader",1);
	player->set_explore("island#6");
	return 1;
	}
	tell_object( player,"任你怎麼叫也叫不醒他，想幫他也沒法子幫羅。\n" );
	return 1;
}

int accept_item(object me,object item)
{
	string *name;
	int lv;

	name=item->query("id");
	if( name[0]=="wheet wine" ){
	if( undefinedp( lv=me->query_temp("lizard_quest/valor") ) ){
	tell_object( me,"蜥蜴人勇士說：謝謝你的酒。\n" );
	command( "drink wheet wine" );
	return 1;
	}
	else{
	tell_object( me,"蜥蜴人勇士說：嗯～～好酒，來乾了它。\n" );
	command( "drink wheet wine" );
	lv=me->query_temp( "lizard_quest/valor" );
	me->set_temp( "lizard_quest/valor",lv+1 );
	return 1;
	}
	}
	tell_room( environment(this_object()),
	"蜥蜴人勇士喝道：『店小二，這東西拿去換酒來。』\n" );
	item->remove();
	return 1;
}

void ask_trouble()
{
	object player;
	int wine;
	
	player=this_player();
	wine=player->query_temp("lizard_quest/valor");
	if( undefinedp(wine) ){
	tell_object( player,@ALONG

蜥蜴人勇士拉著你的手說：
你要陪我喝酒嗎？不過可惜的是我的酒都喝完了....

ALONG
		);
	player->set_temp("lizard_quest/valor",1);
	return ;
	}
	if( wine > 7 ){
	tell_object( player,"蜥蜴人勇士已經被你灌醉了，無法回答你任何問題。\n" );
	return ;
	}
	switch( wine ){
	case 2 :
		tell_object( player,@BLONG

蜥蜴人勇士深深地嘆了一口氣說：
別說那些傷心事，我們再來喝，今天我們不醉不歸.......

BLONG
		);
		player->set_temp("lizard_quest/valor",3);
		return ;
		break;
	case 4 :
	tell_object( player,@CLONG
	
蜥蜴人勇士激動的抓著你說：
唉～～事情是這樣的。我是這屆蜥蜴人武鬥會的冠軍，也
就是所謂的勇士。照慣例，領袖會給新的勇士一個任務。
可是這次的任務卻難倒我了............你還有酒嗎？

CLONG
		);
		player->set_temp("lizard_quest/valor",5);
		return ;
		break ;
	case 6 :
	tell_object( player,@DLONG

蜥蜴人勇士繼續說道：
最近我們村裡面常常有一些哨兵在站衛兵時會莫名奇妙的
被殺死，本來我們以為是西邊武士堡的忍者乾的好事。但
是，後來發現每個死者都是被吸乾全身的血而死，所以又
有人說可能是村子裡有怪物。可是所有目擊者都已經死了
，所以我至今一點頭緒都沒有，叫我如何是好呢？真希望
有人能幫我。唉～別提了......喝酒吧。

DLONG
		);
		player->set_temp("lizard_quest/valor",7);
		return ;
		break;
	default :
	tell_room( environment(this_object()),
	"蜥蜴人勇士看了看你，又繼續喝酒。\n" );
		return ; 
	}
	return ;
}
