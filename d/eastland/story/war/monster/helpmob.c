#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
        set("help_war",1);
}
void init()
{
     object player;
     player=this_player();  
     if ( player->query("palace_war") ) {
        tell_room(environment(),sprintf(
            "%s對著%s喊道：可惡的蚩尤軍，吾等奉命殲滅你們，給我下地獄去吧！！\n",
            this_object()->query("c_name"),player->query("c_name")));
            this_object()->kill_ob(player);
     }
     ::init();
}
void die()
{
    int damage;
    object killer;
    killer=query("last_attacker");
    if ( killer) {
      if ( !killer->query("npc") ) {
         tell_object(killer,"\n空中傳來黃帝大怒的聲音：原來你是蚩尤派來臥底的！\n\n");
         tell_object(killer,"黃帝招來一道閃電劈在你頭上！！\n\n\n");
         tell_room(environment(),sprintf("黃帝招來一道閃電劈在%s的頭上！\n",
            killer->query("c_name")),killer);
         damage=killer->query("max_hp")*9/10;
         killer->add("hit_points",-damage);  
      }
    }
    ::die();
}
