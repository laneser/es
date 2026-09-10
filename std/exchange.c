//#pragma save_binary

// exchange.c
// A facility for changing money from one kind of coin to another.
// Written by Mobydick@TMI-2, 8-25-92
// For now the service is free, later we should probably attach a fee to it.

#include <money.h>
#include <move.h>
#include <mudlib.h>

#define SIGN "/obj/coinval_sign"

inherit COINVALUE ;

void create()
{
	object sign;

	seteuid(getuid());
	sign = clone_object(SIGN) ;
    sign->set_location(file_name(this_object())) ;
}

void init() {
	add_action ("change", "convert") ;
	add_action ("change", "change") ;
}

int help() ;

int change (string str)
{
	int number, i, j, k, chinese_mode;
	string oldtype, newtype ;
	int oldval, newval ;
	object ob ;

	if (!str) return help();
	if (sscanf(str, "%d %s to %s", number, oldtype, newtype)!=3)
		if (sscanf(str, "%s to %s", oldtype, newtype)==2)
			number = (int)this_player()->query("wealth/"+oldtype);
		else
			return help();
		
	oldval = coinvalue(oldtype);
	if( !oldval )
		return notify_fail( 
			"這種錢幣在這裡並不通行....。\n");

	if( number < 0 )
		return notify_fail( 
			"你只能夠兌換正數的錢幣。\n");

	newval = coinvalue(newtype);
	if( !newval )
		return notify_fail( 
			"你想兌換什麼錢幣？\n");

	if( this_player()->query("wealth/"+oldtype)<number )
		return notify_fail (
			"你沒有那麼多" + to_chinese( oldtype + " coin") + "！\n");

	i = number*oldval ;	/* Value of old coins, in cheapest coin */
	j = i/newval ;		/* Value of old coins, in new coins */
	k = (i-j*newval)/oldval ;   /* Change to be returned.  */
// If we have 0 new coins, then he is just getting back what he started with.
	if (j==0) {
		write( 
			"這些" + to_chinese( oldtype + " coin") + "還值不到一枚" + to_chinese( newtype + " coin" ) + "！\n");
		return 1 ;
	}

// We need to check to see if he can carry the new number of coins.
	if( this_player()->debit( oldtype, number - k ) 
	&& this_player()->credit( newtype, j ) ) {
		write( "Ok.\n") ;
		tell_room( this_object(), 
			this_player()->query("c_name")+"將一些"+ to_chinese(oldtype+" coin")
			+"兌換成"+ to_chinese(newtype+" coin")+"。\n",
			this_player() );
		return 1 ;
	}
	return notify_fail( 
		"這裡可能有一些 Bug ，請通知巫師處裡！\n");
}

int help() {
	write("Usage: " + query_verb() + " [num] [oldtype] to " +
		"[newtype]\n       " + query_verb() + " [oldtype] " +
		"to [newtype]\n");
	return 1 ;
}
