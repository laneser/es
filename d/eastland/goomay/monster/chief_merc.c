#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Tong the vice-chieftain", "唐副總鏢頭" );
	set_short( "唐副總鏢頭" );
	set_long(
		 "唐副總鏢頭人稱唐鐵掌，是威遠鏢局的第二號人物，現在他正在處理\n"
		 "局中事務，你有問題可以直接問他。\n"
	);
        add ("id",({ "tong","chieftain"}));
	set( "unit", "名" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 20 );
	set_skill( "dodge", 80 );
	set_skill( "unarmed", 90 );
	set_skill( "two-weapon", 100 );
	set("max_fp", 1800);
	set("force_points", 1800);
	set( "special_defense", ([ "all": 30 ]) );
	set( "gender", "male" );
	set( "alignment", 1000 );
	set_natural_armor( 75, 30 );
	set_natural_weapon( 31, 16, 28 );
	set( "natural_weapon_class2", 28 );
	set( "natural_min_damage2", 17 );
	set( "natural_max_damage2", 26 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s踏步向前，一記直拳打向%s", "%s左腿往%s一踢",
		"%s使一招「沙僧拜佛」，右拳打向%s", "%s往前一縱，左足往%s踢去",
		"%s一記「左右逢源」，雙拳直取%s", "%s使一招「鐘鼓齊鳴」，雙拳往%s打去",
		"%s一招「聲東擊西」，右足點向%s", "%s一招「猛虎出閘」，左拳如風，直取%s",
		"%s使一記「黑虎偷心」，右拳直擊%s" }) );

#include <replace_mob.h>
}
