#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "The captain of Wizard bodyguard", "皇宮禁軍隊長" );
	add( "id", ({ "bodyguard","captain","guard" }) );
	set_short( "皇宮禁軍隊長" );
	set_long(@C_LONG
這是「巫咸城」皇宮禁軍隊長，不時領導禁衛軍負責皇宮的安全，責任重大。禁軍
隊長從小就被城主收留教以十八般武藝，不但允文允武，報效城主更是因忠心耿耿
，貞堅不二，也因此倍受城主器重。他現在正在巡視皇宮安全，表情顯的格外慎重
。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 500 );
        set( "wealth/gold",100);
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set_skill( "parry", 90 );
        set_skill( "polearm", 90 );
        set_skill( "block", 90 );
        set("max_hp", 750);
        set("hit_points",750);
        set("max_fp", 350);
        set_temp("be_joke",100);
        set_temp("bs",100);
        set("special_defense", ([ "all":50, "none":35]) );
        set("aim_difficulty",
          (["critical":60,"vascular":60,"ganglion":60,"weakest":60]) );
        set("stun_difficulty",90);
        set_natural_armor(80,24);
        set_natural_weapon(13,11,7);
        set("bodyguard",1);
        set("tactic","assault");
        wield_weapon(SWWEA"polearm2");
        equip_armor(SWARM"wiz_shield2");
        set("tactic_func","my_tactic");  
        set("inquiry",([
           "killer":"@@ask_killer",
        ]) );
        set("chat_chance",1);
        set("chat_output",({
            "隊長喃喃自語道：真不知道那天的刺客(killer)會躲到那裡？\n"
        }) );
}
void ask_killer(object asker)
{
   write(@LONG
隊長說道：那天宮裡來了一個刺客，雖然失竊了一些東西，所幸沒人傷亡。
　　　　　不過後來幾次的拘補都被他逃逸了，真不知道他現在會躲在那裡
　　　　　？ 　　
LONG
   );   
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("bodyguard") ) return 1;
        return 0;
}
int my_tactic()
{
    object *couples,victim;
    int i,max;
                     
    if( !victim=query_attacker() ) return 0;
                        
    couples = filter_array( all_inventory(environment(this_object())),
              "can_help", this_object() );
    max = sizeof(couples);
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), sprintf(
           "%s大喊道：有人上門找碴了，大家快保護皇宮的安全。\n"
           ,couples[i]->query("c_name")));
        couples[i]->kill_ob(victim);
    }
    return 0;
}
