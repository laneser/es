#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky-bracers","幸運手鐲");
        add( "id", ({"bracers" }) );
   set_short("幸運手鐲");
        set_long(
"這是一個能帶給你幸運的漂亮手鐲，可是，好像只有給一些不守正道的人．．\n"
                );
        set( "unit", "個");
        set ( "type", "hands" );
   set("armor_class",5);
      set("defense_bonus",3);
   set( "material", "thief" );
        set( "weight", 22 );
        set( "value", ({ 200, "gold" }) );
        set( "no_sale",1);
        set("extra_skills",(["backstab":10,"dodge":5]));
}
