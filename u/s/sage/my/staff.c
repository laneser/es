#include <mudlib.h>
inherit WEAPON;

void create()
{
      set_name( "jin-gu staff", "金箍棒");
        add ("id",({ "staff"}) );
     set_short( "jin-gu staff", "金箍棒");
        set("unit", "把");
        set_long(
            "",@C_LONG
這是一把渾身上下都閃著金光的兵器，只要你看它一眼，就覺得渾身哆嗦，
據說它本來是東海的一根定海神針，後來被齊天大聖當做武器了
棒上用紅筆寫著：如意金箍棒，重一百八十萬公斤
C_LONG
        );
        set( "weapon_class", 45);
        set( "type", "bo");
        set( "min_damage", 25);
        set( "max_damage", 47);
        set( "no_sale", 1);
        set( "weight",180 );
        set( "value", ({ 3800, "silver" }) );
}
