#include "../oldcat.h"

inherit MONSTER;

void create ()
{
    ::create();
    set_level(16);
    set_name("the wizard Corak","矮靈巫師科拉克");
    add("id",({"wizard","corak"}) );
    set_short("矮靈巫師科拉克");
	set_long(
@LONG
一個矮靈巫師，科拉克是矮靈族歷史上最強的巫師，他負責向火神乞求每年的平靜。
LONG
	);
    set("alignment",-880);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "個" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",14);
    set_perm_stat( "int",26);
    set_perm_stat( "con",18);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",16);
	
    set ("wealth", ([ "gold":30]) );
    set ("max_hp", 500);
    set ("hit_points", 500);
    set ("aim_difficulty", ([ "critical":50,"weakest":30,"vascular":30 ]) );
    set_natural_armor( 36 ,15 );
    set_natural_weapon(2,7,15);
    set ("weight", 350);
    set_skill("shortblade",90);
    set("special_defense", (["all":33,"none":20]) ); 
    set( "tactic_func", "cast_spell");
    set("chat_chance",5);
    set("chat_output", ({
        "\n巫師說：我們明年的祭品還沒有著落，你願意犧牲自己嗎 ?\n\n",
        "\n巫師說：還好今年的祭品已經有著落了，又可以平安的度過一年。\n\n"
    }) );
    set("inquiry",([
        "volcano":"@@ask_volcano",
        ]) );
    wield_weapon(OWEAPON"shortsword1");
    equip_armor(OARMOR"mail1");
    equip_armor(OARMOR"ring1");
}

void ask_volcano(object who)
{
  tell_object(who,
    "巫師說：只要我們每年在這裡血祭一位活人，火神就不會發怒，火山就不會爆發。\n"
  );
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 6 ) {
      tell_room( environment(this_object()),
        "\n\n科拉克唸了一段咒語：FENDI MENTAR DIVI CREMBI MENTAR BONI\n"
        "空中出現一道青色的閃光直擊向科拉克的敵人，並且給與敵人致命的攻擊。\n\n"
         );
      victim->receive_special_damage("fire", 20+random(6));
      return 0;
    }
    if( (this_object()->query("hit_points")<180) && (random(100)<50) ) {
      tell_room( environment(this_object()),
        "科拉克呼喚矮靈的守護神醫療他自己。\n"
      );
      this_object()->receive_healing(35+random(30));
      return 1;
    }
    
    return 0;
}
