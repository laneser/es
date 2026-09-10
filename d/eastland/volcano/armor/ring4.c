
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("wraith flamen ring", "矮靈祭司之戒");
        add( "id", ({ "ring" }) );
        set_short("矮靈祭司之戒");
        set_long(
     "這是歷代矮靈族神殿祭司祭祀時穿戴的聖物，擁有無上的權力和神力。\n"
        );
	set("unit","只");
        set( "type", "finger" );
        set( "material" ,"element" );
        set( "defense_bonus", 6 );
	set("special_defense",(["evil":15]));
        set( "weight", 5 );
        set( "no_sale",1);
}
