#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "mew", "海鷗" );
	add( "id", ({ "mew" }) );
	set_short( "海鷗" );
	set_long("這是一種海鳥\n");	
	set("unit","只");
    set( "alignment", -50 );
	set_perm_stat( "dex", 4 );
	set_c_verbs( ({ "%s往下俯衝，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
#include <replace_mob.h>
}
