#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Spark Leggings","雅典娜閃亮脛甲" );
        add( "id", ({ "leggings","spark leggings" }) );
        set_short( "雅典娜閃亮脛甲" );
        set_long(
                "希臘戰神雅典娜最喜愛的脛甲，閃閃發光，看來似乎不錯。\n"
        );
        set( "unit", "只" );
        set("material","knight");
        set( "type", "legs" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 4700, "silver" }) );
}
