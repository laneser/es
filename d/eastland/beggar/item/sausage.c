#include <mudlib.h>
#include <stats.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
	set_name("sausage","『一口香腸』");
	add( "id" , ({ "sausage" }) );
   set_short("『一口香腸』");
   set_long(@C_LONG
一串串烤得香香的香腸,引起你食指大動。
C_LONG
	);
   	set("unit","個");
        set("weight", 15);
   	set("value",({ 300, "silver" }) );
}

int eat_food(string arg)
{
        
    if( !arg ||( arg != "sausage") ) 
        return notify_fail("你要吃啥東東?\n");
    tell_room( environment(this_player()),this_player()->query("c_name")+
        "狼吞虎嚥地吃下了一個『一口香腸』,好像三天沒吃東西的樣子...\n", 
         this_player());
    tell_object( this_player(),
        "你狼吞虎嚥地吃下了一個『一口香腸』,看來你是餓了～～\n");
    this_player()->receive_healing( 15+random(5) );
    remove();
    return 1;
}
