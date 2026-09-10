#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "飄雪洞天" );
	set_long(
		"這是一間新蓋好的工作室，它目前空蕩蕩地沒有任何東西。也許你第一件\n"
	"要做的就是在這裡加一些東西。\n"
	);
        set( "light",1 );
	set( "exits", ([
		"adv" : "/d/adventurer/hall/adv_guild",
		"scholar" : "/d/scholar/scholar/scholar_guild",
	]) );
        set( "objects", ([
          "icy" : "/u/s/snow/obj/icy.c",
          "shoe" : "/u/s/snow/obj/shoe.c",
          "dress" : "/u/s/snow/obj/dress.c"
        ]) );
        reset();
}
void init()
{
        add_action("to_rest","rest");
}
int to_rest()
{
	object me;
	me = this_player();
	me->set("max_hp",3000);
	me->set("hit_points",3000);
	me->set("spell_points",320);
	me->set("force_points",3000);
	me->set("talk_points",600);
        write ("一股寒氣圍繞著你,你覺得渾身舒暢.\n");
	return 1;
}                                        
