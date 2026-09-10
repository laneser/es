#include "../takeda.h" 

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(16);
	set_name( "Song Jiang", "宋江" );
	set_short( "宋江" );
	set_long(
@C_LONG
    表字公明，外號呼保義，人稱及時雨宋公明，鄆城縣宋家村人。幼攻經史，
長有權謀，馳名大孝，仗義疏財，為梁山泊總兵部頭領，名聞遐邇，震動京師。
C_LONG
	);
	set( "unit", "名" );
	add ("id", ({"song","jiang" }) );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 27 );
	set_perm_stat( "kar", 28 );
	set_skill( "dodge", 100 );
	set_skill( "unarmed_parry",100 );
	set_skill( "unarmed", 100 );
	set( "time_to_heal",2 );
	set( "special_defense", ([ "all": 50 ]) );
	set("aim_difficulty", ([ "critical":30, "vascular":55, "ganglion":50 ]) );
	set("stun_difficulty/ma",40 );
	set( "gender", "male" );
	set( "race", "human" );
	set_temp("detect_invi", 1);
	set_temp("effect/detect-invis", 1);
	
	set_temp("detect_hide", 1);
        set_temp("effect/detect-hide", 1);
	set( "alignment", 2400 );
	set_natural_armor( 70, 30 );
	set_natural_weapon( 45, 25, 38 );
	set( "defense_type","berserk");
	set( "wealth/gold", 160 );
	set_c_verbs( ({ "%s神態悠閒自然, 靜靜的看著%s",
		"%s負手而立, 對著%s發出會心微笑", "%s輕輕搖頭, 伸手拍拍%s",
		"%s一聲清嘯, %s感覺一陣痠麻"
		 }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( TARMOR"phoenix_helmet");
        equip_armor( TARMOR"waterlily_boots");
        equip_armor( TARMOR"gold_chainmail");
        equip_armor( TARMOR"hoshi_jade");

}

int my_tactic()
{
	object victim,bandit;
        string stat;
        int n;

	if( random(5)>1 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	if( victim->query_temp("caught") < 3 ) {
	victim->add_temp("caught",1) ;
	tell_object( victim, 
"\n宋江嘆道: 看汝此等武藝, 亦屬不凡, 吾上體天心, 今乃網開一面! \n"
"放汝一條生路便是.......\n\n"
"宋江揮揮手, 一群嘍羅把你帶到大寨門, 然後一把將你推倒在地\n");
	tell_room( environment(), 
"\n宋江派出一堆嘍羅把" + victim->query("c_name") + "，抬到別處放生\n",
		 this_object()  );

 victim->receive_damage(5);
 victim->move_player( TROOM"gate1","*** 你看到"+victim->query("c_name")+"像一隻狗般被人丟出來 ***","");

 tell_object( victim, 
 "\n你被摔了個狗吃屎，一些鮮血從你的嘴角中流了出來，四周的人似乎都在笑你 \n\n");
	return 1;
}
        tell_object( victim,
        "\n宋江罵道: 泥人亦有三分火氣, 你道我無法整治你嗎? \n\n"
        "宋江揮揮手, 一群嘍羅把你抓去地牢, 然後一把將你推倒在地\n");
        tell_room( environment(),
        "\n宋江揮揮手，一堆嘍羅把" + victim->query("c_name") + "，拎到地牢動用私刑...\n",
                 this_object()  );
        victim->receive_damage(30);
        bandit = new(TMONSTER"small_bandit");
        
 victim->move_player( TROOM"jail1","*** 你看到"+victim->query("c_name")+"像一隻狗般被人丟出來 ***","");
 bandit->move(environment(victim));
 bandit->kill_ob(victim);
 tell_object( victim,
  "\n你被摔了個狗吃屎，一些鮮血從你的嘴角中流了出來，四周的人似乎都在笑你 \n\n");
 return 1;  

}