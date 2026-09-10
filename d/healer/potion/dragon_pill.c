#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
  add_action("eat_pill","eat");
}  
void create()
{
	set_name("dragon pill", "青龍丹" );
	add( "id", ({"pill"}) );
	set_short("青龍丹");
	set_long(
		"這種藥丸是蠻有名氣的補藥, 對於亂服成藥造成的身體不適:p\n"
		"頗有療效。如果你覺得頭昏眼花, 建議你立刻吃(eat)一顆青龍\n"
		"丹。不過如果你已經生病, 這種補藥並不能治病, 你還是應該去\n"
		"看醫生。\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 3000, "silver" }) );
}

int eat_pill(string str)
{
    int stat;
    object player;
        
        if (!str || str!="pill") 
          return notify_fail("你要吃什麼?\n");
        player=this_player();
	stat = (int) player->query("medication_resistance");
	// 1 dragon pill can recover from 3 makira potion
	stat = stat - 210 ;
	if (stat<0) stat=0; 
	player->set("medication_resistance",stat);	
        tell_object(player,"你覺得身體狀況好多了, 頭也不再那麼暈。\n");
        remove();
        return 1;
}
