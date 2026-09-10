#include "../island.h"

inherit WEAPON;
void create()
{
	set_name( "personal sword","試用的配劍" );
	add( "id",({ "sword" }) );
	set_short( "試用的配劍" );
	set_long(@LONG
這是為你打造的配劍，不過你要先試試看稱不稱手，趕快把他配戴上去吧！	
LONG
	);
	set( "unit","把" );
	set( "type","longblade" );
	set( "weapon_class",1 );
	set( "min_damage",1);
	set( "max_damage",2 );
	set( "weight",120 );
	set( "value",({ 2500,"silver" }) );
	set( "wield_func","wield_sword" );
	set( "prevent_drop" , 1 );
}

void wield_sword()
{
	string name;
	int lv,j,hood,wc1,ski,wc,maxd,mind;

	name=this_player()->query("c_name");
	lv=this_player()->query_level();
	ski=((int)this_player()->query_skill( "longblade" ))/2;
	hood=this_player()->query( "knighthood" );
	switch(hood){
			case "baron":
					j=220;
					break;
			case "vicomte":
					j=240;
					break;
			case "earl":
					j=260;
					break;
			case "marquess":
					j=280;
					break;
			case "duke":
					j=300;
					break;
			case "lord":
					j=350;
					break;
			case "overlord":
					j=400;
					break;		                 		
			}

	wc = ((lv-4)*j)/100 ;
	if ( wc > ski )
	{
	wc1 = ski;
	}
	else
	{
	wc1 = wc;
	}
	
	maxd =  ( wc1*1.25 ) ;
//	if ( maxd >= 55 ){
//		maxd = 55 ;
//	}
	
	mind =  ( wc1/1.4 ) ;
//	if ( mind >= 30 ){
//		mind = 30 ;
//	}
	
	set_short("@@short");
	set_long("@@long");
	set( "weapon_class",wc1 );
	set( "min_damage",mind );
	set( "max_damage",maxd );
	set( "no_sale",1 );
	set( "prevent_drop",1 );
	tell_room( environment(this_player()),
	name+"把配劍用力揮了一揮，臉上露出滿意的神情。\n",this_player());
	tell_object(this_player(),"你對於這把劍滿意極了，你想這真是一把和你相配的劍啊！\n");
	set_name( "personal sword","@@short" );
	return ;
}

string short()
{
	string name;

	name = this_player() ->query( "c_name" );
	return set_color( "『"+name+"的配劍』", "HIY" );
}

string long()
{
	string str;

	str = " \n這是你的專屬配劍，要好好愛惜它，畢竟他代表了你的身份啊！\n";
	return str;
}
