#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(12);
    set_name("dwarf guard","矮人守衛");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a dwarf guard",
           "矮人守衛");
	set_long(@LONG
這個矮人守衛正保衛在矮人村莊的入口,但是他似乎渴望著能離開這裡到
酒吧(Pub)去.
LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "個" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
	set_skill("shortblade",78);
	set_skill("parry",55);
    set ("max_hp",390);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "gold":13]) );
    set_natural_weapon(27,15,25);
	set_natural_armor(43,19);
    set ("weight", 350);
    set ("inquiry",([
         "pub":"@@ask_pub",
         "wine":"@@ask_wine",
         "maze":"@@ask_maze",
        ]) );
    
    set("chat_chance",10);
    set("chat_output",({
        "守衛很想要睡覺但是在崗位上因此他覺得很無奈.\n",
        "守衛說:假使你迷失在迷宮(maze)中,往西三四步你就可以離開了.\n"
       }) );
    equip_armor(Armour"/ringmail01");
    wield_weapon(Weapon"/shortsword02");
    equip_armor(Armour"/armband01");
     
}

void ask_pub(object who)
{
  tell_object(who,@MSG1
守衛說:當我在站崗的時候,不要跟我提起酒吧,那會讓我想起美妙的啤酒(wine),
守衛吞了一口口水.
MSG1
   );

}

void ask_wine(object who)
{
   tell_object(who,@MSG2
啤酒,可惡,當我在站崗的時候,不要跟我提起酒,我會忍不住想要偷喝,可是這是違
反紀律的.守衛瞪著你說

不過一些果汁或許可以讓我解解饞.守衛又吞了一口口水.
MSG2
   );
}

void ask_maze(object who)
{
   tell_object(who,@MSG3
守衛說:這迷宮已經幫助我們許多次,在多次的矮人巨人戰爭中,巨人總是無法
突破這最後一道防線.這個迷宮的魔法障壁並不是一般人能解開的.嗨!嗨!
MSG3
   );
}

int accept_item(object ob1,object ob2)
{
    if ( !( ob2->id("juice") ) )
      return 0;
    else
      {
      tell_object(environment(),@MSG4
守衛說:謝謝.
守衛很快地把果汁當成酒地喝了起來然後跟你閒聊了起來
守衛著這個地方其實蠻恐怖的, 洞裡中不知道會有甚麼奇奇怪怪的東西
跑出來, 而且地底常常有一些莫名奇妙的聲音傳出, 常讓我覺得很可怕
所以一但有空的時候, 我就會到酒吧去喝酒聊天, 你知道酒吧罷, 那兒
的酒保是個很有趣的傢伙, 他知道許許多多的傳聞軼事(rumors).
MSG4
       );
      ob1->set_explore("deathland#36");
      ob2->remove();
      return 1;
      }
}
