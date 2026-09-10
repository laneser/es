#include <mudlib.h>
inherit OBJECT;
void create()     
{
        set_name( "crystal glass", "水晶玻璃球" );
	add("id",({"glass"}));
	set_long(@LONG
一顆晶瑩剔透的水晶球，它上面的螢光物質使得它不時在黑暗中發出些微磷光。	
LONG
        );	
	set_short("水晶玻璃球");
	set( "unit", "顆" );
	set("weight", 40);
	set("value", ({ 100, "silver" }));
        set("light",1);
        call_out("disappear",1800,this_object());
}
void disappear(object ob)
{
    object owner;
    owner=environment(this_object());
    if (!owner)
       printf("這顆水晶球上的螢光物質業已消耗殆盡失去光澤了...！\n");
    remove();
}
