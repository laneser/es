#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Body guard", "貼身待衛" );
	add( "id", ({ "guard" }) );
	set_short( "皇宮禁軍 城主的貼身待衛" );
	set_long(@C_LONG
這是「巫咸城」負責保衛城主安全的禁軍待衛。由於這項工作非常重要，所以
，他不敢東張西望，只有木然地看守著前方，心裡十五個吊桶，七上八下，深怕出
了什麼差錯。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 300 );
        set_perm_stat( "str", 26 );
        set_perm_stat( "dex", 26 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "kar", 30 );
        set_skill( "parry", 80 );
        set_skill( "polearm", 100 );
        set_skill( "block", 80 );
        set_skill( "defend", 100 );
        set("wealth/gold",100); 
        set("max_hp", 680);
        set("hit_points",680);
        set("special_defense", ([ "all":50, "none":40]) );
        set_natural_armor(88,26);
        set_natural_weapon(5,0,0);
        set("bodyguard",1);
        wield_weapon(SWWEA"polearm2");
        equip_armor(SWARM"wiz_shield2");
        set("tactic_func","my_tactic");  
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
    for( i=0; i<max; i++ ) {
       tell_room( environment(this_object()), sprintf(
          "%s大喊道：兄弟們，有人上門挑釁，大家快抄傢伙上！\n"
          ,couples[i]->query("c_name")));
           couples[i]->kill_ob(victim);
    }
    return 0;
}