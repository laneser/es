#include <mudlib.h>
inherit "/std/reagent";

void create()
{
	set_name( "zhi chiung", "知穹草" );
	add("id",({"grass","chiung"}) );
	set_short("知穹草" );
	set_long(
	"知穹草生長在寬廣的草原, 矮矮的, 大約只有兩寸。\n"
	"你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "ZHI_CHIUNG" );
	set( "unit", "株" );
        set( "weight", 1 );
	set( "savour","bitter");
	set( "effect","weak");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 30, "silver" }) );
}

