#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("scale","八歧蛇鱗");
    set_short("八歧蛇鱗");
    set_long(
@C_LONG
這是枚八歧大蛇脫落的蛇鱗，黯淡的黝黑色不能反射任何光線，
它的邊緣極端的銳利，似乎能割裂任何東西，而它的形狀很特殊
，似乎能放(put)在某處。
C_LONG
            );
    set("unit","枚");
    set("weight",15);
    set("value", ({ 10, "silver" }));
    set ("no_sale", 1);
}
