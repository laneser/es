#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        ::create();
    set_level(11);
    set_name("vault guard","庫房守衛");
    add ("id", ({ "guard" }) );
    set_short( "庫房守衛");
        set_long( @C_LONG
一個守衛兵正站得直直地看守著這座庫房。
C_LONG
        );
    set("alignment",100);
    set( "gender", "male" );
    set( "unit", "個" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
        set_skill("polearm",30);
        set_skill("parry",55);
    set ("max_hp",350);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "silver":80]) );
    set_natural_weapon(17,10,24);
    set_natural_armor(40,22);
    set ("weight", 350);
    set("chat_chance",5);
    set("chat_output",({
        "守衛說:這兒不是你該來的地方，快離開吧,不然我要報告長官羅。\n"
       }) );
    set( "att_chat_output", ({
         "守衛尖叫著:「敵人好久沒來了!!你正好給我機會練槍法!!下地獄去吧!!」。\n"
        }) );
 
    equip_armor(OBJS"mail01");
    wield_weapon(OBJS"lance");
}
