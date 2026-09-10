#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master Nei", "雷帝 亞協斯.妮" );
	add( "id", ({ "master","nei" }) );
	set_short( "Master Nei", "雷帝 亞協斯.妮" );
	set_long(@AAA
在你眼前是一位相當動人的女子，美麗的臉蛋配上誘人的身材，讓人
想不道她居然也是武士團忍者部隊的首領之一，她和葛拉並稱為忍者
軍團的兩大天王，而由於妮擅長使用雷系魔法，故又稱之為雷帝！！　	
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "female" );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 30 );    
        set( "max_hp",950 );
        set( "hit_points",950 );
 	set_natural_armor( 55,35 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":45,"none":35 ])); 
        set( "aim_difficulty",([ "critical":100,"weakest":30,"ganglion":60,
                                 "vascular":30 ]));
        set( "stun_difficulty/ma",5);  
	set( "alignment", 1500 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "block",100);
        set_skill( "tactic",100);
        set_skill( "dodge",100);
        set("tactic","berserk");
        set( "wealth" , ([ "gold": 70 ]) );
        set( "tactic_func", "att_gonfus");
        wield_weapon(MOBJ"sword2");
        equip_armor(MOBJ"nei_cloak");
        equip_armor(MOBJ"nei_vest");
        equip_armor(MOBJ"nei_shield");
}

int att_gonfus()
{
     object victim;
     int dam,n;
     if( !(victim = query_attacker()) || (random(25)>4) ) return 0;
 else{    switch(n=random(2))
 { case 0:    
 {    
     tell_room(environment(this_object()), 
     "\n妮大喝一聲:看我的霸皇劍奧義 雷擊鷲爪斬\n"+
     "\n妮的手上的劍散發出一股股雷電，以迅雷之速斬向"+victim->query("c_name")+"\n\n"
       );
      dam = 25 + random(35);
      victim->receive_special_damage("eletric", dam );
      report(this_object(),victim);
      return 1;     
}
 case 1:
{      tell_room(environment(this_object()),
       "\n妮高聲吟唱咒文:遵循著神靈之血與祭壇上與神所定之契約\n"+
       "\n妮高聲吟唱咒文:以我之名，雷之精靈聽我號令，　落雷　！！\n\n"
       );
       call_out("to_attack",4);
       return 1;
}
}
}      
}
int to_attack()
{   object victim;
    int dam;
    victim = query_attacker();
    if (!victim) return 1;
      tell_room(environment(this_player()),
      "\n轟一聲一股巨大的雷電從天而降，打在"+victim->query("c_name")+"身上\n\n"
      );
      dam=35+random(45);
      victim->receive_special_damage("eletric",dam);
      report(this_object(),victim);
      return 1;
 }
