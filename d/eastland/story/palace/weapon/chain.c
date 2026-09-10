#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("Wolf chain","青狼鎖");
    add("id", ({ "chain" }) );
    set_short("青狼鎖");
    set_long(@C_LONG
一條丈長的武器，前端刻著一個青鬱郁的狼頭，張牙舞爪，可怖已極。
C_LONG
    );
    set( "unit", "件" );
    setup_weapon("chain", 30,15,23);
    set( "weight",100);
    set( "value", ({ 1500, "silver" }) );
}

