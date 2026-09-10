#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(10);
        set_name( "Drow guard","黑暗精靈守衛" );
        add ("id", ({ "drow", "guard" }) );
        set_short( "Drow guard","黑暗精靈守衛" );
        set("unit","位");
        set_long(
@C_LONG
他是這個黑暗村落的守衛，黑暗精靈是個和平的種族，他的任務也相當　　　　
的輕鬆，由於最近黑暗精靈村的訪客變多了，老村長於是就拿了些傳單　
(paper)，叫他發給觀光客。
C_LONG
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 15);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 40);
        set("natural_defense_bonus",6);
   set( "special_defense", ([
      "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "male");
        set("wealth/silver",50);
   set("weight" , 700 );
        set ("race", "drow");
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身體","頭部","手臂"}));
        set( "inquiry", ([
        "paper" : ({
"傳單？喔．．．老村長最近為了女祭司的事情正煩惱著，那有空弄傳單？\n"
                  })
               ]) );

        wield_weapon(OBJ"copper_hammer");
        equip_armor(ARM"shield");
        equip_armor("/d/noden/asterism/armor/leggings02");
}

