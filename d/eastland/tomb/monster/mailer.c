#include "../almuhara.h"
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "mail man", "信差" );
        set_short( "信差" );
        add( "id", ({ "man" }) );
        set_long(
@C_LONG_DESCRIPTION
你看到一個官差打扮的人，他的胸前有一處很深的刀傷，正奄奄一息地在這尋找
出路。對於你的來到，他似乎相當高興，不過他好像已經沒有力氣向你求助了。
C_LONG_DESCRIPTION);
        set( "gender", "male" );
        set( "max_hp",120);
        set( "hit_points",1);
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 10 );
        set( "no_attack",1 );
        set_natural_weapon(12,5,15);
        set( "inquiry", ([
        "help" : "@@ask_help" ]) );
}
 
int ask_help()
{
object obj;
tell_object(this_player(),
@ASK
 
信差用微弱的聲調說：盜..賊......玉........佩.國....師.......
當你想問個清楚時.....卻發現他已經斷氣了.......
 
一塊玉佩從信差垂下的手中掉落。
 
也許是身中劇毒，信差的□體迅速地化成血水......滲入地面......
ASK);
obj=new("/d/eastland/tomb/item/break_jade1");
obj->move(environment(this_object()));
this_object()->remove();
}
