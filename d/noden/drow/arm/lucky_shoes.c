#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky shoes", "幸運鞋");
        add( "id", ({ "boots","shoes" }) );
        set_short( "幸運鞋" );
        set_long(
@C_LONG
這是一雙能帶來幸運的鞋子。由白色帆布細密的織成，鞋跟處有一
把小刀的標誌。
C_LONG
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
   set("extra_skills",(["steal": 10 ]));
        set( "defense_bonus", 5 );
        set( "weight", 38 );
        set( "value", ({ 120, "gold" }) );
}
