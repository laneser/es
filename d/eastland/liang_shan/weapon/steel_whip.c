#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("steel whip","水磨八稜鋼鞭");
       add("id",({"whip","steel_whip",}) );
       set_short("水磨八稜鋼鞭");
	   set_long(
           "這是一把用特殊金屬製成的鋼鞭，因為太過堅硬而不能鑄造，只好用\n"
	   "水沙慢慢打磨．鞭身是八角形構造，稜特別突出，被打到可能很痛．\n"
	
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set("type","whip");
	set( "min_damage", 25 );
	set( "max_damage", 35 );
	set( "weight", 150 );
	set( "value", ({ 410, "gold" }) );
        set_c_verbs(({
    "%s鞭梢揮出一股勁風，打向%s",
    "%s隨手一揮，打中%s",
    "%s由空中如電般揮向%s",}));
    set("extra_skills",(["anatomlogy": 10 ]));
}

