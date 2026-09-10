#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(5);
        set_name( "Injured hawkman soldier","受傷的鳥人族士兵" );
        add("id",({"injured","hawkman","soldier"}) );
        set_short( "受傷的鳥人族士兵" );
        set_long(@LONG
一個渾身是血的鳥人族士兵，臉上看起來很痛苦的樣子，他滿臉血跡，
眼神無力的看著你，嘴角微揚，雙手微微的發抖。
LONG
        );
        set( "alignment", -400 );
        set( "gender","male" );
        set( "race","hawkman" );
        set( "chat_chance", 5 );
        set( "chat_output",({
"士兵痛苦的在地上呻吟:..唉..........我就快要死了\n",
"士兵喃喃自語...:聽說.... 在墓室祈禱(pray)，死去的亡靈就可以得到安息..\n",
"士兵深深地嘆了一口氣.... : 為什麼要有戰爭呢? \n"
        }));
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 9 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_perm_stat( "kar", 10 );
        set_perm_stat( "int", 3 );
        set_skill( "dodge", 10 );
                     set("hit_points",90);
}
