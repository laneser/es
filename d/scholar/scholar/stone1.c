//暫時給精靈不見時使用的物件, 並不十分妥善, 取代方法考慮中.
#include <body.h>

inherit OBJECT;

void create()
{       
	set_name("spirit_stone","精靈之石" );
	set_short("精靈之石");
	set_long(@LONG
	
一塊淡綠色半透明的結晶石，據說能幫助你招換失去的精靈。(touch spirit_stone)。

LONG);
	set("unit","塊");
        set("prevent_get",1);
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
  if (!arg || arg != "spirit_stone")
    return 0;
  if (!this_player()->query_temp("summon_rest")) {
    write("精靈之石微微的震動了一下，但是沒有發生任何事情。\n");
    return 1;
  }
  write("精靈之石發出五彩的光芒，使你恢復招換精靈的能力。\n");
  this_player()->delete_temp("summon_rest");
  return 0;   
}