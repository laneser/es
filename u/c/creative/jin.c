#include <mudlib.h>
#include <ansi.h>

inherit MONSTER;

void create ()
{
 ::create();
 set_level(19);
 set_name("jin ke","荊軻");
 add("id","ke");
 set_short("大刺客 荊軻");
 set_long(@C_LONG
 赫赫有名的荊軻，曾經刺殺過秦王，他武功概世，現在他被殺手幫幫言任命
 在這裡負責訓練殺手的工作。只見他星目緊閉，劍眉深鎖，公乎有什麼事情
 需要人幫忙.\n
 @C_LONG
 );
 set("gender","male");
 set("race","drow");
 set("unit","名");
 set_perm_stat("str",30);
 set_perm_stat("int",30);
 set_perm_stat("kar",30);
 set_perm_stat("dex",30);
 set_perm_stat("pie",30);
 set_perm_stat("con",30);
 set("max_hp",3000);
 set("hit_points",3000);
 set_natural_armor(60,35);
 set_natural_weapon(72,29,55);
 set("chat_chance",10);
 set("att_chat_output",({
 "荊軻獰笑道：敢來野我?!找死!!\n"
  }));
 wield_weapon("/d/island/hole/weapon/axe1.c");
 set("inquiry",([
  "help": "@@ask_help",
  "task": "@@ask_task"]);
}

void ask_help(object asker)
{
 write(@D_LONG
 我有人任務很難完成,想多找些幫手,如果你是殺手,你可以向我問一下(task)
 如果任務完成了,我會報答你的\n
 @D_LONG
}

void ask_task(object asker)
{
write(@C_LONG
 今次的任務是殺rashudi...
 @C_LONG
}


