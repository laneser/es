
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Blacksword＿Ya＿Sha", "黑夜叉" );
        add( "id",({ "sword" }) );
        set_short( "Blacksword＿Ya＿Sha", "黑夜叉" );
        set_long("this is a black blade.\n",
            " 這是一把劍身烏黑，劍長且薄的利劍，這也是武士副隊長星＿卡的愛劍\n"
        );
        set( "unit", "把");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 40 );
        set( "nosecond",0);
        set( "weight", 170 );
        set( "value", ({ 150, "gold" }) );
}


