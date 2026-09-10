#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("feather fan", "羽扇");
        add ("id",({ "fan","wand",}) );
        set_short("羽扇");
        set_long(
        "這是一支看來平凡的羽扇，讓你想起了蘇軾的詞－羽扇綸巾談笑間，\n"
        "強虜灰飛煙滅....也許這隻扇子也有著特殊的魔力...。\n"
        );
        set( "unit", "支" );
        set( "weapon_class", 35 );
        set( "type", "wand" );
        set( "min_damage", 18 );
        set( "max_damage", 27 );
        set( "weight", 40 );
        set( "power_on", 1);
        set( "no_sale", 1);
        set( "value", ({ 7000, "silver" }) );
        set( "hit_func", "wand_hit" );
        set( "charge_left", 7 );
        set( "max_charge", 7 );
        set( "special_damage_type", "electric" );
        set( "special_damage", 60 );
        set( "special_c_msg", "一揮，招出一片烏雲，發出一股強大的電殛，你聞到一股焦味。");
}
