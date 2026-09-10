#include <mudlib.h>

inherit CONTAINER;

void create()
{
        ::create();
        set_name("bag", "捕獸袋");
        set_short("捕獸袋");
        set_c_open_long(@LONG
這是蜥蜴人獵人愛用的袋子，用來裝小獵物或者是魚。        
LONG
        );
        set( "weight", 15);
        set( "weight_apply", 55 );
        set( "max_load", 210);
        set( "value", ({ 20 , "silver" }));
        set( "prevent_insert",1 );
        set( "prevent_put_money", 1);
}
