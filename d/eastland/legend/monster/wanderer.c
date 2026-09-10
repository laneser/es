#include <mudlib.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(15);
  set_name("wanderer","流浪者");
  add( "id", ({ "wanderer" }) );
  set_short("流浪者");
  set_long(@C_LONG
一個孤苦無依到處流浪的人。據說，他本出身於一個顯赫的家族，但是，朝代更替
，一時殺伐四起，不但使得他的家園飽受摧殘，更是和親人失散，這使得當時年紀
很小的他不知所措，至今，他卻還沈浸在幼時的記憶，以為身處在幸福的環境中。
現在，他不知道何處可去，何處是他的家，更不知道渡過了今天，明天又是什麼樣
的情況，你從他身的身上處處可見戰亂帶來的影響，古有云：「明知兵者是兇器，
聖人不得己而用之。」希望所有在位者都能存有悲天憫人的胸懷，瞭解權力並不是
手中殺人的籍口。
C_LONG  
    );
  set( "race", "human" );
  set( "unit", "個" );
  set( "gender", "male");
  set_natural_weapon(30,18,33);
  set_natural_armor( 70, 18 );
  set( "max_hp", 400 );
  set( "hit_points", 400 );
  set_perm_stat( "int", 17 );
  set_perm_stat( "str", 20 );
  set_perm_stat( "dex", 22 );
  set_perm_stat( "pie", 18 );
  set("chat_chance",5);
  set("chat_output",({
     "流浪者說道：......\n",
     "流浪者說道：我的家....唉..\n"
  }) );
  set( "att_chat_output", ({
     "流浪者哭喪著臉道：我這麼可憐，你還在打我？\n"
  }) );
}
