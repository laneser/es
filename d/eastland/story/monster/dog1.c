#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "hell dog", "地獄□犬" );
	add ("id", ({ "dog" }) );
	set_short( "地獄□犬" );
	set_long(@C_LONG
一頭面目猙獰的黑色大犬；它的兩支獠牙大的驚人，足足有一個人的身驅那麼大；
一對眼睛，更如銅鈴那般大，正惡狠狠地瞪著你；四肢更不用提了，行動間好似經
歷場十級大地震，那樣地孔武有力。地獄□犬的嘴角還在流著鮮血，赫！原來是它
銜在嘴裡的肉的血！不妙，它正向你撲過來，行動迅速已極！
C_LONG
	);
        set("killer",1);
        set_temp("bs",10);
        set( "alignment",-1000);
        set( "unit", "頭" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "karma", 30);
	set_skill("dodge",100);
	set("special_defense", (["all":30,"none":20,"fire":-20]) );
        set("aim_difficulty",
           (["critical":50,"vascular":50,"ganglion":50,"weakest":50]) );
	set("stun_difficulty",50);
	set("max_hp", 1000);
	set("hit_points", 1000);
	set("max_fp",300);
	set_natural_weapon(80,32,50);
	set_natural_armor(1,1);
        set("weight", 2000);
        set("tactic","assault");
        set("bodyguard",1);
        set("unbleeding",1);
        set_c_verbs( ({ "%s的兩支大獠牙，往%s一掃",
                        "%s用頭往%s一撞", 
                        "%s張開它的血盆往%s狠狠一咬"
                    }) );
        set_c_limbs(({"軀體","頭部","前肢","後腿"}));
        set("tactic_func","my_tactic");
}
void init()
{
   object player;
   player=this_player();
   if ( player->query_temp("wonderful_spell") ){ 
      tell_object(player,"你巧妙地矇騙過地獄□犬而沒有受到它的攻擊！\n");
      return ;
   }
   else return ::init();
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("bodyguard") ) return 1;
       return 0;
}
int my_tactic()
{
   object victim,*couples;
   int i,max;
   if ( !victim=query_attacker() ) return 0;
   couples=filter_array(all_inventory(environment(this_object())),
        "can_help",this_object());
   max=sizeof(couples);
   for (i=0;i<max;i++)
      couples[i]->kill_ob(victim);
   if ( random(14)>1 ) return 0;  
   tell_object(victim,"\n忽然，「地獄□犬」趁你不防備時往你背後偷咬一口，登時鮮血淋漓！\n\n");
   tell_room(environment(this_object()),sprintf(
    "\n「地獄□犬」往%s身上一咬，登時鮮血淋漓！\n\n",victim->query("c_name")),victim);
   (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,3 );
    return 1;               
}
