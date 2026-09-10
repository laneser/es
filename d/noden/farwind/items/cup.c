#include <mudlib.h>

inherit OBJECT;

int filled;

void create()
{
	set_name("cup", "杯子");
	add( "id", ({ "paper cup" }) );
	set_short( "紙杯" );
	set("long","@@query_c_long");
	set( "quest_smith", 1 );
	set( "weight", 3 );
	filled = 0;
}

string query_c_long()
{
	if( filled )
		return "這個杯子裝滿了清水，但是若不把水喝(drink)掉或倒(pour)掉，\n"
			"這個杯子可能很快會糊掉。\n";
	else
		return  "這個紙杯似乎可以用來裝水，你所要做的只是找一處有水的地方\n"
			"用 fill cup 把杯子裝滿水。\n";
}

int query_filled() { return filled; }

void init()
{
	add_action( "fill_water", "fill" );
	add_action( "drink_water", "drink" );
	add_action( "pour_water", "pour" );
}

int fill_water(string arg)
{
	object env;

	if( !arg || arg!="cup" )
		return notify_fail("用什麼裝水？\n");
	if( filled )
		return notify_fail("杯子中已經裝滿清水了。\n");

	env = environment(this_object());
	if( living(env) ) env = environment(env);

	if( !env->query("water_source") )
		return notify_fail("這裡沒有水....。\n");

	filled = 1;
	write("你把杯子裝滿清水。\n");
	call_out("mess_up", 200);
	return 1;
}

int drink_water(string arg)
{

	if( !arg || arg!="cup" )
		return notify_fail("喝什麼？\n");
	if( !filled )
		return notify_fail("杯子是空的。\n");
	filled = 0;
	write("你把紙杯中的水喝光了。\n");
	return 1;
}

int pour_water(string arg)
{
	if( !arg || arg!="cup" )
		return notify_fail("倒掉什麼？\n");
	if( !filled )
		return notify_fail("杯子是空的。\n");
	filled = 0;
	write("你把紙杯中的水倒光了。\n");
	return 1;
}

void mess_up()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) ) {
	tell_object(owner, "你的紙杯糊掉了，變成一團溼紙團，你隨手將它扔了。\n");
	}
	remove();
	return;
}
