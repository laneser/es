
#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(17);
        set_name( "Adventurer Keiwi","冒險家奇維" );
        add ("id", ({ "adventurer","keiwi" }) );
        set_short( "Adventurer Keiwi","冒險家奇維" );
        set("unit","位");
        set("alignment",740);
        set("weight",900);
        set("wealth/copper",3800);
        set_long(
@C_LONG
他是一位環遊世界的冒險家，由於他豐富的閱歷，當年畢克林老爹初
次到黑暗精靈村時，就是由他代為嚮導的。但是他最近似乎因為愛人
(lover) 失蹤而煩惱。
C_LONG
        );
        set_perm_stat("int", 16);
        set_perm_stat("str",23);
        set("max_hp",650);
        set("hit_points",650);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1", 13);
        set ("natural_max_damage1", 22);
        set ("natural_armor_class", 78);
   set( "special_defense", ([
       "all":20, "none":12]));
        set ("race", "human");
        set ("gender", "male");
        set_skill("longblade",70);
        set_skill("dodge",75);
        set_skill("parry",65);
        set( "inquiry", ([
             "snake" : ({"可帕的大蛇...禁地守衛不會讓你過去的喔 ..\n"}),
             "herb" : ({
                      "喔....蛇窩草哦...我有我有，可是只有一束，不能給你..\n"
                      "除非你幫我一個忙，我就給你蛇窩草....\n"
                       }),
             "help" : ({
       "你想幫我嗎？好，我在此的探險已經有數年了\n"
       "但是最近，我的油燈用完了..真糟糕...\n"
       "我正在找尋司娜可神殿的秘密，但是我需要一盞油燈，你能給我一盞嗎？\n"
                       }),
             "lover" : ({
                       "愛人？？等等吧....飯島愛小姐沒空為我介紹，再等一陣子吧\n"
                        })
                   ]) );
        wield_weapon(OBJ"copper_blunt");
        equip_armor(ARM"ring1");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="lamp"))
     return 1;
write("奇維說：太好了！！耶！我又可以繼續我的冒險了。\n");
   if (!this_object()->query("gress")) {
     write("奇維給你一束蛇窩草。\n");
     ob=new(OBJ"gress");
     ob->move(this_player());
     set("gress",1);
   }
   else
     write("奇維說：不妙！有人先來拿了，你等reboot吧...哈哈。\n");
   return 1;
}
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE
奇維高喊一聲：想不到我閱歷世界一生，竟敗在你的手中.....

你看到奇維的揹包中掉出了一件鎧甲。

DIE
,this_object());
   obj=new("/d/noden/drow/arm/lucky_plate");
    obj->move(this_object());
   ::die(1);
   }

