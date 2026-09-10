#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "ghostly face", "鬼臉" );
	add( "id", ({ "face" }) );
	set_short("鬼臉" );
	set_long(
		"你看到一張鬼魅般的臉浮現在牆壁上，她對著你邪惡地笑著。\n"
	);
   set( "race", "undead" );
	set( "gender", "female" );
	set( "alignment", -300 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "my_tactic" );
	set( "wealth/silver", 70 );
	set_c_verbs( ({"%s從空氣中伸出一隻手，抓向%s", "%s發出一陣尖銳的叫聲，往%s一撞"}) );
	set_c_limbs( ({ "鼻子", "眼睛", "耳朵" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"鬼臉突然變大，張開她的血盆大口，發出一陣極其刺耳的尖叫聲！\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

