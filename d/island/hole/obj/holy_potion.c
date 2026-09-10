#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "Holy Potion","聖水" );
	add( "id",({ "holy potion","potion" }) );
	set_short( "聖水" );
	set_long(@LONG
	一瓶聖水，專門用來對付吸血鬼的。
LONG
		);
	set( "weight",5 );
	set( "unit","個");
}           

void init(){ add_action( "to_throw","throw" ); }

int to_throw(string arg)
{
	string what,which;
	
	if( !arg || sscanf(arg,"%s to %s",what,which)!=2 )
		return notify_fail( "Usage: throw <item> to <target>\n" );
	if( which!="vampire" )
		return notify_fail( "聖水得來不易，你捨得亂用嗎？\n" );
	if( what!="potion" )
		return notify_fail( "這東西不能拿來丟人喔！\n" );
		
	write( set_color(
"你甩了甩手臂，奮力將聖水往吸血蝙蝠砸去，不偏不倚打在吸血蝙蝠身上。\n","HIY") );
	this_object()->remove();
	return 1;
}
	