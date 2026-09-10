#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "hold_mark", "hold" );
}
 
void create()
{
        set_name( "army mark", "步卒兵符" );
        add( "id", ({ "army","mark" }) );
        set_short( "步卒兵符" );
        set_long( @C_LONG
這是一面金制的令牌，上面刻著『牧馬關步兵令』，據說這兵符和步兵團長有同等
的地位，拿著(hold)它可以通過所有的守衛和士兵。當然，前提是他們對你沒有私
人恩怨...
C_LONG
                );
                set("unit","面");
                set("weight", 10);
                set("value",({10, "silver"}) );
        set("no_sale", 1 );
}
 
int hold_mark(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="庫房大門" ) {
        tell_object(this_player(),
                "你拿著令牌，守衛對你一幅必恭必敬的樣子。\n" );
        this_player()->set_temp("army_mark",1);
        this_player()->set_explore("eastland#26");
        } else
        tell_object(this_player(),
                "你拿著令牌像笨蛋一樣晃呀晃呀地，可是沒人理你。\n" );
        return 1;
}
