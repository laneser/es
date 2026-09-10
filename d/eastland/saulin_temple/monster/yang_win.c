#include "../saulin_temple.h" 

inherit MONSTER;
int i=1;
void create()
{
	::create();
	set_level(18);
	set_name( "Yang Win", "大漠飛鷹 楊勝" );
	set_short( "大漠飛鷹 楊勝" );
	set_long(@C_LONG
楊勝久住塞外，號稱『大漠飛鷹』，乃鷹爪門第一高手。他將師傳的鷹爪功\
融入了他自創的鷹揚千里身法及九陰白骨爪，創出了六式的旋風飛鷹訣，他
這次來到中原，似乎是想揚名立萬的，你打算成為他的爪底亡魂嗎?
C_LONG
	);
	set( "unit", "名" );
	add ("id", ({"yang","Yang","win","Win"}) );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set( "special_defense", ([ "all": 50, "monk":25 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":30, "ganglion":50, "weakest":50 ]) );
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", -400 );
	set("max_hp", 600);
	set("hit_points", 600);
	set_natural_armor( 90, 31 );
	set_natural_weapon( 55, 24, 37 );
	set( "wealth/gold", 100 );
	set_c_verbs( ({ "%s向前飛進，一爪『銀鷹亮翼』抓向%s", "%s身如大鷹飛起，臨空急速往%s一抓",
		"%s大吼一聲，化爪為掌使出『雷霆一擊』向%s", "%s往前一縱，使出『鷹揚九天』往%s飛撲而去",
		"%s橫飛而來，『巨鷹臨空』抓向%s", "%s如旋風轉了起來，但見千百隻利爪抓向%s",
		"%s狂笑一聲，突然使出『雄鷹探海』用雙爪刺向%s" }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( SAULIN_OBJ"eagle_hat");
        equip_armor( SAULIN_OBJ"eagle_cloak");
        equip_armor( SAULIN_OBJ"eagle_bracer");

}

int my_tactic()
{
	object victim;
        string stat;
        int n;

	if( random(100)>8 ||(!i) || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_room( environment(this_player() ),  
set_color("\n\n揚勝突然雙眼泛出一道青光，大吼『身旋如風，爪利如鷹，旋鷹六式，畢敵於此』\n但見他身如電閃，連出三招... \n\n","HIG")   
         ); 
         
         i = 0; 
         this_player()->continue_attack();
         this_player()->continue_attack();
         this_player()->continue_attack();
         i = 1; 
	return 1;
}
