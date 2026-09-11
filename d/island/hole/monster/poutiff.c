#include "../hole.h"

inherit MONSTER;
void create ()
{
	::create();
	set_level(17);
	set_name( "Lizardman Poutiff Rasoda","拉索達" );
	add( "id",({ "poutiff","rasoda" }) );
	set_short( "蜥蜴人祭司 拉索達" );
	set_long(@LONG
    你看見的是一位保護蜥蜴人村落的祭司，由於蜥蜴人天生智商較
低，無法成為施法者，現任領袖『布倫希多』有見於法術在戰場上的
重要性，因此特地由莫亞達城將她請來。不過她看起來似乎有什麼事
正困擾著她。
LONG
		);
	set( "alignment",600 );
	set( "exp_reward",28000 );
	set( "gender","female" );
	set( "race","drow");
	set( "unit","個" );
	set_perm_stat( "dex",21 );
	set_perm_stat( "str",11 );
	set_perm_stat( "int",25 );
	set_perm_stat( "pie",20 );
	set_perm_stat( "kar",22 );
	set( "max_hp",450 );
	set( "max_sp",1800 );
	set( "hit_points",450 );
	set( "spell_points",1800 );
	set( "wealth",([ "gold":25 ]) );
	set_natural_weapon( 16,12,17 );
	set_natural_armor( 45,24 );
	set( "weight",300 );
	set_skill( "target",100 );
	set_skill( "elemental",100 );
	set_skill( "black-magic",100 );
	set( "guild_levels/black-magic",70 );
	set( "guild_levels/elemental",70 );
	set( "guild_levels/guild",70 );
	set_skill( "concentrate",100 );
	set_skill( "dodge",90 );
	set_skill( "whip",100 );
	set( "magic_delay",2 );
	set( "spells/flare",1 );
	set( "spells/sleet",4 );
	set( "spells/fireball",5 );
	set( "special_defense",([ "all":35,"none":10 ]) ); 
	set( "aim_difficulty",([ "vascular":20 ]) );
	set( "tactic_func","cast_spell" );
	wield_weapon( HWEAPON"chabok" );
	equip_armor( HARMOR"cloth1" );
	equip_armor( HARMOR"cloak4" );
	equip_armor( HARMOR"ring1" );
	equip_armor( HARMOR"amulet4" );
	equip_armor( HARMOR"helmet7" );
	set( "inquiry",([ "vampire" : "@@ask_vampire",
//	                  "charge" : "@@ask_charge" 
	                  ]) );
}

void init()
{
	::init(); 
	add_action( "to_report","report" ); 
}

int cast_spell()
{
	object victim;
	string name;
	
	if( !(victim = query_attacker()) ) return 0;
	
	name = victim->query( "name" );
	if( random(20) < 5 ) {
	command( "cast flare on "+name );
	return 1;
	}
	
	if ( random(20)< 4 ) {
	command( "cast fireball on "+name );
	return 1;
	}
	
	else if ( random(20)< 3 ) {
	command( "cast sleet on "+name );
	return 1;
	}
	else return 0;   
}

int to_report(string arg)
{
	string what,man;
	
	if( !arg || sscanf(arg,"%s to %s",what,man)!=2 )
	return notify_fail( "拉索達說道：『嗯？有什麼事嗎？』\n" );
	
	if( man!="rasoda" && man!="poutiff" )
	return notify_fail( "這裡沒有這個人。\n" );

	else
	{
	switch(what){
		case "kirs" :
		write(@ALONG
拉索達看看你手中的小木刀說:
嗯～桃木削成的短刀！你終於找到除去吸血鬼的武器。不
過光是這樣還是不夠的，吸血鬼的道行高深，想找到他的
棲息地不是一件容易的事；就算找到他的棲息地，恐怕也
看不到他。所以你必須先找到紫水晶。唯有先用紫水晶的
魔力逼迫吸血鬼現身，才有打敗他的可能。把桃木短刀給
我，我先將法力灌輸在桃木短刀上吧。
ALONG
	);
		return 1;
		break;
		
		case "amethyst" :
		write(@BLONG
拉索達拍拍你的肩膀說:
要找紫水晶嗎？那兒不是有個水晶池子嗎？你看看把池水除去
之後，能不能找到罕見的紫水晶吧！
BLONG
	);
		return 1;
		break;
	default :
		return notify_fail( "拉索達給你一個白眼後說：『別回報一些無關緊要的事情。』\n" );
	}
	}
}

int accept_item(object me,object item)
{
	string *name;
	
	name=item->query( "id" );
	if ( name[0]=="mahogany kirs" ){
	tell_room( environment(me),
	"拉索達喃喃念著咒語，手中的桃木短刀泛起一陣奇異的光芒。\n" );
	tell_object( me,"拉索達說:我已經將桃木短刀施上魔法了，你快去找其他的東西吧！\n" );
	item->set( "charge",1 );
	command( "give kirs to "+lower_case( (string)me->query("name") ) );
	return 1;
	}
	else
	return notify_fail( "拉索達說道: 別給我一堆垃圾好嗎？\n" );
}

void ask_vampire()
{
        if( this_player()->query_temp("lizard_quest/poutiff") )
        {
          tell_object( this_player(),@ALONG
拉索達說: 哦！是國王陛下要你來的嗎？吸血鬼確實危害我們居民的安全很久了，
　　　　　我們也知道非得用桃木劍射他，才能消滅他；但一來桃木(mahogany)難
          求，二來他實在是太會隱藏了，我們一直無法發現他的蹤跡，唉......
ALONG
          );
          this_player()->delete_temp("lizard_quest/poutiff");
          this_player()->set_temp("lizard_quest/feller",1);
          return;
        }
        write("拉索達搖搖頭說: 我很忙，別煩我！\n");
        return;
}
