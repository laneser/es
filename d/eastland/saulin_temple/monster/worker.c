#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(6);
        set_name( "worker", "長工" );
        add ("id", ({ "worker" }) );
        set_short("長工");
        set("unit","位");
        set_long("這是一個在菜園工作的長工，全身髒兮兮的正在努力工作。\n");
        set("alignment",100);
        set("wealth/silver",20);
        set_perm_stat("str", 10);
        set_perm_stat("dex", 9);
        set_natural_weapon(8,2,5);
        set_natural_armor(30, 12);
        set ("gender", "male");
        set ("race", "human");
        set ("chat_chance",20);
        set ("chat_output",({
        "長工說道：最近有一些不知名的動物跑來菜園搗亂，真討厭。\n",
        }));
        wield_weapon(SAULIN_OBJ"spud");
}
