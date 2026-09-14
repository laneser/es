#include "../story.h"

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name("wonderful straw","奇妙吸管");
        add( "id" , ({ "straw" }) );
        set_short( "奇妙吸管");
        set_long(@C_LONG
一根長長的的吸管，它的一頭有個大圓球，圓球是中空的，或許，你可用它來攝取
(suck)某些動物死後屍體裡的液體。
C_LONG  );      
        set("unit","根");
        set("weight",10);
        set("no_sale",1);
        set("value", ({500, "silver"}) );
}
void init()
{
    add_action("do_suck","suck");
}
int do_suck(string arg)
{
    object player,env,target,liquid;
    string cname;
    if ( !arg ) return notify_fail("Syntax : <suck corpse>\n");
    player=this_player();
    env=environment(player);
    if (!target=present(arg,env)) 
       return notify_fail("這裡沒有那樣東西。\n");
    cname=target->query("c_name");
    if( target->query("npc")!=SMOB"spider1" )
       return notify_fail("這個東西沒有任何液體可供你攝取！\n");
    liquid=new(SITEM"liquid");
    liquid->move(env);   
    write(sprintf("你靈巧地從%s上取得一些液體！卻不小心弄斷了吸管，把液體灑在地上！\n",cname));
    target->remove();
    this_object()->remove();
    return 1;
}