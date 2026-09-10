#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "nail_spirit", "nail" );
}
 
void create()
{
        set_name( "seven nail", "七星追魂釘" );
        add( "id", ({ "nail" }) );
        set_short( "七星追魂釘" );
        set_long( @C_LONG
這是一支七寸長的紅色木釘，整隻釘子散發著檀香和某種你說不上來的奇異力量。
這隻木釘的釘頭看起來並不十分鋒利，讓你懷疑是不是真的能釘(nail)住些什麼。
C_LONG
                );
        set("unit","支");
        set("weight", 10);
        set("value",({1, "silver"}) );
        set("no_sale", 1 );
}
 
int nail_spirit(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="庫房大門" ) {
        tell_object(this_player(),
                "你拿著令牌，守衛對你一幅必恭必敬的樣子。\n" );
        this_player()->set_temp("army_mark",1);
        } else
    if ((string)environment(this_player())->query("short")=="密道崗哨" ) {
        tell_object(this_player(),
                "你拿著令牌，守衛對你一幅必恭必敬的樣子。\n" );
        this_player()->set_temp("army_mark",1);
        } else
        tell_object(this_player(),
                "你拿著令牌像笨蛋一樣晃呀晃呀地，可是沒人理你。\n" );
        return 1;
}
