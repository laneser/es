#include <mudlib.h>

inherit OBJECT;

void create(){

	set_name("special","特調大補酒");
	add( "id" , ({ "special" }) );
	set_short( "特調大補酒" );
	set_long( "特調大補酒，限當場喝！\n" );
   	set("unit","杯");
   	set("weight", 15);
   	set("value",({100, "silver"}) );
	set("drink",10);
	call_out("drink_it", query("drink"), this_object() );
}

void drink_it(object who)
{
	object owner;
	owner = environment(who);
	if( owner && living(owner) ) 
	{
		tell_object(owner,
			"你喝下一杯特調大補酒。感到精神好了一些。\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"喝下一杯特調大補酒，精神看起來好了一些!!\n",
			owner );

		owner->receive_healing(15);
	}
	remove();
}
	
