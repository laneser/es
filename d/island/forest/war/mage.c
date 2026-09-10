#include "../tsunami.h"

inherit "/d/eastland/island/war/i_warvalue";
inherit HOME+"magic";


void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(16);
        set_name("Daemon Magician","聖靈魔導士");
        add( "id", ({"magician","daemon","mage"}) );
        set_short("聖靈魔導士");
        set_long(@LONG
這是位聖靈魔導士，在歷次戰爭中，他總是以純熟的混合系魔法毀滅
敵人，獲取勝利。
LONG
                );
        set("unit","位");
        set("race","daemon");
        set("gender","male");
        set("alignment",-500);
        set("hit_points",350);
        set("max_hp",350);
        set("spell_points",1000);
        set("max_sp",1000);
        set("justice",8);
        set_perm_stat("int",28);
        set_perm_stat("str",15);
        set_perm_stat("dex",25);
        set_perm_stat("kar",25);
        set_perm_stat("pie",20);
        
        set_natural_armor(30,30);
        set_natural_weapon(10,5,20);
        
        set( "special_defense", ([ "all":25,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":0,"weakest":60,"ganglion":0 ]) );
        set("killer",1);      
        set( "wealth/gold",100 );
        set( "tactic_func", "cast_spell" );
        set("weight",350);
        
        set_skill("shortblade",80 );
        set_skill("dodge",80);
        set_skill("parry",80);
        set("aiming_loc","ganglion"); 
        
        wield_weapon(TWEP"shortblade1");
        equip_armor(TOBJ"hat1");
        equip_armor(TOBJ"robe1");
}

int cast_spell()
{
        object *victim;
        
        if( !(victim=query_attacker()) ) return 0;
            if( random(20)<3 ) {        
         tell_room( environment(this_object()),
"\n魔導士閉目含首吟唱著咒文：周遊四方的精靈啊，以聖靈之名，清淨這世上的邪惡\n"      
"吧！！只見他右手的火球穿過左手的寒氣團，形成一顆光球衝入 "
+victim->query("c_name")+" 的胸口......\n");
         victim->receive_special_damage("evil",50);
         report( this_object(),victim );      
               return 1;
       }
        else return 0;
}   

