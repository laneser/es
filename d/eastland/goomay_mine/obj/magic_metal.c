#include "../zeus.h"

inherit OBJECT;

void create()
{
	set_name("magic magnetite", "魔法磁鐵礦" );
	add("id",({"magnetite"}));
	set_short( "...","魔法磁鐵礦" );
	set_long("..",
	"這是一塊千載難逢的上好鐵質，若用來製成武器，必是無堅不摧，\n"
	"無敵不克．相同的，若無絕世的打鐵功夫，有此礦亦是枉然．\n"
	);
	set("unit","塊");
	set("weight", 50 );
}