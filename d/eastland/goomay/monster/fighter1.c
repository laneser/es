#include "../goomay.h" 

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "wrestler wu-bu-la-kuei", "烏不拉龜" );
	set_short( "摔角手烏不拉龜" );
	set_long(@C_LONG
烏不拉龜是從塞外來的摔角好手，聽說東方有許多武功和肉搏的比賽和武鬥
他特別遠從家鄉趕來參加。他有一身結實的肌肉，看來非常的強壯。 
C_LONG
	);
	set( "unit", "名" );
	add ("id", ({"wu","bu","la","kuei","wrestler" }) );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 80 );
	set_skill( "unarmed", 90 );
	set( "special_defense", ([ "all": 30 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":45, "ganglion":50 ]) );
	set("stun_difficulty/ma",30 );
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", -400 );
	set_natural_armor( 65, 27 );
	set_natural_weapon( 32, 17, 28 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s向前一進，一記猛拳打向%s", "%s左腿往%s一踢",
		"%s大吼一聲，右拳劈向%s", "%s往前一縱，往%s飛撲而去",
		"%s橫撲而來，雙腿絞向%s", "%s如旋風轉了起來，飛向%s",
		"%s壓住%s的肩膀，用頭撞他", "%s右拳臥緊，左拳如風，直取%s",
		"%s狂笑一陣，突然用手腕掃向%s" }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( Obj"stone_armband");
        equip_armor( Obj"win_head");

}

int my_tactic()
{
	object victim;
        string stat;
        int n;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_object( victim, "\n烏不拉龜大叫一聲，看我的『笨牛飛天』，把你一把抓起丟了出去! \n");

	tell_room( environment(victim),"\n烏不拉龜突然一把抓住" + victim->query("c_name") + "，將他舉在頭上轉了起來！\n",
		({ victim, this_object() }) );

	switch( n= random(4) ) {
		case 0: stat = Goomay"mgate";	break;
		case 1: stat = Goomay"row14";	break;
		case 2: stat = Goomay"col22";	break;
		case 3: stat = Goomay"row13";	break;
		default : break;
	}

 victim->receive_damage(8);
 victim->move_player( stat,"*** 你看到"+victim->query("c_name")+"像一顆流星般飛了出去 ***","");

 tell_object( victim, 
 "\n你被摔了個狗吃屎，一些鮮血從你的嘴角中流了出來，四周的人似乎都在笑你 \n\n");

	tell_room( environment(victim), 
		  "\n" +  victim->query("c_name") + "唱著『飛呀、飛呀、小飛俠...』，從天上飛了下來，他是超人嗎? 快去找他簽名!!! \n\n",
		({ victim, this_object() }) );
	return 1;
}
