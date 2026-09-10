#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("tears of avery","艾佛瑞之淚");
        add( "id",({ "avery", "whip" }) );
        set_short( "艾佛瑞之淚" );
        set_long(@CLONG
    這是大冒險家艾佛瑞專用的鞭子，傳說中是艾佛瑞在北方充滿不死生物的小島上
冒險時所得的戰利品，當時不知道發生了什麼事，使得他決定將這強大的鞭子命名為
「艾佛瑞之淚」。
CLONG
);
        set( "unit", "把");
        set( "weapon_class", 40 );
        set( "type", "whip" );
        set( "min_damage", 25 );
        set( "max_damage", 34 );
        set( "weight", 120 );
        set( "value", ({ 800, "silver" }) );
        set_c_verbs( ({
          "%s化為一道白影，迅捷無倫的卷向%s",
          "%s急速舞動，鞭影化為千百，直擊向%s",
         }) );
        set( "extra_skills",(["anatomlogy":10,"parry":10]));
}
