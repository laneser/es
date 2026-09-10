#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "light_pastil", "light" );
	add_action( "want_quit","quit" );
}

void create(){

	set_name("pastil","線香");
	set_short("奇異的線香");
	set_long("這是一種奇異的線香\n");
    set("value" , ({10,"silver"}) );
	set("unit","束");
}

int light_pastil(string arg)
{
	int old_str;
	old_str = (int)this_player()->query_perm_stat("str");

	set("prevent_drop",1);
//	add("c_cap_name","（點燃中）");
//	add("cap_name","(light)");

	if( arg != "pastil" ) return 0;
	write( 
		"你點起了這束線香，一陣淡藍色的煙霧冉冉升起，圍繞著你的身旁，你感到了一種力量。\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"點起了一束線香，一陣淡藍色的煙圍繞在他的身旁。。\n",
		this_player() );

	this_player()->set_perm_stat("str",old_str+2);
	call_out("restore",5,this_player());
	return 1;
}

void restore(object player){

	int new_str;
	new_str = (int)player->query_perm_stat("str");
	tell_object(player,
		"圍繞在你身旁的煙霧慢慢地消失了...\n");
	player->set_perm_stat("str",new_str-2);
	remove();
}
int want_quit(){

	int new_str;
	new_str = (int)this_player()->query_perm_stat("str");
	tell_object(this_player(), 
	        "圍繞在你身旁的煙霧慢慢地消失了...\n");
	this_player()->set_perm_stat("str",new_str-2);
	remove();
}