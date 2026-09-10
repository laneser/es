#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(16);
        set_name( "white lion","玄天玉獅" );
        add("id",({"lion"}));
        set_short( "玄天玉獅" );
        set_long(@C_LONG
這是一隻毛髮潔淨，純白無瑕的獅子。它的體型大的驚人，足足有九個人的噸位那
樣大！玄天玉獅整天都是處於飢餓狀態，生性更是兇殘無比，往往一看到活的東西
總要好好玩弄一般，使之精疲力盡，然後再吞之入腹才肯擺休！唉呀，你發覺玄天
玉獅正向你撲了過來！
C_LONG
        );
        set("unit","只");
        set_perm_stat( "str", 28 );
        set_perm_stat( "int", 12 );
        set_skill( "dodge", 60 );
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        set( "killer", 1 );
        set( "c_killer_msg","你突然發覺玄天玉獅張開大口正向你撲了過來....");
        set( "alignment", -500 );
        set_natural_weapon(28,18,29);
        set_natural_armor(60,15);
        set_c_verbs( ({ 
           "%s張開它的大口，一口向%s咬去",
            "%s迅速地向%s撲去",
           "%s揮動它的利爪，向%s抓去"}) );
        set_c_limbs( ({ "頭部", "身體", "腳部" }) );
}
