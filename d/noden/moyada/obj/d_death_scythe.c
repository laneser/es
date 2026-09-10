#include "../moyada.h"

inherit WEAPON;

void create()
{
    seteuid( getuid() );
	set_name("Death Scythe", "死神鐮刀");
	add ("id",({ "scythe", }) );
	set_short("死神鐮刀");
	set_long(@C_LONG
一把很十分鋒利的大鐮刀，據說是死神心愛的武器。
它可以用來割草(cropp)嗎? 
C_LONG
	);
	set( "unit", "把" );
	set( "weapon_class", 21 );
        set( "type", "longblade" );
	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "nosecond", 1);
	set( "value", ({ 10, "silver" }) );
}

void init()
{
        add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
      object ob;
      write(@ALONG
            
        死神鐮刀很生氣地說: 你想用我來割草! 從來沒人敢如此對待我。
        死神鐮刀從你的手中跳起來，飛到空中並很不爽的舞著。

ALONG
             );
      ob=new( MOYADA"monster/death_scythe" );
      ob->move( environment(environment(this_object())) );
      this_object()->remove();
      return 1;
}
