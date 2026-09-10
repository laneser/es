#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid(getuid());
	set_name("skin","毛皮");
	set_short("毛皮");
	set( "long","@@query_long");
	set( "unit", "張" );
	set( "weight",10 );
	set( "value",({10,"silver"}));
	set( "no_sale", 1);
	set( "c_skin_name","毛皮");
	set( "skin_name","skin"); 
	set( "extra_ids",({}));
}

string query_long()
{
	if ( (string) this_object()->query("c_skin_name") != "skin" )
		return "這是一塊" + (string) this_object()->query("c_skin_name") + "的毛皮。\n";
	else
		return "這是一塊毛皮。\n";	
}


