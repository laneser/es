// The sign that gives the current exchange values. It queries coinvalue.c
// so it should stay current.
// The standard bank and the standard exchange both clone this sign.
// Written by Mobydick in October of 1992.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;
inherit COINVALUE ;

void create()
{
	string *types;
	string long, c_long;
	int i;

	set_name("sign", "匯率表");
	set_short( "Exchange rate sign", "錢幣匯率表" );
	types = cointypes() ;
	long = "The least valuable coin in the realm is the "+types[sizeof(types)-1]+" coin.\n" ;
	c_long = "所有錢幣之中，幣值最低的是: "+ to_chinese(types[sizeof(types)-1]+" coin")+"。\n";
	for (i=sizeof(types)-2;i>-1;i--) {
		long +=		"A "+types[i]+" coin is worth "+coinvalue(types[i])+" "
					+types[sizeof(types)-1]+" coins.\n" ;
		c_long +=	"一個「"+to_chinese(types[i]+" coin")+"」價值 "+
					coinvalue(types[i])+" 個「"+to_chinese(types[sizeof(types)-1]
					+" coin")+"」\n" ;
	}
	set_long( long, c_long );
}

int set_location (mixed dest)
{
	::move(dest);
}

// This makes it impossible to pick it up.

int move (mixed dest)
{
	return MOVE_NOT_ALLOWED ;
}
