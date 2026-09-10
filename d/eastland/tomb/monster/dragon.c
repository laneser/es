
#include "../almuhara.h"

inherit MONSTER;

void create()
{
	object ob1; 
	::create();
	set_level(15);
	set_name( "golden dragon", "金龍" );
	add ("id", ({ "dragon" }) );
	set_short( "金龍" );
	set_long(
    "金龍 ---- 這是皇帝為了防止心懷不軌的人進入陵墓，而命令大國師  孝光在石門\n"
    "上下的禁制所幻化成的奇獸。\n"
	);
    set( "killer", 1 );	
    set( "alignment",500);
    set( "gender", "male" );
    set( "unit", "只" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 25);
	set_skill("elemental",60);
	set_skill("dodge",100);
	set("special_defense", (["all":25,"none":60]) );
	set ("max_hp", 500);
	set ("hit_points", 500);
	set ("wealth", ([ "gold": 100 ]) );
	set_natural_weapon(30,25,30);
	set_natural_armor(78,30);
	set("natural_weapon_class2",70);
	set ("natural_min_damage2", 25);
	set ("natural_max_damage2", 45);
	set_c_limbs(({"身體","頭部","腳部","手臂"}));
	set_c_verbs(({"%s用它的利爪向%s抓去","%s用它那長滿利牙的嘴巴向%s咬去" }));
    set ("weight", 400);
    set ("unbleeding",1);
    
}
