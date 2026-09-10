#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("fighter's dagger","戰士□匕");
    add("id",({"dagger"}) );
    set_short("戰士□匕");
    set_long(@C_LONG
一把由妖精長老用千年精鐵經百年不滅□火熔鑄而成的武器，呈黑色光澤，斷石切
玉削鐵如泥，恁地鋒利異常。
C_LONG
       );
    set("unit","把");
    setup_weapon( "dagger", 20, 13, 23 );
    set("weight",60);
    set("value",({60,"gold"}));
}
