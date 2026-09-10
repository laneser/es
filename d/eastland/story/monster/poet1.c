#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "poet","吟遊詩人" );
    add ("id", ({ "poet" }) );
    set_short( "吟遊詩人");
    set_long(@LONG
一位清瘦逸雋風度翩翩的吟遊詩人，他正偕伴四處觀山閱嶺遊玩探訪故人，路過此
地見風景尚好，遂來此涼亭稍微小憩一番，又愛亭旁蓮池蓮花之清麗，因景因物因
時因地，因此興起吟詩作對之念。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",30);
    set("gender","male" );
    set("alignment",100);
    set("weight",1000);
    set("max_fp",200);
    set("wealth/silver",200);
    set_perm_stat("str",23);
    set_natural_armor(75,5);
    set_natural_weapon(28,14,30);
    set_skill("unarmed-parry",50);
    set_skill("dodge",80);
    set_skill("unarmed",70);
    set("special_defense", ([ "all": 20,"none":20]) );
    set("stun_difficulty",30);
    set("couples",1);
    set( "tactic_func", "my_tactic" );
    set("chat_chance",1);
    set("chat_output",({
       "吟遊詩人閒談道：不知道被芭蕉扇亂刮是什麼滋味。\n"
    }) );
}        
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couples") ) return 1;
        return 0;
}
int my_tactic()
{
    object *couples,victim;
    int i,max;
                        
    if( !victim=query_attacker() ) return 0;
                            
    couples = filter_array( all_inventory(environment(this_object())),
          "can_help", this_object() );
    max=sizeof(couples);
    for( i=0; i<max; i++ ) {
       tell_room( environment(this_object()), sprintf(
          "%s怒道：哼，你以為我們是易與之輩嗎？你莫要打錯了算盤。\n"
          ,couples[i]->query("c_name")));
       couples[i]->kill_ob(victim);
    }
    return 0;
}