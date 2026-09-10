//#pragma save_binary

// sacr.c
// To scarifice the item on the ground to GODS of ES ..
// for cleaning environment of this world , GODS will pay
// some reward for it.

#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_sacrifice(string str)
{
	object *inv,ob;
	mixed *coins;
	int i,cost;
	if ( ! str ) return help();
	inv = ({ });
	if ( str == "all" ) 
	   inv = all_inventory(environment(this_player()));
	else if ( ob = present(str,environment(this_player()))) 
		inv += ({ ob });
	if ( !sizeof(inv)) 
		return notify_fail(sprintf("這裡沒有 %s 這種東西。\n",str));
	   for ( i =0 ; i < sizeof(inv) ; i++ )	{
		if ( !inv[i] ) continue ;
		if ( living(inv[i]) || inv[i]->query("herb_path")) { 
			if ( str != "all" ) tell_object(this_player(),sprintf("神不接受像%s這種活生生的祭品。\n",inv[i]->query("short")));
				continue ;
		}
		if ( inv[i]->query("prevent_get") || inv[i]->query("name")=="board") {
			tell_object(this_player(),sprintf("神搖搖頭，不認為%s是沒有用的廢物。\n",inv[i]->query("short")));
			continue;
		}
		if ( coins = inv[i]->query("value") ) {
			cost = (int)coins[0]*( (coins[1] == "gold") ? 10 : 1)/20;
			tell_object(this_player(),sprintf("你把%s(%s)奉獻給神，",inv[i]->query("short"),inv[i]->query("name")));
			tell_room(environment(this_player()),
				  sprintf("%s把%s(%s)奉獻給神。\n",
					  this_player()->query("c_name"),
					  inv[i]->query("short"),inv[i]->query("name"))
				,this_player());
			inv[i]->remove();
			switch ( random(3) ) {
				case 0 : 
					cost++;
					tell_object(this_player(),sprintf("神很高興的給你 %d 枚銀幣做獎勵。\n",cost ));
					this_player()->add("wealth/silver",cost);
					break;
				case 1 : 
					cost = cost / 2 +1 ;
					tell_object(this_player(),sprintf("神接受你的奉獻，賜你 %d 點經驗。\n",cost));
					this_player()->gain_experience(cost);
					break;
				case 2 : 
					cost = cost / 10 +1;
					tell_object(this_player(),sprintf("神很欣賞你的環保概念，恢復你 %d 點體力。\n",cost));
					this_player()->receive_healing(cost);
					break;
			}
		} else {
		tell_object(this_player(),
			sprintf("你把%s(%s)奉獻給神，但是什麼事也沒發生。\n",
				inv[i]->query("short"),inv[i]->query("name")));
		inv[i]->remove();
		}
	   }

	return 1;
}

int help()
{
	write (@HELP
Usage:	sacrifice <item on the ground> 
	sacrifice all

    使用這個命令可以把丟棄在地上的東西奉獻給神，以維護環境清潔。
由於讚許你的環保概念，大神會給你小小的獎勵。

HELP
);
	return 1;
}
