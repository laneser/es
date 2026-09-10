#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("swamp eel", "鱸鰻");
	add("id",({"fish","eel"}) );
	set_short("鱸鰻");
	set_long(
		"這是一條巨大的鱸鰻，渾身都是不規則的雲狀斑，體色頗深，\n"
		"牙齒尖細但銳利，東方人多相信鰻魚有滋補強身的特殊功用。\n"
	);
	set( "unit", "條" );
	set( "likefish",1);
	set( "pursuing",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 13 );
	set_skill("swimming",100);
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

