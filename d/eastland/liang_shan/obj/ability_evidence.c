#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "evidence of ability", "武藝證明書" );
	add( "id", ({ "evidence" }) );
	set_short( "evdence of ability", "武藝證明書" );
	set_long(
		".\n",
		"一張燙金的很漂亮的紙，上面寫了一些字，或許你可以\n"
		"讀讀看上面寫些什麼。\n"
	);
	set( "unit", "張" );
	set( "weight", 10 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
void init()
{
//      set("owner",environment(this_object()));
        add_action( "do_read", "read");
}

int do_read(string str)
{
     object owner;
     owner = query("owner");
     if (!str || str != "evidence" )
     return notify_fail(
          "讀什麼?\n");
          tell_object( this_player(),"[1;33m上面用很整齊的小楷寫著:   \n" 
          "茲證明"+owner->query("c_name")+"武藝已達甲種山賊特等甄試標準，\n"
          "請准予參加梁山山賊行列。\n\n"
          "見證人: 神機軍師朱武[0m \n");
          return 1;
}
