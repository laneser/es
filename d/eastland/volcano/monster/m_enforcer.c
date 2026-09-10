#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The middle_temple enforcer", "正殿執事" );
	add( "id", ({ "enforcer" }) );
	set_short( "正殿執事" );
	set_long(
                "一位神殿正殿執事。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "str", 17 );
        set_perm_stat( "dex", 17 );
        set_perm_stat( "int", 22 );
        set_perm_stat( "pie", 25 );
	set( "wealth/gold", 16 );
        set( "hit_points", 210);
        set( "max_hp", 210);
        set("natural_armor_class",35);
        set("natural_defense_bonus",20);
        set_natural_weapon(10,2,5);
        wield_weapon(OWEAPON"whip3");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "god" : "@@ask_god",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\n執事說：哈 ! 你也見到那條黑龍了嗎，假如你覺的黑龍寶盒的傳說是真的，\n"
         "就去找吧。假如你覺的是假的，就把那條龍的話當做耳邊風吧。\n\n"
     ); 
}

void ask_god(object who)
{
  tell_object(who,
     "\n我們這個殿中所供奉的是火神，火神掌管這座火山，每當有火山爆發時，就是火神\n在生氣了，所以我們必須祈求火神，希望他不要遷怒於我們。\n\n"
  );
}
