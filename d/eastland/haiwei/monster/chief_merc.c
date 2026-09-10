#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Chou", "周總鏢頭" );
	set_short( "周總鏢頭" );
	set_long("周總鏢頭剛從京城保了一趟鏢回來，現在正在這裡喝酒休息。\n");
	set( "unit", "名" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 80 );
	set_skill( "thrusting", 80 );
	set_skill( "two-weapon", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "gender", "male" );
	set( "alignment", 300 );
	set_natural_armor( 75, 30 );
	set_natural_weapon( 8, 5, 10 );
	set( "natural_weapon_class2", 8 );
	set( "natural_min_damage2", 5 );
	set( "natural_max_damage2", 10 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s踏步向前，一記直拳打向%s", "%s左腿往%s一踢",
		"%s使一招「沙僧拜佛」，右拳打向%s", "%s往前一縱，左足往%s踢去",
		"%s一記「左右逢源」，雙拳直取%s", "%s使一招「鐘鼓齊鳴」，雙拳往%s打去",
		"%s一招「聲東擊西」，右足點向%s", "%s一招「猛虎出閘」，左拳如風，直取%s",
		"%s使一記「黑虎偷心」，右拳直擊%s" }) );

	wield_weapon( "/d/eastland/haiwei/obj/pen" );
	wield_weapon2( "/d/eastland/haiwei/obj/pen" );
}
