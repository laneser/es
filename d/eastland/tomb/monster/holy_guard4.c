#include <races.h>
inherit RACE_HAWKMAN;

void create()
{
        ::create();
        set_level(15);
        set_name( "holy guard","聖地守衛" );
        add ("id", ({ "guard" }) );
        set_short( "聖地守衛");
        set("unit","位");
        set("alignment",400);
        set("wealth/gold",50);
        set_long(
"你看到一位聖地守衛，神態莊嚴肅穆地守衛著這兒。\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",25);
        set_perm_stat("str",25);
        set_natural_weapon( 48, 18, 45 );
        set_natural_armor( 70, 10 );
        set ("gender", "male");
        set("special_defense",(["all":10,"none":10]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
	equip_armor("/d/eastland/tomb/armors/shield2");
}
