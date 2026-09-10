//#pragma save_binary
// This is a guild object ( not guild token )
// Created by Angel@Eastern.Stories 11-15-93

#include <move.h>
#include <daemons.h>
#include "/u/s/sage/guild/killer.h"

mapping stat_max = ([
        "str" : 30,
        "int" : 30,
        "dex" : 10,
        "con" : 20,
        "pie" : 16,
        "kar" : 15,
]);

mapping skill_list = ([
        "recitation"         : ({  60, 100 }),
        "longblade"          : ({ 350, 100 }),
        "blunt"              : ({ 200, 100 }),
        "bo"                 : ({ 200, 100 }),
        "unarmed"            : ({ 100, 100 }),
        "fist-technic"       : ({ 150,  75 }),
        "dodge"              : ({ 200, 100 }),
        "inner-force"        : ({ 150,  95 }),
        "heal-cycle"         : ({ 100,  90 }),
        "martial-art"        : ({ 200,  90 }),
        "unarmed-parry"      : ({ 250, 100 }),
        "force-stun"         : ({ 300, 100 })  
]);
string *c_titles=({
        "看更的 ",
        "看門口的 ",
        "初級殺手 ",
        "中級殺手 ",
        "高級殺手 ",
        "達摩棍法初學者 ",
        "白衣殿初級掌法僧 ",
        "般若院見習弟子 ",
        "羅漢堂弟子 ",
        "達摩院武僧 ",
        "戒律院護院 ",
        "藏經閣護衛 ",
        "少林刀棍高手 ",
        "少林神拳傳人 ",
        "七十二絕技高僧 ",
        "少林絕學第一高手 ",
        "笑傲江湖一高僧 ",
        "威鎮武林之少林神僧 ",
        "佛光普照如達摩再世 ",
        "出身少林的小小實習巫師 ",
});


string *c_titles_n=({
        "小沙彌 ",
        "知客僧 ",
        "服事僧 ",
        "初級武僧 ",
        "羅漢拳仰慕者 ",
        "達摩棍法初學者 ",
        "白衣殿初級掌法僧 ",
        "般若院見習弟子 ",
        "羅漢堂弟子 ",
        "達摩院武僧 ",
        "戒律院護院 ",
        "藏經閣護衛 ",
        "少林刀棍高手 ",
        "少林神拳傳人 ",
        "七十二絕技高僧 ",
        "少林絕學第一高手 ",
        "笑傲江湖一高僧 ",
        "威鎮武林之少林神僧 ",
        "佛光普照之達摩神僧再世　", 
        "出身少林的小小實習巫師 ",
});

string *c_titles_p=({
        "七十二絕技弟子 ",
        "少林絕學傳人 ",
        "名動江湖之少林俗家弟子 ",
        "威鎮武林之少林弟子 ",
        "雄霸天下之少林俗門傳人 ",
        "出身少林的小小實習巫師 ",
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

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
        if( !living(obj) || !obj->query("user") ) return 0;
        if( (string)obj->query("class") != "monk" ) return 0;
        return 1;
}

string query_guild_room()
{
        return GUILD_LOCATION;
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
        string gender,race;

        race = (string)player->query("race");
        gender = (string)player->query("gender");
        if( !wizardp(player) && member_array(gender, ({"female"})) != -1 )
                return notify_fail( 
                        "對不起，本公會不收女賓。\n");
        if( member_array(race, ({"beholder","vampire"})) != -1 )
                return notify_fail( 
                        "對不起，本公會不收吸血鬼和眼魔。\n");

        token = new( GUILD_TOKEN );
        if( token->move(player) != MOVE_OK )
                return notify_fail( 
                        "你身上帶的東西太重了，拿不動本公會的信物。\n");
        cat(GUILD_DATA"c_welcome");
        player->delete("max_sp");
        player->delete("spell_points");
        player->set("max_fp", "@@query_max_fp");
        return 1;
}
/*    
string query_title(object player)
{
        int level;

        level = player->query_level();
        if( level < 1 ) level = 1;
        if( level > 20 ) level = 20;
        return player->query("cap_name") + " the " + titles[level-1];
}
*/
string query_title(object player)
{
        int level;

        level = player->query_level();
        if( level < 1 ) level = 1;
        if( level > 20 ) level = 20;
        
        if ((int)player->query("18brass") == 2) 
        return c_titles_p[level-15] + player->query("c_name");
        if ((string)player->query("gender") != "neuter")
        return c_titles[level-1] + player->query("c_name");
    else
        return c_titles_n[level-1] + player->query("c_name");    

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

// the function decide the equip level when a monk wear armor.
int equip_level(object armor)
{
        string material;
        
        material = armor->query("material");
        if( !material ) return 2;
        if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
        else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
        else return 2;
}
