#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "uyko", "橘右京" );
//	add( "id", ({ "uyko" }) );
	set_short( "uyko", "橘右京" );
	set_long(@AAA
你眼前是一位年輕的劍客，有著一張十分貌美清秀的臉孔，但是明顯的他氣色
並不好，一直咳嗽著，有時還會咳出鮮血，讓你懷疑他還能和人戰鬥嗎？
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 30 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 70,25 );
	set( "natural_weapon_class1", 15 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 45 ); 
        set( "time_to_heal",25);
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "dodge",80);
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"swallow_sword");    
        equip_armor(MOBJ"sakura"); 
        set("inquiry",([
            "o_i_la_shi":"@@give_ob"
            ]));
}

int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
     "\n\n右京突然躍向空中，快劍一揮，從劍身上居然飛出一隻火鳥\n"+
     "\n那隻火鳥休一聲飛向"+victim->query("c_name")+"\n\n"
      );
      dam = 20 + random(25);
      victim->receive_special_damage("fire", dam );
      report(this_object(),victim);
      return 1;
}
int give_ob(object ob)
{  
   if( this_player()->query_temp("have_get_statue") )
   {
       write(@CCC
橘右京說道：你這個貪心的傢伙，去死吧 !!! 
說著快劍一揮，對你造成了難以想像的傷害。
CCC);
     this_player()->set("hit_points",0);
     return 1;
   }    
   if( !this_player()->query_temp("calford") )
      return notify_fail("橘右京瞪著你說:小子，有何指教？想和我挑嗎？\n");
   ob=new(MIT"statue");
   this_player()->set_temp("have_get_statue",1);
   write(@AAA
橘右京說道：你是加爾福特叫來拿禮物的吧，這個雕像我刻好已經很久了，就
　　　　　　是等你來拿而已，算算娜考璐璐的生日也快到了，你就趕快拿去
　　　　　　給她讓她高興一下吧！


橘右京說完從身後的大樹下拿出一個雕像，放在你腳邊．．


AAA
);
   ob->set("statue_getter",(string)this_player()->query("name") );
   ob->move(environment(this_player()));
   return 1;
 }

