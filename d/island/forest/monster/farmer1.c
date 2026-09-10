#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Gardener","老園丁");
    set_short("老園丁");
    set_long(@LONG
    一個魔族的老公公，全身皮膚都曬得黑黝黝的，正辛勤的清除御花園中
的落葉及雜草；如果你有什麼罕見的植物想要種，那麼他會很樂意為你服務
的，因為，收集稀有植物來充實御花園，正是他的工作！
LONG
            );
    set("unit","位");
    set("race","daemon");
    set("gender","male");
    set("alignment",200);
    set_perm_stat("dex",7);
    set_perm_stat("str",5);
    set("max_hp",125);
    set("hit_points",125);
    set_skill("unarmed",30);
} 

int accept_item(object player,object obj)
{
    if( !obj || !(obj->query("luoko_seed"))) return 0;
      if( (string)obj->query("getter") != (string)player->query("name") ){
      write(@GET
老園丁奸笑道：哦，小子，你這種子是偷來的吧？沒收！！就把種子收起來了！！
GET
           );
      return 1;
      }
    tell_room(environment(),
    "老園丁瞪大著眼睛，用顫抖著的雙手接過種子，急忙把它種入泥土中！\n");
    obj->remove();
    call_out("grow_up",5,this_player() );
    return 1;
} 

int grow_up()
{
    if( present("luoky")) {
    tell_room(environment(),@ALONG

魎皇鬼以為園丁種的是蘿蔔，以迅雷不及掩耳的速度把種子挖走了.........
天啊，你都還沒反應過來勒！！！

老園丁嘆氣道：小子，只好再去找一顆種子了............
ALONG
             );
    return 1;
    }
    tell_room(environment(),@BLONG
老園丁說道：小夥子，這樣就行了；請轉告(report)阿重霞公主，就說龍皇沒事了，
好嗎？
BLONG
             ); 
    this_player()->set_temp("seed_ok",1);
    return 1;
}  
