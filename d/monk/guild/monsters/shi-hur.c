#include "saulin_monk.c"

void create()
{
	::create();
	set_level(9);
	set_name( "shi hur", "虛合大師" );
	add ("id", ({ "shi", "hur","monk" }) );
	set_short("虛合大師" );
	set_long( @LONG
虛合是個精通五種少林絕技的老僧，一生隱居少林，幾乎不曾出去過。
虛合大師唯一的興趣就是練武，所以能當上他的徒弟是你的福氣啦!!!
般若(音讀 玻惹 )掌是少林武僧最常習練的一種拳法，它博大精深，又
足以克敵致勝，昔日少林第八代方丈元元大師創此掌法，而後經歷代改
良迄今，算是少林的招牌拳法。
LONG
	);
    set( "alignment",1500);
    set( "gender", "male" );
    set( "race", "lizardman" );
    set( "unit", "位" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 18);
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
        set("special_defense", ([ "all":40, "none":30, "monk":15 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("class", "monk");
	set("forgetful", 1);
          set("attack_skill",CLASS"bolo_fist");
          set("defense_skill",CLASS"chu_han");
          set("defense_type","berserk");    
          set("monk_gonfu/bolo-fist",10);
          set("monk_gonfu/chu-han",10);
	set("wealth/gold", 10);
	set_natural_weapon( 40, 18,28 );
	set_natural_armor( 55, 35 );
        set("weight", 700);
	set("att_chat_output", ({
	    "虛合說道 『般若掌的威力看見了吧』\n ", 
	}) );
    equip_armor( SAULIN_OBJ"cloth2.c" );
    equip_armor( SAULIN_OBJ"ring1.c" );
}
