#include <../mumar.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(17);
        set_name( "fight horse", "戰馬" );
        add( "id", ({ "horse" }) );
        set_short( "戰馬" );
        set_long(
        "這是一匹高大、強壯、雄偉的紅色牧馬關戰馬，你站在旁邊覺得自己矮了一截。\n"
        "你覺得若能騎(mount) 著它在戰場上奔馳，一定是人生一大樂事。\n");
        set( "unit", "匹" );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 76,39 );
        set_skill("dodge",80);
        set( "alignment", 300 );
        set( "extra_look","$N正騎著一匹火紅的牧馬關戰馬，看起來一付很威風的樣子。\n");
        set( "mountable", 1);
        set( "max_load", 2300 );
        set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
        set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起來，用前肢在%s一陣亂踩"}) );
        equip_armor(OBJS"saddle");
}
void init()
{
        mount::init();
}
