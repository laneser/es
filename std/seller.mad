//#pragma save_binary

// seller.c
// This object provides selling ability to other object.
// Created by Annihilator@Eastern.Stories 12-05-93

#include <move.h>
#include <shop.h>

mixed *inventory;
string menu_text, c_menu_text;

void set_inventory(mixed *inv)
{
	inventory = inv;
}

varargs void set_menu(string menu, string c_menu)
{
	menu_text = menu;
	if( c_menu ) c_menu_text = c_menu;
	else c_menu_text = menu;
}

void init()
{
	add_action( "do_buy", "buy" );
}

void reset()
{
	int i;

	if( !inventory || !pointerp(inventory) || sizeof(inventory)<1 ) return;
	for( i=0; i<sizeof(inventory); i++ )
		inventory[i][2] = inventory[i][1];
}

int do_buy(string arg)
{
	int i, ord;
	string name, shop_name, unit;
	mixed *value;
	object ob, me;

	me = this_player();
	if( !arg ) return notify_fail("買什麼？\n");
	if( !inventory || !pointerp(inventory) || sizeof(inventory)<1 )
		return notify_fail("對不起，這裡不賣任何東西。\n");

	if( sscanf(arg, "%s %d", name, ord)!= 2 ) {
		name = arg;
		ord = 1;
	}
	for( i=0; i<sizeof(inventory); i++ ) {
		if( !inventory[i][0]->id(name) ) continue;
		if( !(--ord) ) {
			ob = new( inventory[i][0] );
			break;
		}
	}
	if( !ob ) {
		return notify_fail("對不起，這裡不賣這種東西。\n");
	}
	if( inventory[i][2] < 1 ) {
		ob->remove();
		return notify_fail("對不起，這樣東西已經賣完了，請待會兒再來。\n");
	} else inventory[i][2]--;

	value = ob->query("value");
	if( !value || value[0]==0 ) {
		ob->remove();
		return notify_fail("對不起，這樣東西是非賣品。\n");
	}
	if( !me->debit( value[1], value[0] ) ) {
		ob->remove();
		inventory[i][2]++;
		return notify_fail("對不起，這樣東西你買不起。\n");
	}
	if( ob->move(me)!=MOVE_OK ) {
		ob->remove();
        inventory[i][2]++;
		me->credit( value[1], value[0] );
		return notify_fail("對不起，這樣東西對你來說太重了。\n");
	}
	if( !(unit=ob->query("unit")) ) unit = "個";
	printf("你買下一%s%s。\n",unit,ob->query("short"));
	tell_room( environment(me), 
		sprintf("%s買下一%s%s。\n",
				me->query("c_name"),unit,ob->query("short")),
		me );
	return 1;
}

int show_menu()
{
	int i;
	mixed *value;
	string unit;

	if( !inventory || !pointerp(inventory) || sizeof(inventory)<1 )
		return notify_fail("對不起，這裡不賣任何東西。\n");
	if( c_menu_text ) write(c_menu_text + "\n");
	else write("你可以購買(buy)以下的物品:\n");
	for( i=0; i<sizeof(inventory); i++ ) {
		value = inventory[i][0]->query("value");
		if ( !unit = inventory[i][0]->query("unit") ) unit = "個" ;
		if( !value || value[0]==0 ) continue;
		write( 
			sprintf( "  %30-s  %5d %-10s  還有 %3d %-4s\n", inventory[i][0]->query("short") + " (" + 
				inventory[i][0]->query("name") + ")", value[0], to_chinese(value[1]+" coin"),inventory[i][2],unit ));
	}
	return 1;
}
