#include "../legend.h"
#include "../magic.c"

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "fisher older","老漁翁" );
	add ("id", ({"older"}) );
	set_short("老漁翁");
	set_long(@C_LONG
一位年紀約六、七十歲的駝背老人。老漁翁曾經是漁村裡最敢勇的人；在他年輕的
時候，一度與七隻大白鯊惡鬥了三天三夜，最後雖然殺死了四隻，脫困而回，卻也
賠上了一隻眼睛和一條胳臂，但是這種事跡，一直被人們流傳歌誦著。老漁翁曾經
在捕漁時獲得一本魔法書，書裡面記載的知識使得他變為漁村裡最聰明的人，因此
到現在還廣受到人們崇高的尊敬。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 27 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 30 );
        set("weight",900);
	set_skill( "dodge", 100 );
	set_skill( "wand", 80);
	set("max_sp",2700);
        set("spell_points",2700);
	set_temp("be_joke",100);
	set_skill("concentrate",100);
	set_skill("target",100);
	set_skill("elemental",100);
	set_skill("black-magic",100) ;
	set("guild_levels/elemental",60);
	set("guild_levels/black-magic",60);
	set("guild_levels/guild",60);
	set("magic_delay",2 ) ;
        set("spells/sleet",4);
	set("spells/flare",2);
	set("hime_to_heal",3);
	set( "special_defense", ([ "all": 50,"none":50,
	"monk":40,"scholar":20]) );
	set( "stun_difficulty",50);                                              
	set("aim_difficulty", 
	   ([ "critical":100, "vascular":40, "ganglion":70, "weakest":50 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set("max_hp", 900);
	set("hit_points",900);
	set("force_points",500);
	set_natural_armor( 55,41 );
	set_natural_weapon( 37,25,41);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(LARMOR"fish_cloth");
	wield_weapon(LWEAPON"hell_wand");
	set( "tactic_func", "my_tactic" );
        set( "inquiry", ([
             "captain":"@@ask_captain"
        ]) );
}
void ask_captain(object asker)
{
write(@C_LONG
老漁翁道：你問村長喔？唉，可憐的一對佳人，本應是天造地設的一雙，卻因為
　　　　　造化弄人，＃□D．
C_LONG
      );
}
int my_tactic()
{
    object victim,env;
    string mob_cname,vic_cname,vic_name;
    if ( !victim=query_attacker() ) return 0;
    mob_cname=query("c_name");
    vic_cname=victim->query("c_name");
    vic_name=lower_case(victim->query("name"));
    switch( random(50) ) {
    case 1..4 :
        command("cast sleet on "+vic_name);
        break;
    case 5..8 :
        command("cast flare on "+vic_name);
        break;
    case 9..12 :
       env=environment(victim);
       tell_object(victim,set_color(sprintf(
        "%s揚手向你一指，一股奇異的光芒射中了你！\n",mob_cname),"HIY"));
       tell_room(env,set_color(sprintf(
        "忽然%s用手向%s一指，一股奇異的光芒射中了%s。\n",mob_cname,vic_cname,vic_cname)
          ,"HIY"),victim);
       victim->receive_special_damage("energy",25);
       report(this_object(),victim);  
       tell_object(victim,set_color(sprintf(
         "%s將手中的閃電箭往你一射，你只見眼前白光一閃，隨即感到一陣劇痛！\n",mob_cname)
         ,"HIB"));
       tell_room(env,set_color(sprintf(
         "%s將手中的閃電箭往%s一射，一條閃光呼嘯而過，擊中他的身體！\n",mob_cname,vic_cname),
         "HIB"),victim);
       victim->receive_special_damage("electric",25);
       report(this_object(),victim);
       break;
    }              
    return 0;              
}
