#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(14);
        set_name( "big rat", "大老鼠" );
        add( "id", ({ "rat" }) );
        set_short( "大老鼠" );
        set_long(
            "這是一隻高大、強壯的老鼠，看來它把鏡中的牧馬關裡能吃的全吃光了。\n"
            "它現在正趴在一包米袋上睡覺，如果你沒把握，最好不要吵醒它。\n");
        set( "unit", "只" );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 5 );
        set_natural_weapon( 35,20,35 );
        set_natural_armor( 75,28 );
        set_skill( "dodge", 70 );
        set( "alignment", -500 );
        set_c_limbs( ({ "頭部", "身體", "腿部", "尾巴" }) );
        set_c_verbs( ({ "%s張開大嘴，往%s一口咬下",
          "%s人立起來，用前肢在%s頭上一陣亂拳", "%s躺下來，用尾巴掃過%s"}) );
        set("c_death_msg",
          "%s 奄奄一息地說道：「人家..人家還沒吃飽啦...！」然後就倒地不起了..\n" );
}
 
void die()
{
        object killer;
 
        killer = query("last_attacker");
        if( killer ) killer->set_temp("mumar/done",1);
        ::die();
}
