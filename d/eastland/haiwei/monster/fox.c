#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "fox", "狐狸" );
	add( "id", ({ "fox" }) );
	set_short( "狐狸" );
	set_long("這是一種傳聞中很狡滑的動物，不過近看道還滿可愛的。\n");	
	set("unit","只");
    set( "alignment", 200 );
	set_perm_stat( "dex", 10 );
	set_c_verbs( ({ "%s，用嘴咬向%s", "%s用前爪往%s抓下" }) );
	set_c_limbs( ({ "頭部", "身體", "腳部","尾巴" }) );
#include <replace_mob.h>
}
