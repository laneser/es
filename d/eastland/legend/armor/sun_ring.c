#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "sun ring","日戒");
        add( "id", ({"ring"}) );
        set_short("日戒");
        set_long(@C_LONG
一隻以魔法紅寶石鑲制的小巧戒指，戒指上不時閃爍著如烈日般的光□，有著強大
的魔法防禦能力，不過由於封印在寶石上的力量過於強大，反而使得寶石本身脆弱
不堪。它的造形很獨特，似乎是為了某種設計，或許，戴上它會有什麼事發生也說
不定。
C_LONG
        );
        set( "unit", "只" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",1);
        set( "defense_bonus", 2 );
        set( "value", ({ 1000, "silver" }) );
        set("special_defense",(["magic":30, "evil":30]));
        set( "equip_func","equip_ring");
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
    set("light",1 ); 
    return 1;
}
int unequip_ring()
{
    set("light",0);
    return 1;
}    
