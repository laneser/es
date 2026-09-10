
#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set_name( "lamp", "油燈" );
	set("short", "@@query_short");
	set("long", "@@query_long");
	set( "unit", "盞" );
	set("weight", 40);
	set("value", ({ 20, "silver" }));
	set("fuel", 1500);  // fuel is measured in seconds
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
		return notify_fail("這盞油燈的燈油已經燒完了。\n");

	if(query("light")) 
		return notify_fail("這盞油燈已經點著了。\n");

	write( "你將油燈點亮。\n");
	set("light", 1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("太遲了，燈油已經燒完了。\n");

	if(!query("light"))
		return notify_fail("這盞油燈還沒有點著，如何熄滅？\n");

	write("你將油燈熄滅。\n");
	set("light", 0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,
			"你的油燈暗了下來，熄掉了。\n");

	set ("value", ({ 1, "silver" }));
	set ("fuel", 0);
	set ("light", 0);
}
/*
string query_short()
{
	if(query("fuel"))
		return "a lamp" + (query("light") ? " (lit)" : "");
	return "a lmap";
}
*/

string query_short()
{
	if(query("fuel"))
		return "油燈" + (query("light") ? " (亮著)" : "");
	return "油燈";
}

/*
string query_long()
{
	if(query("fuel"))
		return "It is a light source.\n" +
			(query("light") ? "It is lit.\n" : "It is not lit.\n");
	return "It used to be a light source.\n";
}
*/

string query_long()
{
	if(query("fuel"))
		return "油燈是一種常見的照明用具，\n" +
			(query("light") ? "這盞油燈是點著的，你可以熄滅(unlight)它。\n"
			: "你可以把它點燃(light)使用。\n");
	return "這盞油燈的燈油已經用光了。\n";
}
