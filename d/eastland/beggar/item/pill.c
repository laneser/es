#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("bear-snake pill","天山九轉熊蛇丸");
        add( "id" , ({ "pill" }) );
        set_short( "天山九轉熊蛇丸");
        set_long(@C_LONG
這是一顆白色的藥丸,聞起來有點臭臭的。九轉熊蛇丸是天山二老採集十頭大黑熊
掌和三十條大蟒蛇膽以及千年人□研製而成的,其珍貴無比, 更兼有起死回生的療
效。
C_LONG  );      
        set("unit","顆");
        set("weight",1);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
