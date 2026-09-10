
#include "../layuter.h"

inherit MONSTER;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Elf Lord", "精靈王" );
        add ("id", ({ "elf", "lord" }) );
        set_short( "精靈王" );
        set("unit","位");
   set_long( @LONG
精靈王是精靈村的領導者, 他操縱精靈村的各種物產使得精靈
們能夠各師其職、各盡其力地把精靈村建立成為一個豐衣足食
的世外桃源, 但當有外族入侵時, 他又轉而變成一位恐怖的戰
士－此乃因他於年輕時意外獲得一把『以太精靈劍』, 因而超
越所有族人而成為最強之戰士。而他又助現任國王之祖父亞拉
曼三世擊退入侵諾達尼亞之默爾斯人無數次, 而受勳「戰王」。
LONG );
        set("alignment",500);
        set("wealth/gold",20);
        set_perm_stat("int",30);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 20);
        set_perm_stat("kar",30);
        set_natural_weapon( 20, 10, 35 );
        set_natural_armor( 40, 40 );
        set ("gender", "male");
   set( "max_hp", 1110 );
   set( "hit_points", 1110 );
        set ("aim_difficult",(["critical":50, "vascular":20, ]));
        set ("special_defense",
          (["all":60,"fire":35,"poison":15,"none":25]));
        set ("race", "elf");
        set_c_verbs(({"用%s向%s砍去","用%s使出必殺一擊向%s攻擊","用%s向%s刺去"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
       
        set_skill("parry",100);
        set_skill("block",100);
        set_skill("longblade",100);
   set( "war_score", 1000000 );
        
        wield_weapon(LWEAPON"sword");
        equip_armor(LARMOR"boots");
        equip_armor(LARMOR"glove");
        equip_armor(LARMOR"shield");
        equip_armor(LARMOR"legging");
        equip_armor(LARMOR"plate");
        equip_armor(LARMOR"cloak");
}

void die()
{
   object scroll;

   scroll = new( "/d/mage/tower/obj/eb8_scroll" );
   scroll->move(environment(this_object()));

   tell_room( environment(this_object()),
     "『咚』的一聲, 一件東西從精靈王的手掌中落在地上。\n",
     this_object() );
   ::die(1);
}
