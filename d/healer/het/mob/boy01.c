#include "mudlib.h"
#include "../wang.h"
inherit MONSTER ;

void create ()
{
	object ob;

        ::create();
        set_level(3);
        set_name( "little boy", "童子" );
        add ("id",({ "boy"}));
        set_short( "童子");
        set("unit","位");
        set_long(
@C_LONG
他是一個七八歲大的孩子，正在辛勤的整理這花圃。看他小小年紀
卻能把這裡弄的乾乾淨淨的，真是不簡單。
C_LONG
);
        set("alignment",150);
        set("wealth/silver",15);
	set_perm_stat("dex",7);
	set_perm_stat("str",7);
        set_natural_weapon(4,3,5);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
	set("defense_type","dodge");
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
	ob = new(ITEM"key");
	ob->move(this_object());
}
