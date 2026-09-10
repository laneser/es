#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("golden basket","金色籃子");
        add( "id" , ({ "basket" }) );
        set_short( "@@query_short");
        set_long(@C_LONG
一個純金打造的籃子，有點像狗籠之類的，可以裝(package)動物。
C_LONG  );      
        set("unit","個");
        set("weight",50);
        set("basket_used",0);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_package","package");
}
int do_package(string arg)
{
    object player,env,dog;
    player=this_player();
    env=environment(player);
    if ( !arg || (!dog=present(arg,env)) )
       return notify_fail("這裡沒有這樣東西。\n");
    if ( query("basket_used") )
       return notify_fail("這籃子已經裝了東西了。\n");
    if ( !dog->query("lucky") ) 
       return notify_fail("不能裝這樣東西。\n"); 
    tell_object(player,"你撫摸吉利的頭，並把它裝進籃子裡。你心裡頭想想，還是把它歸還給主人吧。\n");
    dog->remove();
    set("basket_used",1);
    return 1;
}
string query_short()
{
    return sprintf("金色籃子%s", (query("basket_used") ? " (裝著白狗吉利)" :
        "") );
}