#include "../../story.h"

inherit OBJECT;

void create()
{
        set_name("dragon wood","遁龍樁");
        add( "id" , ({ "wood" }) );
        set_short( "遁龍樁");
        set_long(@C_LONG
這是一個外形很像龍的木頭，另外在上面還畫了很多咒語，那咒語的意思是
(use_dragon_wood)。
C_LONG  );      
        set("unit","個");
        set("weight",10);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_use","use_dragon_wood");
}
int do_use(string arg)
{
    object player,env;
    string name;
    player=this_player();
    env=environment(player);
    name=player->query("c_name");
    tell_room(env,sprintf(
      "%s祭起手中的遁龍樁，瞬間，一陣清風把%s颳起，旋即消失於空間！\n",name,name),player);
    tell_object(player,"你祭起手中的遁龍樁，忽然來了一陣清風把你刮來這裡！\n");
    player->move_player(SCITY"house3","SNEAK");
    tell_room(environment(player),sprintf("一陣清風把%s刮來此地！\n",name),player);
    this_object()->remove();
    return 1;
}