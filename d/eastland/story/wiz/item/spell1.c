#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("ghost-killed spell","滅魔符");
        add( "id" , ({ "spell" }) );
        set_short( "滅魔符");
        set_long(@C_LONG
上面寫著一堆蝌蚪文，還有一行隸文，那隸文的意思是(spell_use)。
C_LONG  );      
        set("unit","張");
        set("weight",10);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_spell","spell_use");
}
int do_spell(string arg)
{
    object player,env;
    player=this_player();
    env=environment(player);
    tell_room(env,sprintf(
      "滅魔符自%s手中飛起，旋即消失於地上。\n",player->query("c_name")),player);
    tell_object(player,"\n滅魔符自你手中飛起，旋即消失於地上。\n\n");
    env->set("trap_set",1);
    this_object()->remove();
    return 1;
}