// deathknight.c


#define OBJ "/d/noden/ruin/obj/"
#define AREA "/d/noden/ruin/room/"
#define MOB "/d/noden/ruin/monster/"
#define WP "/d/noden/ruin/weapon/"
#define ARM "/d/noden/ruin/armor/"
#define DIARY "/d/noden/ruin/misc/"
#define QUESTNAME "lost_kingdom"

#include <mudlib.h>
inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Death Knight", "地獄騎士");
    add("id", ({ "knight", "death" }));
    set_short("地獄騎士");
    set("unit", "位");
    set_long("傳說中最厲害最可怕的不死騎士。\n");
    set("race", "undead");
    set("gender", "neutral");
    set("unbleeding", 1);
    set("max_hp", 5000);
    set("hit_points", 5000);
    set_perm_stat("str", 23);
    set_perm_stat("dex", 23);
    set_perm_stat("pie", 21);
    set_perm_stat("kar", 22);
    set_perm_stat("int", 21);
    set_natural_weapon( 50, 10, 20 );
    set_natural_armor( 80, 50 );
    set_skill("dodge", 100);
    set_skill("longblade", 100);
    set_skill("parry", 100);
    wield_weapon(WP"scythe");
    set("killer", 1);  
}

void die()
{
    object *items;
    int i;

    items = all_inventory(this_object());

    for(i = 0; i < sizeof(items); i++)
        items[i]->remove();

    tell_room(environment(this_object()), "地獄騎士發出一聲狂笑：「你以為這樣就能打倒我嗎？做夢！」\n\n地獄騎士的屍體又站了起來！\n\n", this_object());
    set("alt_corpse", MOB"deathknight");
    
    ::die(1);
}
