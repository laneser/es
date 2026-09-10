#include "../moyada.h"

inherit OBJECT;

void create()
{
        set_name( "Mirror of True", "拉之鏡" );
        add( "id", ({ "mirror" ,}) );
        set_short("拉之鏡");
        set_long(@CLONG
一面閃閃發亮的鏡子，據說能映出一個人的真面目。
你可以用它照(show)怪物來識破他的偽裝。
CLONG
        );
        set("weight", 15 );
        set("no_sale",1);
        set("value", ({ 200 , "silver" }) );
        set("unit", "面");
}           

void init()
{
    add_action( "to_show", "show");
}

int to_show( string msg )
{
    string who;
    object ob;
    if( !msg ) return 0;
    if( sscanf( msg, "mirror to %s", who )!=1 ) 
      return notify_fail("Show what to whom ??\n");
    ob = present( who, environment(this_player()) );
    if( !ob ) {
      tell_object( this_player(), "這裡沒這個人。\n");
      return 1;
    }
    if( undefinedp(ob->change(ob, this_player())) )
      tell_object( this_player(), 
        ob->query("c_name")+"說: 你幹什麼?\n" );
    return 1;
}
