#include <mudlib.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(16);
  set_name("woman", "媽媽桑");
  add( "id", ({ "woman" }) );
  set_short("媽媽桑");
  set_long(@C_LONG
一位上了年紀的媽媽桑。媽媽桑現在正打著赤腳，辛勤地在井邊邊洗衣服邊和旁邊
的婦人聊天。對於初到此地的你而言，或許可以向她們打聽個什麼消息也說不定。  
C_LONG  
    );
  set( "race", "human" );
  set( "unit", "個" );
  set( "gender", "female");
  set_natural_weapon(30,18,33);
  set_natural_armor( 70, 18 );
  set( "max_hp", 400 );
  set( "hit_points", 400 );
  set_perm_stat( "int", 17 );
  set_perm_stat( "str", 20 );
  set_perm_stat( "dex", 22 );
  set_perm_stat( "pie", 18 );
  set( "inquiry", ([
     "村長":"@@ask_captain",
  ]) );
  set( "tactic_func", "my_attack" );
}
void ask_captain(object asker)
{
write(@C_LONG
媽媽桑道：喔，村長的家就在前面不遠處的矮房子。唉，可憐的村長．．
C_LONG
     );
}
int my_attack()
{
  object victim;
  if( random(20)>7 || !(victim= query_attacker()) ) return 0;
  tell_object(victim,"媽媽桑拿起她的洗衣刷往你面門一丟\n");
  tell_room(environment(this_object()),sprintf(
       "媽媽桑拿起她的洗衣刷往%s面門一丟\n",victim->query("c_name")),victim);
  victim->receive_damage(10);
  return 0;
}
