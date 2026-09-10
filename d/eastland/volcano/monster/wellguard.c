#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(15);
	set_name( "well guard", "看井守衛" );
	set_short( "看井守衛" );
        add("id",({"guard"}));
	set_long( 
             @LONG
一位看井守衛，他是族長派來看守這口井的，不過他覺的這個工作挺無聊的，但是
不要以為他好欺負，畢竟沒有兩把刷子是不會被酋長重用的。
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set( "max_hp", 500);
        set( "hit_points", 500);
        set_natural_armor(80,45);
        set_natural_weapon(15,5,10);
        wield_weapon(OWEAPON"spear1");
        equip_armor(OARMOR"cloak3");
        set ("chat_chance", 15);
        set ("chat_output", ({
             "守衛說：好無聊喔!\n",
             "守衛說：請不要亂丟(toss)東西到井裡好嗎 ?\n",
             "守衛說：你願意陪我聊天解悶嗎 ?\n",
             "守衛說：生命誠可貴，請不要跳井自殺。\n",
             }) );
        set ( "inquiry", ([
              "well" : "@@ask_well",
              "water": "@@ask_water",
              ]) );
}

void ask_well(object who)
{
   write("\n守衛說：這口井是我們族人的生命，我誓死也要守住它。\n");
   return;
}

void ask_water(object who)
{
  write("\n守衛說：你口渴了嗎 ? 我舀一口水給你吧 !\n");
  write("\n你說：謝謝啦 !\n");
  write("\n守衛說：不客氣 !\n");
  return;
}
