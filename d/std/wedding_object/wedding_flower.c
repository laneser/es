
#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("wedding flower", "新娘捧花");
	add( "id", ({ "flower" }) );
	set_short("wedding flower", "新娘捧花");
	set_long("..",
	"你仔細的看著這束新娘捧花，聞到一股清香.....\n"
	"婚禮結束後，把它送給下一位想要結婚的女孩吧。\n");
	set("unit","束");
        set("no_sale",1);
        set( "weight", 10 );
        set( "value", ({ 50, "silver" }) );
}
