#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name("hint", "小錦囊");
        set_short("hint", "小錦囊");
        set_long(@CLONG
這是一個包的很漂亮的信封，也許你可以把它打開來讀裡面的內容
CLONG
        );
        set("id", ({"hint"}));
        set("unit", "個");
        set( "weight", 1 );
        set( "value", ({ 1, "silver" }) );
        set( "no_sale", 1);
        seteuid( getuid() );
}
void init()
{
        set("owner",environment(this_object()));
        add_action( "do_open", "open");
        add_action( "do_read", "read");
}
int do_open(string str)
{

        if (!str || str != "hint" ) 
                return notify_fail(
                        "把什麼東西打開?\n");
        
        tell_object( this_player(), "現在好像還不是把錦囊打開的時候。\n" );
        return 1;

}
int do_read(string str)
{
if (!str || str != "hint" )
                return notify_fail(
                  "讀什麼?\n");
                                        
                 tell_object( this_player(), "你應該先打開錦囊...\n" );
                 return 1;
}

