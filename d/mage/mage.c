//#pragma save_binary

// This is a guild object ( not guild token )
// Created by Kyoko@Eastern.Stories 11-22-93
// 02-26-95 Elon up'ed black-magic max to 100

#include <move.h>
#include <conditions.h>
#include <daemons.h>
#include "mage.h"

mapping stat_max = ([
	"str" : 15,
	"int" : 27,
	"dex" : 20,
	"con" : 15,
	"pie" : 20,
	"kar" : 23,
]);

mapping skill_list = ([
	"shortblade"  : ({ 600,  40 }),
	"blunt"       : ({ 400,  50 }),
	"dagger"      : ({ 200,  60 }),
	"whip"        : ({ 400,  40 }),
	"wand"        : ({ 100,  90 }),
        "white-magic" : ({ 400,  100 }),
        "black-magic" : ({ 120,  100 }),
        "elemental"   : ({ 100,  100 }),
	"misc"        : ({ 150,  80 }),
	"concentrate" : ({ 100, 100 }),
	"meditate"    : ({ 100,  80 }),
	"target"      : ({ 100, 100 }),
	"runes"       : ({ 100,  90 }),
	"dodge"       : ({ 300,  60 }),
	"magic-shield": ({ 100,  80 }),
	"recharge"    : ({ 100, 100 }),
	"invoke"      : ({ 100,  90 }), 
]);
/*
string *titles = ({
	"the Magic Admirer",
	"the Magic Seeker",
	"the Newbie Magic Student",
	"the Magic Student",
	"the Student of Magic Academy",
	"the Aspiring Apprentice of Magician",
	"the Apprentice of Magician",
	"the Experienced Apprentice of Magician",
	"the Aspiring Magician",
	"the Magician of 1st Lair",
	"the Magician of 2nd Lair",
	"the Magician of 3rd Lair",
	"the Magician of Grey Robe",
	"the Sorcerer",
	"the Experienced Sorcerer",
	"the Adept Sorcerer",
	"the Archmage",
	"the Greater Archmage",
	"the Archmage of Silver Tower",
	"the Apprentice Wizard"
});
*/
string *c_titles = ({
	"魔法仰慕者 ",
	"魔法愛好者 ",
	"魔法學院新生 ",
	"魔法學院學生 ",
	"魔法學院高材生 ",
	"初級魔法師學徒 ",
	"魔法師學徒 ",
	"經驗豐富的魔法師學徒 ",
	"菜鳥魔法使 ",
	"一階魔法使 ",
	"二階魔法使 ",
	"三階魔法使 ",
	"灰衣魔法使 ",
	"初級魔道士 ",
	"魔道士 ",
	"高級魔道士 ",
	"魔導士 ",
	"大魔導士 ",
	"銀魔導士 ",
	"見習巫師"
});

/************************** INTERFACE *****************************/
int is_guild_member(object obj);
int query_stat_max(string stat);
string *query_skill_list();
int query_skill_exp_cost(string sk_name, int sk_level);
int query_skill_max(string skill);
int query_skill_cost(string skill);
string *query_guild_master();
int equip_level(object armor);
/************************** INTERFACE *****************************/

void create()
{
	seteuid( getuid() );
}

string query_guild_room()
{
	return GUILD_LOCATION;
}

string *query_guild_master()
{
	return MAGE_GUILD_MASTER;
}

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
	if( !living(obj) || !obj->query("user") ) return 0;
	if( (string)obj->query("class") != "mage" && 
	    (string)obj->query("class") != "sage" &&
	    (string)obj->query("class") != "necromencer" ) return 0;
	return 1;
}

int query_stat_max(string stat)
{
	if( !stat || !stringp(stat) ) return 0;
	if( strlen(stat) > 3 ) stat = stat[0..2];
	if( undefinedp(stat_max[stat]) ) return 0;
	return stat_max[stat];
}

// The following founctions maintains the skill experience system of this
// guild. You MUST define them in the guild object. These functions are
// called in /std/guild.c to determinate if a player can raise his/her
// skills by training.
string *query_skill_list()
{
	return keys(skill_list);
}

int query_skill_exp_cost(string sk_name, int sk_level)
{
	if( undefinedp( skill_list[sk_name] ) ) return 0;
	if( sk_level < 0 || sk_level >= skill_list[sk_name][1] ) return 0;
	return (int)STATS_D->query_skill_exp(sk_level) * skill_list[sk_name][0] / 100;
}

int query_skill_cost(string skill)
{
	if( undefinedp( skill_list[skill] ) ) return 0;
	return (int)skill_list[skill][0];
}

int query_skill_max(string skill)
{
	if( undefinedp( skill_list[skill] ) ) return 0;
	return (int)skill_list[skill][1];
}

int check_token(object player)
{
	object obj;
	string unit;

	if( !is_guild_member( player ) ) return 0;
	if( !(obj= player->query("guild")) ) {
		obj = new( GUILD_TOKEN );
		if( obj->move(player) != MOVE_OK )
			return notify_fail( 
				"你身上帶的東西太重了，拿不動本公會的信物。\n");
		if( !(unit = obj->query("unit")) ) unit = "個";
		write( 
			"公會重新發給你一" + unit + obj->query("short") + "。\n");
		return 1;
	}
	write( 
		"你的" + obj->query("short") + "並沒有遺失。\n");
	return 1;
}

// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
	object token;
    string race;

    race = player->query("race");
    if( member_array( race, ({ "lizardman" }) ) != -1 )
      return notify_fail(
        "對不起，太笨的種族無法成為魔法師。\n");

	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"你身上帶的東西太重了，拿不動本公會的信物。\n");

	write( @WELCOME
拉修帝說:
歡迎加入魔法師公會，這本魔法之書(spellbook)將替你記錄你所學到的所
有魔法。魔法師雖不是完全正義的團體，但卻並非極惡之徒，切記保持魔
法師的探求心，不要過份為非作歹，否則我將會懲罰你。希望你能珍惜這
本魔法之書並好好充實它。歡迎加入我們, 讓我來恢復你的法力當做我的
見面禮吧 !
拉修帝喃喃唸了一句咒文並用他的手輕輕向你的肩膀一拍。
一陣淡青色的光芒罩住你然後逐漸散去。
WELCOME
);

	tell_room(environment(player), 
	  MAGE_GUILD_MASTER[1]+"喃喃唸了一句咒文並用他的手輕輕向"+
	  (string)player->query("c_name")+"的肩膀一拍。\n"
	  "一陣淡青色的光芒罩住他然後逐漸散去。\n" , player
	); 
	if( !wizardp(player) && player->query("max_fp") ) {
		player->delete("max_fp");
		player->delete("force_points");
	}
	player->set("max_sp","@@query_max_sp");
	player->set("spell_points", (int)player->query("max_sp"));
	HEAL_SP->apply_effect(player);
	return 1;
}
/*
string query_title(object player)
{
	int level;

	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	return player->query("cap_name") + " " + titles[level-1];
}
*/

string query_c_title(object player)
{
	int level;

	level = player->query_level();
	if( level < 1 ) level = 1;
	if( level > 20 ) level = 20;
	return c_titles[level-1] + player->query("c_name");
}
string query_title(object player)
{
	return query_c_title(player);
}
string *query_titles()
{
	return c_titles;
}

string *query_c_titles()
{
	return c_titles;
}

// The funnction decide equip level when a mage wear armor
int equip_level(object armor)
{
	string material;
	
	material = armor->query("material");
	if( !material ) return 2;
	if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
	else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
	else return 2;
}
