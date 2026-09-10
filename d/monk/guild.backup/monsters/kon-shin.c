#include "saulin_monk.c"

void create()
{
	::create();
	set_level(14);
	set_name( "kon shin", "空性" );
	add ("id", ({ "kon", "shin","monk" }) );
	set_short( "空性" );
	set_long( @LONG
空性是個脾氣非常強烈的老僧。他因為個性太強，所以專練武功，不掌寺務。
空性以三十六路龍爪手稱雄武林，他平日也以此為傲，龍爪手強調快、準、狠，
是少林絕技中為眾人稱道的一項，昔日空性以龍爪手和明教教主張無忌大戰光明
頂，此役使得龍爪手為武林人士所皆知，也是空性最樂道的一役。
LONG
	);
	set( "alignment",1000);
	set( "gender", "male" );
	set( "race", "orc" );
	set( "unit", "位" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 18);
	set("exp_reward", 200 );
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("class", "monk");
	set("forgetful", 1);
	set("attack_skill",CLASS"dragon_claw");    
	set("defense_skill",CLASS"chu_han");
	set("monk_gonfu/dragon-claw",10);
	set("monk_gonfu/chu-han",10);
	set("wealth/gold", 10);
	set_natural_weapon( 43, 15, 29 );
	set_natural_armor( 45, 40 );
        set("weight", 500);
	set("att_chat_output", ({
	    "空性大喝道 『這便是龍爪手!!!』\n ", 
	}) );
    equip_armor( SAULIN_OBJ"cloth2a.c" );
    equip_armor( SAULIN_OBJ"armband1.c" );
}
