#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#define FRESH_TIME 180

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
   set_name( "lamb", "燻羊腿" );
   add( "id" , ({ "leg" } ) );
   set_short( "燻羊腿" );
   set_long(
        "一隻色澤亮麗, 香氣四溢的烤羊腿, 讓人不禁食指大動。\n"
	);
   set( "unit", "只" );
   set( "weight", 25 );
   set( "value", ({ 300, "silver" }) );
	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
   if( !arg || (arg != "leg" && arg != "lamb" ) ) return 0;
	if( !query("is_fresh") ) {
        write( "你吃下一隻餿了的燻羊腿。\n" );
        tell_room( environment(this_player()),
                 this_player()->query("c_name")+"吃下一隻餿了的燻羊腿。\n"
                 , this_player() );
       (CONDITION_PREFIX + "sick")->apply_effect( this_player(), 15, 2 );
	} else {
        write(
                "你愉快地吃掉這一隻燻羊腿。然後擦擦嘴角的油漬。\n" );
        tell_room( environment(this_player()),
             this_player()->query("c_name")+"吃掉了一隻燻羊腿, 他似乎還想再吃一隻.\n", this_player() );
        this_player()->receive_healing( 25+random(5) );
	}
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	what->set ("value", ({ 1, "silver" }));
   what->set_short( "餿了的燻羊腿" );
   what->set_long( "這是一盤餿了的燻羊腿, 不能吃了。\n" );
	what->set("is_fresh",0);
   if ( !owner ) { remove(); return ; }
   if( !living(owner) ) { remove() ; return; }
   write(
        "你聞到一股臭味傳來, 好像是什麼東西餿了的樣子。\n"
	);
}
