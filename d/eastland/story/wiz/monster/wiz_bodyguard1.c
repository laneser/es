#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "Wizard bodyguard", "皇宮禁軍" );
	add( "id", ({ "bodyguard","guard" }) );
	set_short( "皇宮禁軍" );
	set_long(@C_LONG
這是「巫咸城」負責皇宮安全的侍衛。由於這項安全工作非常重要，所以，他不敢
東張西望，只有木然地看守著前方，心裡十五個吊桶，七上八下，深怕出了什麼差
錯。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 200 );
        set_perm_stat( "str", 26 );
        set_perm_stat( "dex", 23 );
        set_perm_stat( "int", 23 );
        set_perm_stat( "kar", 30 );
        set_skill( "parry", 70 );
        set_skill( "jousting", 100 );
        set_skill( "block", 70 );
        set("wealth/gold",40); 
        set("max_hp", 400);
        set("hit_points",400);
        set("special_defense", ([ "all":10, "none":10]) );
        set_natural_armor(58,17);
        set_natural_weapon(15,8,10);
        set("bodyguard",1);
        wield_weapon(SWWEA"jousting1");
        equip_armor(SWARM"wiz_shield1");
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
           "%s大喊道：有人上門找碴了，大家快保護皇宮的安全。\n"
           ,couples[i]->query("c_name")));
        couples[i]->kill_ob(victim);
    }
    return 0;
}
