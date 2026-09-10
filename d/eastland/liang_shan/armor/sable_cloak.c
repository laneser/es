#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("sable cape", "貂鼠皮襖");
        add( "id", ({ "cloak","cape" }) );
        set_short("sable cape","貂鼠皮襖");
        set_long(
                "This is a cape made of fur of sable.\n",
                "這是在長白山獵得的上好貂皮作成的皮襖，青白色的柔軟長毛隨\n"
                "著你的腳步搖曳著，看來相當拉風．但是得小心保護動物人士偷襲你．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",([ "evil":2, "fire":-4, "cold":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 999, "silver" }) );
}