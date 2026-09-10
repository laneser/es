#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create(){

	set_name("chicken","烤雞");
	add( "id" , ({ "chicken" }) );
	set_short( "烤雞" );
	set_long( "新鮮的土雞，加上『遠風酒店』祖傳的烤法，讓人不禁食指大動...\n");
   	set("unit","盤");
   	set("weight", 15);
   	set("value",({200, "silver"}) );
	set("fresh",3600); // fresh is measured in seconds...
	call_out("not_fresh", query("fresh"),this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
	if( arg != "chicken" ) return 0;

	if(!query("is_fresh")){
		write("一股臭氣傳來，你不由得捏住鼻子...天啊...真噁心..!!\n");
		write("你丟掉一盤餿了的雞肉。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"丟掉一盤臭掉了的烤雞肉...\n",
		this_player() );
	

		remove();
		return 1;
	}

	write( 	"你愉快地吃掉了這一盤烤雞，心中有一種滿足感...:)\n" );
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"吃掉了一盤烤雞，看起來精神好了一些...\n",
		this_player() );
		

	this_player()->receive_healing(30);
	remove();
	return 1;

}

void not_fresh(object who)
{
	object owner;
	owner = environment(who);
        if( owner && living(owner) )
	{
		write("你聞到一股臭味傳來，好像是什麼東西餿了的樣子。\n" );
        }
		set ("value", ({ 1, "silver" }));
		set_short( "餿了的烤雞" );
		set_long( "這盤烤雞已經餿了，不能吃了。\n");
		set("is_fresh",0);
}
   	
