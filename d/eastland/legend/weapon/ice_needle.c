#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("ice needle","冰魄銀針");
    add("id",({"needle","dagger"}) );
    set_short("冰魄銀針");
    set_long(@C_LONG
冰魄銀針是由千年寒冰製成。銀針本身隱隱透出一陣陣的寒氣,即使是相隔三尺也
能感受。
C_LONG
       );
    set("unit","把");
    setup_weapon( "dagger",37,19,33);
    set("weight",40);
    set("value",({350,"gold"}));
    set("extra_skills",(["anatomlogy":10]));
}
