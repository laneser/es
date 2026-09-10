#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "miners' cap", "礦工頭盔" );
	add("id",({"cap","helmet"}) );
	set_short("礦工頭盔" );
	set_long(
		"這是一頂舊舊的礦工頭盔，上面有一個小小的燈泡，\n"
		 "你可以把它點亮(light)當作照明用。\n"
	);
	set( "unit", "頂" );
        set("material","element");
	set( "type", "head" );
	set( "weight", 30 );
	set( "armor_class", 2 );
	set( "value", ({ 400, "silver" }) );
        set("fuel", 1800);  // fuel is measured in seconds
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
                return notify_fail("你試著亮起頭盔上的燈泡，但是很顯然的 ... 它沒電了。\n");

        if(query("light"))
                return notify_fail("燈泡已經點著了。\n");

        write("你將頭盔上的燈泡點亮。\n");

        set("light", 1);
        call_out("burn_out", query("fuel"));
        return 1;
}

int extinguish_t(string str)
{
        if(!id(str)) return 0;
        if(!query("fuel"))
                return notify_fail( can_read_chinese()?
                        "太遲了，電已經用完了。\n":
                        "What's the point, it's cashed.\n");

        if(!query("light"))
                return notify_fail("這頂頭盔的燈泡根本沒被點亮 !!\n");

        write("你將燈泡開關關掉。\n");
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
                        "你的頭盔燈泡閃了幾下，沒電了。\n");
        set( "value", ({ 350, "silver" }));
        set( "fuel", 0 );
        set( "light", 0 );
}
