#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(17);
        set_name( "wild cat", "山貓" );
        add("id",({"cat"}));
        set_short( "山貓" );
        set_long(@C_LONG
這是一隻有著漂亮皮毛的動物，看它懶洋洋的樣子似乎沒有什麼危險性。但是森林中的
動物似乎都不敢靠近它，還是小心一點的好。
C_LONG
        );
        set("unit","只");
        set_perm_stat( "str", 23 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 13 );
        set_perm_stat( "kar", 20 );
        set_skill( "dodge", 100 );
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        set( "killer", 1 );
        set( "c_killer_msg","你突然發覺山貓正揮動它的利爪向你背後撲了過來....");
        set( "alignment", -500 );
        set_natural_weapon(50,22,30);
        set_natural_armor(80,1);
        set_c_verbs( ({ "%s揮動它的利爪，向%s抓去", "%s迅速地向%s撲去" }) );
        set_c_limbs( ({ "頭部", "身體", "腳部" }) );
}
