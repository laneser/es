#include <mudlib.h>
#define MIX "/d/healer/mix"
#define MESS_OB "/d/healer/potion/mess"

inherit CONTAINER;

void create()
{
	::create();
	seteuid(getuid());
	set_name( "herb bowl", "藥缽" );
	add( "id", ({ "bowl" }) );
	set_short( "an herb bowl", "藥缽" );
	set_c_open_long(
		"這是一個行醫者用來研磨草藥的藥缽，將你要研磨的藥材放進藥缽，然後\n"
		"用 mix 指令即可。\n" );
	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
        set( "max_load", 80 ) ;
	set( "weight_apply", 100 );
	set( "prevent_insert", 1 );
	set( "prevent_put_money", 1 );
}

void init()
{
	::init();
	add_action( "do_mix", "mix" );
}

int do_mix(string arg)
{
	object *inv;
	string potion;
	int i,number;
	int weight;
	object the_potion;

	if( arg && !id(arg) ) return 0;
	if( !environment() || environment()!=this_player() ) return 0;
	inv = all_inventory();
	if( !sizeof(inv) ) return notify_fail( "你的藥缽裡什麼也沒有....。\n");
	potion=MIX->mix(this_object());
	weight=query("weight");
	for(i=0; i<sizeof(inv); i++) {
	        weight = weight - (int)(inv[i]->query("weight") );
	        this_player()->add("load",- (int)(inv[i]->query("weight") ) );
		inv[i]->remove();
	}	
	if( potion ) {
	     number=MIX->potion_amount();
	     for (i=0; i < number; i ++) {
	        the_potion = new(potion);
	        weight = weight + the_potion->query("weight");
	        this_player()->add("load",the_potion->query("weight") );
		the_potion->move(this_object());
	     }
		write( "你將藥缽裡的藥材混合磨碎，配成" + the_potion->query("c_name") + "。\n"
	 	     );
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "將藥缽裡的藥材混合磨碎。\n" ,
			this_player() );
		set("weight",weight);	
		return 1;
	} else {
//		the_potion = new(MESS_OB);
//		the_potion->move(this_object());
//	        weight = weight + the_potion->query("weight");
//		this_player()->add("load",the_potion->query("weight"));
		write("你將藥缽裡的藥材混合磨碎......結果變成一團爛泥。\n" );
		write("你嘆了一口氣, 隨手把藥缽裡的爛泥清掉。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "將藥缽裡的藥材混合磨碎。\n" ,
			this_player() );
		set("weight",weight);	
		return 1;
	}
}
