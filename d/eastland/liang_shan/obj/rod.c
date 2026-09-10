#include "../takeda.h"
inherit OBJECT;

void create()
{
     set_name("fish rod","釣竿");
     set_short("fish rod","釣竿");
     set_long(
      "一根用竹子作成的簡單釣竿，上面連著釣線，浮標和釣鉤。\n"
      );
     set( "unit", "根");
     set("weight",40);
     set("value", ({ 20, "silver" }));
}
