#include "../iigima.h"
#include <stats.h>

#include <conditions.h>
inherit MONSTER ;

void create ()
{

        ::create();
        set_level(14);
        set_name( "Evil mage Chim","邪術師奇姆" );
        add ("id", ({ "drow","mage","chim" }) );
        set_short( "Evil mage Chim","邪術師奇姆" );
        set("unit","位");
        set("alignment",100);
        set("weight",500);
        set("wealth/copper",3800);
        set_long(
@C_LONG
看他瘦小的身驅和駝背的樣子令你感覺他好像很可憐，他是黑暗精靈
村的邪術師，也是老村長的胞弟，年輕的時候曾經周遊四方，得到了許多
寶物，尤其是頭上所戴的頭巾，更是極品。雖然名為邪術師，但是他卻很
樂意幫助(help)人。
C_LONG
        );
        set_skill( "dodge", 70 );
        set_skill( "dagger", 70 );
        set_skill( "anatomlogy", 67 );
        set("defense_type","dodge");
        set( "aim_difficulty",([ "vascular":30,"weakest":30,"critical":30 ]) );
        set( "aiming_loc", "vascular" );
        set( "special_defense", ([
                "all":30, "fire":-10, "cold":-10, "evil":60, "divine":-30 ]) );
        set_perm_stat("int", 22);
        set_perm_stat("kar",19);
        set("max_hp",500);
        set("hit_points",500);
        set_natural_weapon(20,10,20);
        set_natural_armor(50,5);
        set ("race", "drow");
        set ("gender", "male");
        set( "tactic_func", "emit_confuse" );
        set_c_limbs(({"身體","腳部","手臂"}));
        set( "inquiry", ([
                "help" : ({
"哎呀呀～年輕人, 需要幫助嗎? 我很樂意幫助你, 可是我只會鍊金術耶～\n"
"最近不是在禁斷之地有許多的蛇(snake)嗎? 好像很危險哦, 可是....\n"
                  }),
                "snake" : ({
"嗯．．我最近從書本上看到，某種蛇的眼睛能發光(light)，好像很有用的樣子。\n"
                   }),
                "light" : ({
"詳細的情形我也不知道啦～好像是叫作蛇眼之石(stone)吧！\n"
                  }),
                "stone" : ({
"聽說蛇眼石是在司娜可女神神殿裡，可是那裡不準靠近，所以我也沒看過..\n"
                  })
                        ]) );
        wield_weapon(OBJ"scale_dagger");
        equip_armor(ARM"robe");
        equip_armor(ARM"lucky_headband.c");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="stone of snake's eye"))
     return 1;
write("奇姆說道：喔...這是蛇眼石耶！好，我幫你將它作成漂亮的戒指吧。\n");
write("你看奇姆在那裡敲敲打打的，弄了好一會兒....\n");
   if (!this_object()->query("ring")) {
     write("奇姆說道：好了，這戒指就命名為蛇眼石之戒吧，來，給你。\n");
     ob=new(ARM"ring");
     ob->move(this_player());
     set("ring",8);
   }
   else
  write("奇姆說道：對不起哦！我的機器壞了，不能作戒指了\n");
   return 1;
}
int emit_confuse()
{
        object victim;
   if( random(10)>2 ||!(victim= query_attacker())) return 0;
            tell_room( environment(this_object()),
                    "奇姆從口袋拿出一把毛絨絨的毯子向你用力一揮!!\n",
                        this_object() );
            (CONDITION_PREFIX + "confused")->apply_effect( victim, 6, 10 );
        return 1;
}

