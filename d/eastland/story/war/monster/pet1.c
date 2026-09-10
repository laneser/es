#include "../../story.h"
#include <conditions.h>
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(13);
	set_name( "Troll beast", "巨神獸" );
	add( "id", ({ "beast" }) );
	set_short( "巨神獸" );
	set_long(@LONG
一隻口張獠牙的巨人族野獸，經過了長久的訓練，富有很強的攻擊力。
LONG
	);
	set( "unit", "只" );
	set( "race","巨人");
	set( "alignment", -100 );
	set_natural_armor(60,15);
	set_natural_weapon(40,8,20);
	set( "killer", 1 );
        set( "pursing", 1 );
        set( "war_points", 50 );
	set_skill( "unarmed-parry", 60 );
        set_skill( "unarm", 100 );
        set_c_verbs( ({
             "%s張開闊口向%s咬去",
             "%s揮動利爪抓向%s"}) );
        set_c_limbs( ({ "頭部", "身體", "牙" }) );
        set("tactic_func","my_tactic");
}
int my_tactic()
{
     object victim;
     string name;
     if ( !victim=query_attacker() ) return 0;
     if ( random(10) > 1 ) return 0;
     name=victim->query("c_name");
     tell_room(environment(),sprintf("巨神獸張開闊口往%s身上一咬！\n",name),victim);
     tell_object(victim,"巨神獸張開闊口往你身上一咬！\n\n");
     (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,5,5);
     return 1;
}
