#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Sky longsword","怒龍劍");
        add ("id", ({"longsword","sword" }) );
        set_short("怒龍劍");
        set_long(@LONG
一把劍柄雕刻著雙龍頭用太白金精打造的武器。劍身的白色光輝達十丈長，發出陣
陣寒氣。   
LONG
        );
        set("type", "longblade");
        set("unit","把");
        set("weapon_class",35);
        set("min_damage", 20 );
        set("max_damage", 40);
        set("weight", 100);
        set("value", ({ 1000, "silver" }) );
        set_c_verbs( ({ 
           "的%s發出十丈白色光輝斜劈%s",
           "飛躍而起，手持%s一道人影往%s電射而去",
           "快速地揮動%s，對著%s連砍三刀",
           "準備使出「毀天滅地」的一式，手中%s對著%s的弱點狠狠一擊"           
        }) );
}
