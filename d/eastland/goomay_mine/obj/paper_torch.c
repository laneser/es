

#include "../zeus.h"
inherit OBJECT;

void create()     
{
	set_name( "magic_paper", "千里火" );
	set("short", "@@query_short");
	set("long", "@@query_long");
	set("id", ({ "paper" }));
	set( "unit", "張" );
	set("weight", 5);
	set("fuel", 300);  // fuel is measured in seconds
}


void init()
{
	add_action("light_t", "blow");
	add_action("extinguish_t", "unlight");
}        
int light_t(string str)
{
	if(!id(str)) return 0;	

	if(query("light")) 
		return notify_fail( "這張千裡火已經點著了。\n");

	write("你吹了一口氣將千里火給點著了。\n");
	set("light", 1);
	this_player()->set_temp("paper/light",1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;	
	if(!query("fuel"))
		return notify_fail( "來不及了!這張千裡火已經化為飛灰了。\n");	
	if(!query("light"))
		return notify_fail("這根千里火還沒有點著，如何熄滅？\n");

	write("你將搖一搖手將千里火熄滅。\n");
	set("light", 0);
	this_player()->set_temp("paper/light",0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{       object ob; 
	object owner;
           ob = this_object();
	owner = environment(this_object());
	if( living(owner) ){
		tell_object( owner,"你的千里火火光閃了幾下，化成灰熄掉了。\n");
       ob->remove();
       this_player()->set_temp("paper/light",0);
	}
}

string query_short()
{
	if(query("fuel"))
		return "千里火" + (query("light") ? " (點著)" : "");
}


string query_long()
{
	if(query("fuel"))
		return "千里火是最古代常見的隨身光源，\n" +
			(query("light") ? "這張千裡火已經點著了，你可以熄滅(unlight)它。\n"
			: "你可以對它吹(blow)口氣點燃使用。\n");
}
