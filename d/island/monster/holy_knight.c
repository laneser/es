#include <../island.h>

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Lizardman Holy Knight","聖騎士金身" );
	add( "id",({ "lizardman","knight" }) );
	set_short( "聖騎士金身" );
	set_long(@LONG
    這是村人為了紀念聖騎士而特地請人打造的一座雕像，打造得栩
栩如生，彷佛是用真人去做的。雖然只是個雕像，但那種霸氣依然能
令人感到害怕。
LONG
		);
	set( "exp_reward",50000 );
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",1400 );
	set( "time_to_heal",6 );
	set_natural_armor( 55,10 );
	set_natural_weapon( 90,55,90 );
	set_natural_weapon2( 85,45,80 );
	set( "max_hp",1000 );
	set( "hit_points",1000 );
	set_perm_stat( "str",30 );
	set_perm_stat( "kar",30 );
	set_perm_stat( "dex",30 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "unarmed",100 );
	set_skill( "two-weapon",100 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set( "wealth/gold",1000 );
	set( "tactic","assault" );
	set( "special_defense",
	([ "fire":80,"cold":80,"energy":80,"electric":80,"energy":80,"none":80 ]) );
	set( "aim_difficulty",
	([ "vascular":35,"ganglion":100,"weakest":65,"critical":60 ]) );
	set( "stun_difficulty",75 );
	set( "no_attack",1 );
//	equip_armor( IOBJ"shield01" );
//	equip_armor( IOBJ"boots02" );
//	equip_armor( IOBJ"tail01" );
//	equip_armor( IOBJ"plate02" );
//	equip_armor( IOBJ"ring01" );
//	equip_armor( IOBJ"glove01" );
//	equip_armor( IOBJ"arm01" );
//	equip_armor( IOBJ"necklace01" );
//	equip_armor( IOBJ"helmet01" );
}

int accept_item(object me,object item)
{
	string name,iname;
	object obj;
	
	name=this_player()->query( "c_name" );
	iname=item->query( "c_name" );
	
	if ( iname!="聖騎士元神" )
	{
	obj=new( IOBJ"bill" );
	obj->set_long( "\n感謝大德『"+name+"』慷慨捐贈『"+iname+"』\n\n\n           和平紀念堂管理處特立此據以茲證明。\n");  
	obj->move(me);
	item->remove();
	tell_room(environment(),"\n不知從哪鑽出的工作人員，對"+name+"笑了笑，便掏出一張紙條給"+name+"\n",this_player());
	tell_object(this_player(),"\n從聖騎士背後走出一個人，他以懷疑的眼神看了看你，便掏出一張紙給你，是武功密笈嗎！？\n\n");

	return 1;
	}
	else
	{
	if( (int)this_player()->query_temp("holy_knight")==1){
	this_player()->set_temp("jousting",1);
	}
	tell_room(environment(),"\n突然聖騎士金身身上發出萬丈光芒！金身竟然動了起來.....\n\n");
	item->remove();
	set_name( "lizardman Holy Knight","蜥蜴人聖騎士" );
	set_short( "蜥蜴人聖騎士" );
	set_long(@C_LONG
    你所看到的就是傳說中『創世神戟』的主人『聖騎士』，也就是當年蜥蜴人
口中的『最終戰士』。當時由於三族混戰，戰況可說空前慘烈，死傷無數。直到
『聖騎士』出現才制止了瘋狂的忍者武士繼續殺戮，而戰爭亦告一段落；三方停
火後便在『映世村』簽下和平條約，然而蜥蜴人為表示和平的誠意，於是將『創
世神戟』插在『映世村』的廣場上，並且由魔族用法術將『創世神戟』封印住，
日後成為『映世村』中和平的象徵。

C_LONG
		);
	set( "no_attack",0 );
	command("go down");
	return 1;
	}
	return 1;
}

void leave()
{
	command("go up");
	tell_room(environment(),"\n聖騎士搖搖頭，嘆了口氣！ 突然，一道光芒從聖騎士的天靈蓋射出.....\n聖騎士又變成金身了......\n\n");
	set( "no_attack" , 1 );
	set_name( "Lizardman Holy Knight","聖騎士金身" );
	set_short( "聖騎士金身" );
	set_long(@LONG
    這是村人為了紀念聖騎士而特地請人打造的一座雕像，打造得栩
栩如生，彷佛是用真人去做的。雖然只是個雕像，但那種霸氣依然能
令人感到害怕。
LONG
		);
	return ;
}
