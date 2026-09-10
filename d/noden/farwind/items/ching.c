#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "quaff_potion", "drink" );
        add_action( "quaff_potion", "quaff" );
}

void create(){

        set_name("ching","竹葉青");
        add( "id" , ({ "wine","chinese wine","ching" }) );
	set_short( "竹葉青" );
      set_long("這是遠風鎮產的竹葉青。\n");
        set("unit","杯");
	set("ident", "CHING");
        set("weight", 10);
        set("value",({20, "silver"}) );
}

int quaff_potion(string arg)
{

        if( ! id(arg) ) return 0;
        write(
                "你喝下一杯竹葉青。感到頭有點暈暈的，但是有一種興奮的感覺。\n"
        );
        tell_room( environment(this_player()) ,
                this_player()->query("c_name")+"喝下一杯竹葉青，顯得很開心的樣子
。\n",
                this_player() );

        remove();
        return 1;

}

