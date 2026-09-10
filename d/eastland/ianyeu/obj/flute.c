#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "flute", "玉簫" );
   set_short( "玉簫" );
   set_long(
     "這是一隻由翠玉所雕成的玉簫，玉簫上面佈滿龍形花紋，\n"
     "還有用篆文刻著幾個小字：『笑傲江湖』。\n" );
   set( "unit", "只" );
   set( "type", "shortblade" );
   set( "hit_func", "weapon_hit" );
   set( "weight", 80 );
   set( "weapon_class", 41 );
   set( "nosecond", 1 );
   set( "min_damage", 20 );
   set( "max_damage", 35 );
   set( "value", ({ 1000, "silver" }) );
   set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int dex, fp;

   owner = environment();
   dex = owner->query_stat("dex");
   fp = owner->query("force_points");

   if( dex < 25 ) {
     tell_object( owner,
     "\n由於你不夠敏捷, 玉簫被你甩了出去!\n\n" );
     this_object()->remove();
     return 0;
   }
   if( random(dex)<21 ) return 0;
   if( random(dex)>20 && fp<20 ) {
     tell_object( owner,
     "\n由於你的內力不足, 玉簫所發出的音波反而震傷了你自己!\n\n" );
     owner->receive_special_damage( "energy", dex+random(15) );
     return 0;
     }
   else {
       tell_object( owner,
       "\n你將一陣內力貫輸於玉簫, 管中突然發出一陣音波向"+victim->query("c_name")+"射去\n\n" );
       tell_object( victim,
     "\n" +
          owner->query("c_name") + "的玉簫突然發出一陣音波向你襲來!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "的玉簫突然向" + victim->query("c_name") + "射出一陣音波!\n\n"
         , ({ victim, owner }) );
        victim->receive_special_damage( "energy", dex+10 );
        owner->add( "force_points", -20 );
       return dex+10;
	}
}
