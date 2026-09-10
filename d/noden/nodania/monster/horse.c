#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(6);
	set_name( "mini horse", "迷你馬" );
	add( "id", ({ "horse" }) );
	set_short( "迷你馬" );
	set_long(
		"這是一匹可愛的迷你馬，如果你想練習騎術的話，可以試著騎(mount)它。\n" );
	set( "unit", "匹" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 2 );
	set_natural_armor( 25, 12 );
	set_natural_weapon( 8, 4, 10 );
	set( "c_extra_look", "$N正騎著一匹可愛的小迷你馬。\n");
	set( "alignment", 100 );
	set( "mountable", 1);
	set( "max_load", 1600 );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起來，用前肢在%s一陣上亂蹬" }) );
}

void init()
{
//	monster::init();
	mount::init();
	
}
