#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "Ghost of Variel", "薇莉兒的鬼魂" );
	add( "id", ({ "ghost", "variel" }) );
	set_short( "薇莉兒的鬼魂" );
	set_long(
		"你看見一個悲傷的女人，她看起來十分美麗，但是你從她淡淡的身影可\n"
		"以斷定她只是個鬼魂。\n"
	);
   set( "race", "undead" );
	set( "gender", "female" );
	set( "alignment", 500 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "my_tactic" );
	set( "unbleeding",1);
	set( "alt_corpse", "NONE" );
	set_c_verbs( ({"%s伸手抓向%s"}) );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"薇莉兒的鬼魂說道: 請埋葬(bury)我可憐的孩子 ....\n",
		"薇莉兒的鬼魂悲傷地嘆氣。\n",
		"薇莉兒的鬼魂說道: 我的孩子(son)是無辜的 ....\n"
	}) );
	set( "inquiry", ([
		"son" :"我的孩子不是惡魔(devil)，我愛我的孩子 ...." ,
		"bury" : "請把我的孩子從惡魔手中救出來，埋在墓園裡，和我及我丈夫一起 ...." ,
		"devil" : "惡魔幾乎是無法消滅的，你必須找到那張符咒(incantation) ...." ,
		"incantation" :"就是從前那個東方人給我丈夫的驅魔咒 ...." 
	]) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"鬼魂的影子變得模糊，然後你覺得有人在你的耳邊吹氣....\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

void die()
{
	tell_room( environment(this_object()), 
		query("c_cap_name") + "的影子化成一股白煙，消失了 ....\n",
		this_object() );
	::die(1);
}

// This function is called when the quest finished
void quest_finished(object player)
{
	tell_room( environment(player), 
		"薇莉兒的鬼魂微笑著說道: 非常謝謝你，"+player->query("c_cap_name")+"。\n",
		this_object() );
	die();
}
