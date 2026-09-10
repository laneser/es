// torch.c
// A torch - for seeing in the dark, roasting marshmallows, whatever you
// want, really.
// Written by Guile@TMI-2, 11-8-92.
// Thanks to Zeus@TMI-2 for a quickie fix, 1-22-93.

#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set("short", "@@query_short");
	set("long", "@@query_long");
#include <compress_obj.h>
 	set_name( "torch", "火把" );
	set("id", ({ "torch" }));
	set( "unit", "枝" );
	set("weight", 30);
	set("value", ({ 5, "silver" }));
	set("fuel", 900);  // fuel is measured in seconds
}


void init()
{
	add_action("light_t", "light");
	add_action("light_t", "ignite");
	add_action("extinguish_t", "extinguish");
	add_action("extinguish_t", "unlight");
}

int light_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail( "這根火把已經燒完了。\n");

	if(query("light")) 
		return notify_fail( "這根火把已經點著了。\n");

	write("你將火把點亮。\n");
	set("light", 1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("太遲了，這根火把已經燒完了。\n");

	if(!query("light"))
		return notify_fail("這根火把還沒有點著，如何熄滅？\n");

	write("你將火把熄滅。\n");
	set("light", 0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,"你的火把火光閃了幾下，熄掉了，你隨手把它扔掉。\n");
	this_object()->remove();
/*
	set( "value", ({ 1, "silver" }));
	set( "fuel", 0 );
	set( "light", 0 );
	set( "useless", 1 );
*/
}

string query_short()
{
	if(query("fuel"))
		return "火把" + (query("light") ? " (點著)" : "");
	return "燒光的火把";
}

string query_long()
{
	if(query("fuel"))
		return "火把是最常見的照明用具，\n" +
			(query("light") ? "這根火把是點著的，你可以熄滅(unlight)它。\n"
			: "你可以把它點燃(light)使用。\n");
	return "這根火把已經燒完了。\n";
}
