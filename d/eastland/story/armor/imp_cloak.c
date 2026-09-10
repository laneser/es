#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("cloak of Wing race", "大首領披風");
        add( "id", ({ "cloak" }) );
        set_short( "大首領披風");
        set_long(@C_LONG
這是一件由千年蠶絲縫製成的鬥蓬，手工細緻，不但通風，穿起來亦冬暖夏涼，舒
適極了。
C_LONG
        );
        set("unit","件");
        set("type", "cloak" );
        set("material","cloth") ;
        set( "armor_class",7 );
        set("defense_bonus", 6 );
        set("weight", 50 );
        set("extra_skills",(["meditate":10]));
        set("extra_stats",(["dex":-1]));
        set("value", ({ 210, "gold" }) );
}



