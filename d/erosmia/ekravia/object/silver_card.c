#include "../ekravia.h"
inherit OBJECT;

int		charge;
int		use_card();

void	create()
{
//	::create();
	set_name("silver card");
	set_short("銀卡");
	set( "long", "@@long_desc");
	add( "id", ({"card", "silver card"}) );
	set( "weight", 0);
	set( "unit", "張");
	set( "value", 0);
	set( "no_drop", 1);
	charge = 10;
}

string	long_desc()
{
	string	s;
	s = sprintf("%s\n%s%s%s\n", "這是一張銀色的卡片, 上面印著迪諾旅店的標誌",
			 "這張銀卡還可以使用", chinese_number(charge), "次。" );
	return s;
}

/*
使用卡片進入房間時被呼叫, 如果卡上還有 charge 的話則傳回 1,
否則傳回 0。
*/
int		use_card()
{
	if (--charge > 0)	return 1;
	call_out( "remove_card", 5, this_player(),this_object() );
	if (charge == 0)	return 1;
	return 0;
}

void	remove_card( object player, object this_ob)
{
	tell_object(player, "銀卡的次數已經用完了。\n");
	this_ob->remove();
}
