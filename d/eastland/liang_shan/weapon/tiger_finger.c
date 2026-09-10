#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("tiger finger","手指虎");
       add("id",({"finger","tiger"}) );
       set_short("手指虎");
       set_long(
       "手指虎其實就像是有刺的手套，可以以此攻擊敵人，但由於使用他的\n"
       "人必需與敵人貼身肉搏，因此不論攻擊敵人或自身遭受攻擊都較平常來的\n"
       "嚴重許多。也因此，較強的山賊特別偏愛這種武器。\n"
	);
	
	set( "unit", "套" );
 	set("block_tactic",0);
 	set( "weapon_class", 17 );
        set("type","unarmed");
	set( "min_damage", 10 );
	set( "max_damage", 19 );
	set( "nosecond", 1 );
	set( "weight", 65 );
	set("bleeding",2);
	set( "value", ({ 42, "gold" }) );
	set( "wield_func","wield_finger" );
	set( "unwield_func","unwield_finger" );
}	
