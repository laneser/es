#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name("note","短函");
	set_short("一封短函");
	set_long(
		"一封短函，上面寫著幾行字。\n"
	);
	set("no_sale",1);
	set( "unit", "封");
	set("weight", 2);
	set("value", ({ 5, "silver" }));
}

void init()
{
	add_action("read_note","read");
}

int read_note(string str)
{
    object ob;
    if ( !str || str != "note" ) return 0;
    else {
      ob = environment(this_object());
      if ( ob != this_player() ) 
        return 0;
      else 
        {
          write("謝謝你，有緣人。\n"
          	"我無以回報，只能送你這顆珠子，它是進入陵墓的關鍵。\n" );
          return 1;      
        }
    }
}
