#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Magic Hawk","魔鷹");
    add("id",({"hawk","eagle"}) );
    set_short("魔鷹");
    set_long(@LONG
這是一隻可怕的鷹，正瘋狂的拍動它的翅膀，對你怒目而視。
LONG
            );
    set("unit","只");
    set("alignment",-800);
    set("weight",600);
    set_perm_stat("str",17);
    set_perm_stat("dex",16);
    set("hit_points",300);
    set("max_hp",300);
    set("killer",1);
    set("pursuing",1);
    set("exp_reward",6000);
    set_natural_weapon(40,30,40);
    set_natural_armor(45,25);
    set("unbleed",1);
    set("c_killer_msg","突然間，魔鷹伸展雙翼及利爪向你衝了過來！");
    set_skill("dodge",80);
    set_c_verbs( ({"%s的尖喙啄向%s","%s的利爪抓向%s","%s的翅膀掃向%s"}) );
    set_c_limbs( ({"背心","利爪","頸部","額頭","翅膀"}) );
    set("alt_corpse",TWEP"dagger1");
    set( "death_msg","%s\n");
    set( "c_death_msg","%s說:今後我願跟隨您，主人！隨後幻化成一把匕首....\n");
 }
