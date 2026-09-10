// gate.c: an object for spell 'ASTRAL-GATE'////#pragma save_binary
#include <mudlib.h>

inherit OBJECT;

void	set_destination(object dest);
object	gate_destination;

void	create()
{
	set_name("astral gate", "星界之門");
	add( "id", ({ "gate" }) );
	set_short( "星界之門" );
	set( "long", "@@query_long");
	set( "weight", 0);
	set( "unit", "道");
	set( "prevent_insert", 1);
	set( "prevent_drop", 1);
	set( "prevent_get", 1);
}

void	init()
{
   add_action( "enter_gate", "enter");
}

void	set_destination( object dest )
{
	gate_destination = dest;
}

int		enter_gate( string s)
{
	if (!s)	return notify_fail( "你想進入什麼東西?\n" );
	if ( (!present(s)) || (present(s) != this_object()) )	return 0;
// prevent bugs
	if ( (!gate_destination) || (gate_destination->query("no_teleport")) ) 
	{
		tell_room( environment( this_object()), 
			"在你接觸光門時, 門忽然劇烈地搖動起來, 發出強烈的閃光而消失。\n"
		);
		::remove();
		return 0;
	}
	
	this_player()->move_player( gate_destination,
		this_player()->query("c_name") + "走進了星界之門" );
	return 1;
}

int		remove()
{
	tell_room( environment( this_object() ), 
		"光門漸漸地轉為黯淡, 消失了。\n"
	);
	return ::remove();
}

string	query_long()
{
	string s;
	
	s= "光門有點搖搖晃晃的, 看不到門的彼方。\n";
	if (gate_destination) {
		s = "你透過光門, 看到門的另一側:\n";
		s = s + gate_destination->query("long");
		return s;
	}
	else return s;
}
