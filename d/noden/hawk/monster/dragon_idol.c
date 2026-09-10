#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "dragon idol", "龍形傀儡" );
        add( "id", ({ "idol", "dragon" }) );
        set_short( "龍形傀儡" );
        set_long(
                "你看到一個巨大的龍形傀儡，它的四肢似乎被一些看不見的線牽動著。\n"
        );
        set( "unit", "只" );
        set( "race", "dragon" );
        set( "alignment", -1100 );
        set_natural_armor( 50, 30 );
        set_natural_weapon( 40, 30, 50 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 26 );
        set( "hit_points", 700 );
        set( "max_hp", 700 );
        set( "aim_difficulty",
                ([ "critical":30,"vascular":20,"weakest":20,"ganglion":35]) );
        set( "special_defense",([ "all":30,"none":30 ]) );
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set( "tactic_func", "my_tactic" );
        set( "wealth/gold", 100 );
        set( "killer", 1);
        set( "pursuing", 1);
        set_c_limbs( ({ "頭部", "身體", "腿部", "尾巴" }) );
        set_c_verbs( ({ "%s張嘴往%s猛咬", "%s用巨爪抓向%s" }) );
}

int my_tactic()
{
        object *victim;

        if( random(20)<3 ) {
                tell_room( environment(this_object()),
                        "\n龍形傀儡發出一聲可怕的吼叫聲，從口中噴出許多黑色的氣體....。\n\n",
                        this_object() );
                victim = query_attackers();
                victim->receive_special_damage( "magic", 30 );
                return 1;
        }
        return 0;
}
