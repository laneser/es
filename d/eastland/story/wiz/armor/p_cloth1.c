#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "red silk du-do","紅緞地彩繡肚兜" );
        add( "id", ({ "cloth", "du-do" }) );
        set_short( "紅緞地彩繡肚兜");
        set_long(@LONG
一件設計可愛，小巧玲瓏的肚兜。用米色和硃紅兩色做地，並逢而制，主要用扇形
幾何圖案並加彩繡之花鳥紋搭襯而成。
LONG);
        set( "unit", "件" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 20);
        set( "defense_bonus", 5);
        set( "value", ({ 2000, "silver" }) );
}
