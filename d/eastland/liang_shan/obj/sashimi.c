#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#define FRESH_TIME 60

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("fish meat","黃金夢幻鯉魚的肉");
	add( "id" , ({ "meat","fish" }) );
   set_short("黃金夢幻鯉魚的肉");
   set_long( "外皮閃耀著美麗的金色光芒，內層是半透明的魚肉，據說是\n"
             "人間的珍味。\n" );
   	set("unit","塊");
   	set("weight", 15);
	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
	if( !arg || arg != "fish" ) return 0;
	if( !query("is_fresh") ) {
        write("你吃掉一塊腐爛了的魚肉。\n");
        tell_room( environment(this_player()),
           this_player()->query("c_name")+"吃掉一塊腐壞了的魚肉。\n"
                   , this_player()
		);
       (CONDITION_PREFIX + "sick")->apply_effect(this_player(),15,2,5);
	} else {
        write(
                "你愉快地吃掉這一塊生魚肉, 清甜的滋味在口中慢慢擴散....:)\n" );
        tell_room( environment(this_player()),
                     this_player()->query("c_name")+"吃掉了一塊生魚肉，看起"
                "來精神大振...\n", this_player()
		);
           this_player()->receive_healing( 40+random(10) );
	}
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	what->set ("value", ({ 1, "silver" }));
   what->set_short( "腐壞的魚肉" );
   what->set_long( "這塊魚肉已經腐壞了，發出一股難聞的氣味。\n" );
	what->set("is_fresh",0);
   if ( !owner ) { remove(); return ; }
   if( !living(owner) ) { remove() ; return; }
   write(
        "你聞到一股臭味傳來, 好像是什麼東西壞了的樣子。\n"
	);
}
