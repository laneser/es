#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        ::create();
        set_level(10);
        set_name( "gonfu master", "教頭" );
        add( "id", ({ "master" }) );
        set_short( "教頭" );
        set_long( "你看到一個臭屁的教頭正在對新兵指指點點地。\n" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", 300 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 70 );
        set( "wealth/gold", 20 );
        set_natural_weapon( 22, 9, 17 );
        set_natural_armor( 43, 20 );
        set( "natural_weapon_class2", 28 );
        set( "natural_min_damage2", 10 );
        set( "natural_max_damage2", 22 );
        set( "chat_chance", 5 );
        set( "chat_output", ({
                "教頭對新兵說道: 你怎麼那麼笨，連個馬步都扎不穩。\n",
                "教頭對著新兵大罵: 還摸魚!!你就快倒大楣了!!\n",
                "教頭對你說: 看什麼看!!沒看過老鳥帶菜鳥啊!!。\n",
                "教頭用不屑的眼光正上下打量你。\n"
        }) );
        set( "att_chat_output", ({
  "教頭大叫:「孩子們!把這個肉腳打成肉包吧!!把我教你們的本事都用上來!!」。\n",
        }) );
 
    equip_armor(OBJS"pants");
    equip_armor(OBJS"cloth02");
}
