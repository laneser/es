#include "../dony.h"

inherit MONSTER;
int times;
void create()
{
	::create();
	set_level(19);
	set_name( "unknow prisoner","不知名[發狂中]" );
	add ("id", ({"prisoner"}) );
	set_short(set_color("囚犯 不知名[發狂中]","HIR"));
	set_long(@C_LONG
你眼前所見是一個年約八、九十歲的老人;他長髮披肩全身上下汙穢不堪,他的衣服
處處散發著一股令人掩鼻的氣息; 讓你驚呀的是有兩條粗粗的精鐵鑄鎖鏈從他的琵
琶骨穿了過去,兩端各連在牆壁上;除此之外,全身上下不下千百個疤痕,與其說是刀
傷不如說是受到極悲慘的酷刑。據說,他曾是轟動一時的大魔頭,但受到八大門派的
圍剿並且制服了他才不致於為害武林。
C_LONG
	);
	set( "unit", "名" );
        set("killer",1);
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 25 );
        set("weight",900);
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set_skill( "unarmed-parry",100);    
	set( "special_defense", ([ "all": 70,"none":70]) );
	set("aim_difficulty", 
	   ([ "critical":120, "vascular":40, "ganglion":70, "weakest":70 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -5000 );
	set("max_hp", 1800);
	set("hit_points",1800);
	set("force_points",500);
	set_natural_armor( 90,30 );
	set_natural_weapon( 110,35,63);
	set( "wealth/gold", 400 );
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(DARMOR"fighter_ring1.c");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({ "%s騰空躍起當頭一記劈空掌對著%s劈下",
                        "%s腳往前踏一步十指成爪往%s一抓,凌厲已極",
                        "%s使出六、六三十六式旋風腿往%s狠狠一掃"
                    }) );
        set( "chat_chance", 2 );
        set( "att_chat_output", ({
             "不知名嘲笑你的無知:連我你也敢招惹,真是活得不耐煩了！！ \n",
             "你發現對手實在是太強了,一道道冷汗從你的背脊流下!! \n"
        }) );
        
}

int my_tactic()
{
     int i,ran;
     object *env,victim;
     string vic_name,mob_name;
     
     if (!victim= query_attacker()) 
         return 0;
     vic_name=victim->query("c_name");
     mob_name=this_object()->query("c_name");
     if( times ) {
        if (times==11)
           tell_room(environment(this_object()),
             "\n"+mob_name+"開始施展吸星大法......\n\n");
        if( --times ) {
           tell_object( victim,"你正被吸取精力！！\n");
           tell_room(environment(this_object()),
               vic_name+"被吸取全身的精力！\n",victim);
           victim->receive_damage(10);
           victim->block_attack(2);
           victim->set_temp("msg_stop_attack","(  你正被吸取精力而動彈不得!!  )\n");
           this_object()->receive_healing(5);
           if ( ( victim->query("class") )=="monk" )
               victim->add( "force_points", -10 );
           report(this_object(),victim);
           return 1;
        } else {
           this_object()->set_natural_armor( 90,30 );
           tell_room(environment(this_object()),
             "\n"+mob_name+"臉上露出滿意的表情:好飽好飽,哈哈哈哈哈！！\n");
           return 1;
        }
     }       
     ran=random(80);
     if ( ran>77 ) {
         times = 11;
         this_object()->set_natural_armor( 80,20 );
         return 0;
     } 
     else if ( ran>74 ) {
        tell_object(victim,
           "\n"+mob_name+"盤旋而起使出了「天水之舞」,令你頭昏眼花！！\n\n");
        tell_room(environment(this_object()),
           mob_name+"盤旋而起使出了「天水之舞」令"+vic_name+"不由自主地跟著起舞！！\n",victim);
        (CONDITION_PREFIX + "confused")->apply_effect( victim, 5, 5 );         
        return 0;
     } 
     else if ( ran>72 ) {
        tell_object(victim,
           "\n"+mob_name+"兩手一青一赤使出了「元陰元陽掌」,往你身上一按,登時真氣大□！！\n\n");
        tell_room(environment(this_object()),
           mob_name+"兩手一青一赤使出了「元陰元陽掌」,往"+vic_name+"身上一按！！\n",victim);
        victim->receive_special_damage("fire",20);
        victim->receive_special_dmage("sleet",20);
        victim->add( "force_points", -20 );
        victim->add( "spell_points", -40 );
        report(this_object(),victim);
        return 0;         
     }
     else if ( ran>70 ) {
        tell_object(victim,
           "\n"+mob_name+"雙手急速舞動,一招「北斗真空截風衝」切斷你周遭的空氣！！\n\n");
        tell_room(environment(this_object()),
           mob_name+"雙手急速舞動,一陣風壓讓你喘不過氣來！！\n",victim);
        (CONDITION_PREFIX + "slow")->apply_effect( victim, 5, 5 );
        (CONDITION_PREFIX + "weak")->apply_effect( victim, 5, 5 );
        return 0;
     }           
     else if ( ran>65 ) {
        tell_object(victim,
           "\n"+mob_name+"喝道: \n"
           "\n看我的不傳之秘 :「修羅金剛指」向你的檀中穴一點！！\n\n");
        tell_room(environment(this_object()),
           "\n"+mob_name+"一股強勁的指力向"+vic_name+"彈去！！\n",victim);
        victim->receive_damage(30);
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack","(  你被點住了穴道而無法移動  )\n");
        return 0;                     
     }
}

void die()
{
   tell_room(environment(this_object()),
       "\n不知名謂然長嘆道:唉,沒想到我竟死於這些鼠輩手中......\n\n");
   ::die(1);
}        