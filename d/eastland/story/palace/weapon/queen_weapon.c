#include <mudlib.h>;

inherit WEAPON;

void create()
{
    set_name("Jade ru_i","玉如意");
    add("id", ({ "mace","ru_i","jade ru_i" }) );
    set_short("玉如意");
    set_long(@LONG
一把通體由和闐羊脂美玉製成的如意。如意長一尺又五寸，透散著只有上等玉石才
有圓潤柔和的光芒；柄上鏤金畫上了一隻鳳凰的圖案，金色鳳凰作勢欲飛，翎羽俱
現，端的是巧奪天工，唯妙唯肖。
LONG);
    set( "unit", "把" );
    set( "weight", 70 );
    setup_weapon("blunt", 35,10,10);
    set( "value", ({ 300, "gold" }) );
}
