#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("emporer armband", "御賜臂環");
    add( "id", ({"armband", }) );
    set_short("御賜臂環");
    set_long(@C_LONG
臂環一般是頭陀使用的防具, 現在一些僧侶也使用臂環以增加防禦能力了。
御賜臂環是昔日少林武僧幫助李世民奪得天下時, 皇上御賜表彰的聖物... 
流傳迄今, 所有少林武僧皆以配掛它為榮。
C_LONG
              );
    set( "unit", "個");
    set( "type", "arms" );
    set( "armor_class", 4 );
	set("material","stone");
    set( "defense_bonus", 4 );
    set( "weight", 30 );
    set( "value", ({ 150, "gold" }) );
}
