#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name("snake", "百步蛇" );
        set_short("百步蛇" );
        set_long(
@C_LONG
這是一尾美麗的蛇，不停的吐信並且冷冷的看著四周，你知道這是
條擁有劇毒的蛇類，還是別碰它好！
C_LONG
        );
        set( "unit", "條" );
        set( "alignment", -700 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
        set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}

int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "百步蛇張開嘴巴向你咬下，你覺得全身傳來一陣劇痛！！！\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
29, 3 );
        return 1;
}       
