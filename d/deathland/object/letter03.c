// Echo/item/letter03.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("Incantation paper of Lock","禁錮咒文");
add("id",({"paper","incantation paper",}) );
set_short("Incantation paper of Lock","禁錮咒文");
set("c_long",@LONG_D
一張寫著奇怪符號咒文,只感到一種奇異的力量從紙上傳來.
LONG_D
);

set( "unit", "張");
set("weight", 0);
set("prevent_drop",1);
}
