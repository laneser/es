#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
        set_name("chi-eu's corpse","「蚩尤」的□體");
        add( "id" , ({ "corpse" }) );
        set_short( "「蚩尤」的□體");
        set_long(@C_LONG
這是「蚩尤」的□體。當時黃帝和蚩尤大戰，蚩尤戰敗後□體就被埋在解池旁，多
年來，不乏巨人族的勇士想要來此盜□卻都被中了沿途的埋伏，多年以後就不了了
之。
C_LONG  );      
        set("unit","具");
        set("weight",500);
        set("no_sale",1);
        set("chicorpse",1);
        set("value", ({1, "silver"}) );
}
