#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("king-kong bracers", "金剛環");
        add( "id", ({"bracers","bracer" }) );
        set_short("金剛環");
        set_long(@C_LONG
一雙被上樂金剛 (四臂瑪哈嘎拉) 加持過的石手環,
加持以極大之誅法可以幫你誅除一切的內外障。
C_LONG
                );
        set( "unit", "雙");
        set( "type", "hands" );
        set("material","stone");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 1500, "silver" }) );
}
