#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name("cobra", "飯匙倩" );
        set_short("飯匙倩" );
        set_long(
@C_LONG
號稱蛇王的飯匙倩，又名眼鏡蛇，是蛇類中最毒最兇猛者
依照你對蛇類粗淺的認知，你也明白，不去惹它才是正確
的選擇。
C_LONG
        );
        set( "unit", "條" );
        set( "alignment", -730 );
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 14 );
        set( "natural_max_damage1", 18 );
        set( "tactic_func", "emit_poison" );
        set( "chat_chance",15);
//        set( "chat_output", ({
//                                         });
        set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
        set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}
int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "飯匙倩揚起頸部的大眼，狠狠向你咬下，你覺得一陣刺痛 ....\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
25, 6 );
        return 1;
}       
