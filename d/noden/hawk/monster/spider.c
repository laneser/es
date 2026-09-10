#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(13);
        set_name( "Spanish Spider", "西班牙大蜘蛛" );
        add ("id", ({ "spider" }) );
        set_short( "西班牙大蜘蛛");
        set_long(@LONG
西班牙原裝進口大蜘蛛，看來這附近的蜘蛛網大概都是它搞的鬼。
LONG
        );
        set_perm_stat("dex",23);
        set_skill( "dodge", 50 );
        set( "alignment", -500 );
        set( "race", "insect" );
        set( "gender", "male" );
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        set( "aim_difficulty",
        ([ "critical":40,"weakest":40,"ganglion":10,"vascular":90 ]) );
        set_natural_weapon( 20, 15, 30 );
        set_natural_armor( 20, 40 );
        set ("special_defense", ([
                "monk": 20, "scholar": 20, "all": 20 , "none" : 20]) );
        set_c_limbs( ({ "頭部", "身體", "前腳"}) );
        set_c_verbs( ( {"%s衝到你面前，從嘴巴吐出一道毒液往%s一陣亂噴",
                        "%s突然延著網子往上爬，再從空中落下來咬%s",
                        "%s四處亂竄，用長滿倒鉤的腳踢向%s"}));
}
