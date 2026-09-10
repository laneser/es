#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit ROOM;
inherit COINVALUE;
void create()
{
	::create();
	set_short( "奉獻臺" );
	set_long( "這裡是奉獻臺。\n" );

}

void init()
{
	add_action("do_sacrifice", "sacrifice");
        add_action("do_sacrifice", "sac");
        add_action("do_sacrifice", "rebo");
}

void convert_value( object ob )
{
	mixed *value;
	int val;

	value = ob->query( "value" );
	if( !value || !pointerp(value) ) {
		ob->delete("value");
		return;
	}
	if( !intp(value[0]) || value[0]==0 || !stringp(value[1]) ) {
		ob->delete("value");
		return;
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	if( val==0 ) val = 1;
	ob->set( "value", ({ val, "silver" }) );
	return;
}

int sell_ob(object ob)
{
	int will_remove, res, number;
	string type, unit;
	mixed *value ,*rate;

	convert_value(ob);
	value = ob->query("value");
	if( !value ) {
		tell_object(this_player(),sprintf(
		   "天帝說道:這沒有價值的東西(%s)也敢奉獻給我？沒誠意嘛。\n",
		   ob->query("short")));
		ob->remove();
		return 1;
	}
    number = value[0] ;
	if (!this_object()->query("rating"))
	  number = number * SHOP_SALES_FRAC;
	else {
	  rate = this_object()->query("rating");
	  number = number * rate[0] / rate[1];
	}
	number -= number * ( 75 - (int)this_player()->query_skill("trading") ) / 200;
	if(number>1000) number = 1000;

	type = value[1];
	ob->move(this_object());
	if( !(unit = ob->query("unit")) ) unit = "個";
	write(sprintf("你把身上的%s奉獻給天帝，天帝龍心大悅賞給你 %d 塊%s。\n",
	    ob->query("short"),number,to_chinese(type+" coin")));
	tell_room( this_object(),sprintf("%s奉獻給天帝一%s%s。\n",
		this_player()->query("c_name"),unit,ob->query("short")),
		this_player() );
        ob->remove();
	return 1;
}
int do_sacrifice(string str)
{
	int i;
	object ob, *obs ;

	if (!str) 
		return notify_fail("你要奉獻你身上的什麼東西給天帝呢？\n");

	if( str=="all" ) {
		obs = all_inventory(this_player());
		for( i=0; i<sizeof(obs); i++ ) {
			if( obs[i]->query("prevent_drop") || obs[i]->query("secure") )
				continue;
			if(obs[i]->query("wielded") || obs[i]->query("equipped") ) 
				continue;
			sell_ob(obs[i]);
		}
		return 1;
	} else {
	ob = present(str, this_player());
	if( !ob )
		return notify_fail("你沒有這樣東西。\n");
	if( ob->query("prevent_drop") || ob->query("secure") )
		return notify_fail("傻小子，這樣東西已經有標記不能奉獻給天帝。\n");
	sell_ob(ob);
	}
	return 1;
}
