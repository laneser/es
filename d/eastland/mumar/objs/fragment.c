#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "do_plast", "plast" );
}
 
void create()
{
        set_name( "fragment", "鏡子的碎片" );
        add( "id", ({ "fragment" }) );
        set_short( "鏡子的碎片" );
        set_long( @C_LONG
這是一片鏡子的碎片，反映著你一張充滿疑惑的臉。你可以試著把它貼回(plast)原處。
C_LONG
                );
                set("unit","片");
                set("weight", 10);
                set("value",({ 5, "silver"}) );
        set("no_sale", 1 );
}
 
int do_plast(string arg)
{
    if( !arg || arg != "mirror" ) {
        tell_object(this_player(),
                "你想把這碎片貼在那兒？。\n" );
        return 0;}
    if ((string)environment(this_player())->query("short")=="李芃的收藏室" &&
        this_player()->query_temp("look_mirror")) {
        tell_object(this_player(),
                "你把碎片貼回鏡上的角落，鏡子發出一陣溫暖的光茫。\n" );
        this_player()->set_temp("mirror_ok",1);
        remove();
        } else
        tell_object(this_player(),
                "這兒沒有鏡子啊...\n" );
        return 1;
}
