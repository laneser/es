#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "hold_mark", "hold" );
}
 
void create()
{
        set_name( "cavalry permit", "騎兵令牌" );
        add( "id", ({ "cavalry","permit" }) );
        set_short( "騎兵令牌" );
        set_long( @C_LONG
這是一面金制的令牌，上面刻著『牧馬關騎兵令』，據說這兵符和騎兵團長有同等
的地位，拿著(hold)它可以自由使用牧馬關的馬匹。
C_LONG
                );
                set("unit","面");
                set("weight", 10);
                set("value",({10, "silver"}) );
                set("no_sale", 1 );
}
 
int hold_mark(string arg)
{
    if( !arg || arg != "permit" ) return 0;
    if ((string)environment(this_player())->query("short")=="馬房" ) {
        if (this_object()->query_temp("hold_permit") ) {
             tell_object(this_player(),
                     "馬伕對你說，這面令牌的時效已過了。\n" );
             this_player()->set_temp("cavalry_mark",0);
              }
        else  {
             tell_object(this_player(),
                "你拿著令牌，馬伕嚇得頭都不敢抬一下。\n" );
             this_player()->set_temp("cavalry_mark",1);
             this_object()->set_temp("hold_permit",1);
              }
        } else
        tell_object(this_player(),
                "你拿著令牌像個白痴一樣晃呀晃呀地，可是沒人理你。\n" );
        return 1;
}
