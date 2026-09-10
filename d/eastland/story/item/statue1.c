#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name("stone statue","石雕像");
        add( "id" , ({ "statue" }) );
        set_short( "石雕像");
        set_long(@C_LONG
一座栩栩如生的十尺長雕像；上像刻劃的是個神態威武的戰士，它正在跟一隻野獸
搏鬥。你不禁地想向它膜拜(worship)，景仰之心油然而生。
C_LONG  );      
        set("unit","座");
        set("prevent_get",1);
}
