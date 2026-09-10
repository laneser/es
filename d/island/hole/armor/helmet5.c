#include <../hole.h>

inherit ARMOR;
int no_pray;
void create()
{
	set_name( "Daemon Visor","惡魔面罩" );
	add( "id", ({ "visor" }) );
	set_short( "惡魔面罩" );
	set_long(@LONG
	邪教徒為了要把惡魔的力量附在身上所戴的面罩。
	傳說只要誠心祈求，就可以獲得黑暗的力量。
LONG
		);
	set( "unit","頂" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "evil":25 ]) );
	set( "value",({ 520,"silver" }) );
	no_pray=0;
}

void init(){ add_action( "do_beg","beg" ); }

int do_beg(string str)
{
	object obj,player;
	
	obj=this_object();
	player=this_player();
	
	if( obj->query( "equipped" ) ){
		if( no_pray==1 ) return notify_fail( "這面罩已經失去作用了。\n" );
		if( !str || str!="ishige" ) return notify_fail( "想想看，誰是邪惡的象徵．．\n" );
		if( ((int)player->query( "alignment" )) < -1600 ) return notify_fail( "你已經夠邪惡了。\n" );
		tell_object(player,set_color(
		"你咬破指尖將鮮血灑向空中，心中默唸著召喚黑暗力量的咒語....\n"+
		"漸漸的你發覺身上充滿了邪惡的力量。\n","HIY" ));
		player->set( "alignment",-1600 );
		player->add( "hit_points",-60 );
		no_pray=1;
		return 1;
	}
	else{
		tell_object( player,"想與惡魔打交道必須穿戴象徵邪惡的信物。\n" );
		return 1;
	}
}
