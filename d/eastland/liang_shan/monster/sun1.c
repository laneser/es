#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "Sun Er Niang", "孫二孃" );
	add( "id", ({ "sun","er","niang" }) );
	set_short( "孫二孃" );
	set_long(
		"你看到一個強壯的少婦，她就是賣人肉包子的孫二孃，外號母夜叉，配\n"
		"與張青為妻，為梁山打聽聲息兼邀接來賓頭領。\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set( "alignment", -400 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 20 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 80 );
	set( "wealth/gold", 65 );
	set( "special_defense", (["all": 30 ]) );
	set_natural_weapon( 5, 4, 4 );
	set_natural_armor( 46, 10 );
        set("tactic_func","kick");
	set("inquiry",([
	    "meat" : "@@ask_meat"
	    ]));
	wield_weapon( "/d/eastland/obj/thin_blade" );
        equip_armor(TARMOR"red_skirt");
        equip_armor(TARMOR"ruby_ring");
}

int stop_attack()
{
	object husband, *tmp;

	husband = present( "hsin", environment() );
	if( !husband ) return 0;
	tell_room( environment(), 
		"張青喝道: 臭小子，敢欺負我老婆？看刀！\n"
	 );
   tmp =query_temp("protectors");
   if(! tmp || member_array(this_player(),tmp)==-1);
    husband->kill_ob(this_player());
 
}
int kick()
{
   object victim;
   string name,c_name;
   if (!(victim= query_attacker())) return 0;
   if ( (string)victim->query("gender") == "female" ) return 0;
   name =victim->query("name");
   c_name =victim->query("c_name");
   if(random(5)<1) {
   tell_room(environment(this_object()),
   "\n孫二孃大叫: 讓你知道女人的厲害．裙底飛出一腿直擊"+c_name+"要害，使它\n痛     不     欲     生\n\n"
);
   victim->receive_special_damage("evil",10);
   victim->block_attack(2);
   return 1;
}
}
void ask_meat()
{
if (!(this_player()->query_temp("fat_quest/meat")) || (int)this_player()->query_temp("fat_quest/meat")==0)
write(
"孫二孃兇巴巴的說道: 什麼肉? 想死啊?\n");
else 
{
write(
"孫二孃笑咪咪的說: 大家都很奇怪，為什麼敝店還能找到山產來做成好吃的料理。\n"
"甚至還有人傳說我們是用人肉來作菜......:) \n"
"很久以前我們的確是用過人肉，但自從在山寨內開業以後，就再也沒有用過了\n"
"現在我們用的肉，都是派人去幽國城西南的大森林打獵來的，但是因為是專人\n"
"處理，成本就比較貴一點呦，您要不要試看看。\n\n"
"你想，既然成本比較貴，似乎不太適合肥東這種公營事業...但是你還是認為跟肥\n"
"東討論(consider meat)一下比較好\n");
this_player()->set_temp("fat_quest/meat",2);
}
return 0;
}