#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "ghost of Bill", "比爾的鬼魂" );
	add( "id", ({ "ghost", "bill" }) );
	set_short( "比爾的鬼魂" );
	set_long(
		"你看到一個高瘦的男人，他看起來很友善，不過他是個鬼魂。\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "unbleeding",1);
	set( "tactic_func", "my_tactic" );
	set( "alt_corpse", "NONE" );
	set_c_verbs( ({"%s伸手抓向%s"}) );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"比爾喃喃自語: 惡魔(devil)是沒有名字(name)的 ....\n",
		"比爾喃喃自語: 生活困苦 ....\n",
		"比爾喃喃自語: 天亮了嗎 .... ？\n",
		"比爾喃喃自語: 是誰 .... 媽 ....？\n",
		"比爾喃喃自語: 不 .... 不是我，鑰匙(key)在哈洛德(Harold)先生身上 ....\n"
	}) );
	set( "inquiry", ([
		"devil" :"那個嬰兒是惡魔，..... 喔不！原諒我，哈洛德先生！" ,
		"name" :"我 .... 我的名字叫比爾·格蘭登！我不是惡魔！" ,
		"key" : "鑰匙 ... 酒窖的鑰匙。布瑞伐爾(Bravar)先生 .... 也在那裡 .... " ,
		"harold" :"哈洛德先生已經瘋了！他要殺死那個嬰兒！喔，糟了...." ,
		"bravar" :"布瑞伐爾先生是位仁慈的醫生，他是好人 ...."
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
