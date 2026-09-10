//#pragma save_binary

#include <move.h>
#include <daemons.h>
#include <conditions.h>
#include "scholar.h"

mapping stat_max = ([
	"str" : 17,
	"int" : 25,
	"dex" : 25,
	"con" : 18,
	"pie" : 17,
	"kar" : 18
]);

mapping skill_list = ([
	"longblade"    : ({ 250,  70 }),
	"shortblade"   : ({ 200,  85 }),
//	"dagger"       : ({ 300,  80 }),
	"parry"        : ({ 300,  70 }),
	"dodge"        : ({ 300,  60 }),
	"tactic"       : ({ 250,  60 }),
	"inner-force"  : ({ 150,  70 }),
//	"anatomlogy"   : ({ 200,  60 }),
	"polemic"      : ({ 100, 100 }),
	"yinyanglogy"  : ({ 150,  60 }),
//	"soothsaying"  : ({ 150,  60 }),
	"chutan"       : ({ 200,  70 }),
	"ethics"       : ({ 100, 100 }),
//	"thrusting"    : ({ 250,  50 }),
        "embattle"     : ({ 100,  95 }),
        "brood"        : ({ 150,  70 }),
        "palaeography" : ({  50,  80 }),
]);
/*
string *titles=({
        "Apprentice of Knowledge",
        "Exam Reject",
        "Impecunious Tutor",
        "Junior Student",
        "Student",
        "Senior Student",
        "Baccalaureate",
        "Junior Licentiate",
        "Licentiate",
        "Senior Licentiate",
        "Privat Docent",
        "Ferrum Fellow",
        "Argentum Fellow",
        "Aurum Fellow",
        "Wizadry Fellow",
        "Dean of Flos",
        "Council of Oculus",
        "Chanceller of Knowledge",
        "Lord of Erudition",
        "Apprentice Wizard",
});
*/
string *c_titles=({
        "笨笨的小書僮",
        "加油中的落第秀才",
        "不折腰的窮學究",
        "小有進步的三品舉人",
        "努力中的二品舉人",
        "更上層樓的一品舉人",
        "剛出爐的新科進士",
        "辦事得體的三品太學生",
        "飲酒賦詩的二品太學生",
        "舞墨長吟的一品太學生",
        "雜學豐富的遊學書生",
        "仗義直言的鐵筆書生",
        "一字萬金的銀筆書生",
        "天下知名的金筆書生",
        "學有專精的神筆書生",
        "才高八斗的探花書生",
        "學富五車的榜眼書生",      
        "滿腹經綸的狀元書生",
        "天機神算的百曉書生", 
        "實習巫師"              
});

string *c_titles_girl=({
        "頑皮的女小書僮",
        "加油中的落第女秀才",
        "不折腰的窮女學究",
        "小有進步的三品女舉人",
        "努力中的二品女舉人",
        "好要更好的一品女舉人",
        "剛出爐的新科女進士",
        "辨才無礙的三品女太學生",
        "飲酒賦詩的二品女太學生",
        "俠骨柔情的一品女太學生",
        "智謀超人的遊學女書生",
        "一筆定江山的鐵筆女書生",
        "文思泉湧的銀筆女書生",
        "聰明好運的金筆女書生",
        "遊戲人間的神筆女書生",
        "無所不知的探花女書生",
        "仙才卓塋的榜眼女書生",
        "深謀遠慮的狀元女書生",
        "智冠古今的百曉女書生",
        "實習巫師"
});

/*
 * TO DESIGN A GUILD:
 *    You must define the following functions in the guild object that
 * can be called in /std/guild.c or other place. These function should
 * do certain check to make sure its argument are correct.
 */
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

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
	if( !living(obj) || !obj->query("user") ) return 0;
	if( (string)obj->query("class") != "scholar" ) return 0;
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

string *query_guild_master()
{
	return GUILD_MASTER;
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
	write( "你的" + obj->query("short") + "並沒有遺失。\n");
	return 1;
}

void check_quest(object player)
{
  if ((int)player->query_quest_level("Tenshin's herb")==1)
    player->set("demand/grass",1);
  if ((int)player->query_quest_level("Ohio's_brother")==1)
    player->set("demand/wood",1);
  return;
}

// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
	object token;
	int level;
	string race;

// close guild for reconstructure at 94/11/8 by Ruby@Eastern.Stories
//	tell_object(this_player(),
//	"對不起，由於國庫吃緊，皇上暫時停止對本公會補助，所以停止\n"
//	"招收門徒，請原諒 !!\n");
//	return 1;
//
	race = (string)player->query("race");
	if( member_array(race, ({"orc", "lizardman", "centaur", "beholder", 
		"hawkman" }))!=-1 )
		return notify_fail("對不起，本公會不收奇形怪狀的種族。\n");
	if( (int)player->query_perm_stat("int") < 5 )
		return notify_fail(
			"對不起，你的智慧太低了，不夠資格加入書生公會。\n");

	token = new( GUILD_TOKEN );
	if( token->move(player) != MOVE_OK )
		return notify_fail( 
			"你身上帶的東西太重了，拿不動本公會的信物。\n");
	write( @WELCOME
歡迎加入書生公會，卞大夫為人隨和，並不約束你的行為，因為特立獨行
之士往往有其他過人之處，只要你不犯下欺君叛國之罪，卞大夫仍是以禮
相待，這塊由城內名匠刻成的玉符(jade mark) 是卞大夫送給門下食客的
見面禮，請笑納。
WELCOME
	);
	player->set("max_fp", "@@query_max_fp");   /* maybe need delete...*/
        player->set("max_sp", "@@query_max_sp");
        player->set("spell_points",(int)player->query("max_sp"));
        HEAL_SP->apply_effect(player);
        check_quest(player);
	return 1;
}

string query_title(object player)
{
        int level;

        level = player->query_level();
        if( level < 1 ) level = 1;
        if( level > 20 ) level = 20;
        if ((string)player->query("gender") != "female")
          return c_titles[level-1] + " " + player->query("c_name");
        else
          return c_titles_girl[level-1] + " " + player->query("c_name");
}

string query_c_title(object player)
{
        return query_title(player);
}

string *query_titles()
{
        return c_titles;
}

string *query_c_titles()
{
        return c_titles;
}

// the function decide the equip level when a scholar wear armor.
int equip_level(object armor)
{
	string material;
	
	material = armor->query("material");
	if( !material ) return 2;
	if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
	else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
	else return 2;
}
