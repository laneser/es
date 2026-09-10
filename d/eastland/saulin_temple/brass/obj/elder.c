#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "elder", "銅人陣長老 慧元" );
        add ("id", ({ "elder","monk" }) );
        set_short( "銅人陣長老 慧元" );
        set("unit","位");
        set_long(
@C_LONG
銅人陣長老  慧元是當今少林寺方丈的師兄，因為不願和師弟爭奪方丈之位，
故自願退至銅人陣，擔任守陣長老的職務。如果你想要闖關的話，可以向慧元
大師詢問有關銅人(brassman)的事。
C_LONG
        );
        set("alignment",2000);
        set("wealth/gold",200);
        set("gender", "male");
        set("race", "human");
        set("class", "monk");
        set("max_hp", 2500);
        set("max_fp", 600);
        set("hit_points", 2500);
        set("force_points", 600);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("pie", 20);
        set_perm_stat("kar", 22);
        set_perm_stat("int", 28);
        set_natural_weapon( 80, 20, 40 );
	set_natural_armor( 100, 40 );
        set("special_defense", ([ "all":50,"none":30,"fire":30,"cold":30 ]) );
        set("aim_difficulty", ([ "critical":50, "vascular":80, ]) );
        set_skill("dodge", 100);
        set_skill("force-stun", 100);
//        set("attack_skill", "monk/general/keep_flower");
        set("defense_skill", "monk/general/body_def");
	set("monk_gonfu/body-def",10);
	set("monk_gonfu/keep-flower",30);
        equip_armor( SAULIN_OBJ"/necklace01" );
        equip_armor( SAULIN_OBJ"/cloth1" );
        equip_armor( SAULIN_OBJ"/glove2" );
        equip_armor( SAULIN_OBJ"/ring1" );
        equip_armor( SAULIN_OBJ"/shield2" );
        wield_weapon( SAULIN_OBJ"/go" );
	set("tactic_func","my_tactic");
	set("inquiry", ([
	"brassman" : "@@enter_brass" ]) );
}

int my_tactic()
{
        if( (int)this_object()->query("force_points") < 100 ) { 
        	this_object()->add("force_points",500);
        	return 1; }
//        if( this_object()->query_temp("stun_busy") ) return 0;
//        else {  command( "stun" );
//        	return 1; }
}

int enter_brass()
{
	object obj;
	obj = this_player();
	
	if( (int)obj->query("18brass") == 1 ) {
		tell_object(obj,
			"慧元大師說道：你已通過了銅人陣的考驗，現在你可以選擇要還俗或是\n"
			"	      得到一樣證明。去跟玄慈長老談談吧。\n" );	
		return 1; }		
	tell_object( obj,
		"慧元大師說道：阿彌陀佛。你想要闖一闖十八銅人陣嗎 ? 可先要有心理準備。\n"
		"	      回答我是(answer yes)或否。\n" );
	obj->set_temp("brassman",1);
	return 1;
}
