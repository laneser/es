#include "../zeus.h"

inherit OBJECT;

void create()
{
	set_name("singing arrow", "響鈴箭" );
	add("id",({"arrow"}));
	set_short( "...","響鈴箭" );
	set_long("..",
	"這是一只經過特殊設計的箭，尾端有著一條條的隙縫，行進時可\n"
	"發出鬼哭神號的聲音，令人心膽俱碎．現在正牢牢地插在地上\n"
	);
	set("unit","只");
	set("weight", 5000 );
}