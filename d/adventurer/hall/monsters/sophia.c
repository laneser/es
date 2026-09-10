#include "mudlib.h"
#include <daemons.h>

inherit MONSTER;

void init()
{
add_action("do_sit","sit");
}
void create ()
{

    ::create();
    set_level(15);
    set_name("Officer Sophia","書記官 索菲亞");
    add("id",({"officer","sophia"}) );
    set_short("書記官 索菲亞");
	set_long(@C_LONG
書記官 索菲亞是一個綠髮長耳的女孩，有著可愛的臉龐與燦爛的笑容。
她現在為諾達尼亞的圖書館工作，由於耶拉曼國王對冒險很有興趣，特地派
她來冒險者公會收集資料，如果你有任何有關冒險的故事，可以在旁邊的皮
椅上坐下來，慢慢講給她聽，你將會因此而獲得一些報酬。
C_LONG
	);
    set("alignment",500);
    set( "gender", "female" );
    set( "race", "elf");
    set( "unit", "個" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",18);
    set_perm_stat( "int",22);
    set_perm_stat( "karma",23);
    set_skill("unarmed",70);
    set_skill("parry",60);	
    set ("max_hp",400);
    set ("hit_points",400);
    set ("wealth", ([ "gold":100]) );
    set_natural_weapon(20,10,20);
	set_natural_armor(50,40);
	set ("aim_difficulty",([ "weakest":30,"vascular":10]) );
	set("special_defense", (["fire":10,"none":20,"cold":-10]) );
    set ("weight", 400);
    wield_weapon("/d/adventurer/hall/weapons/claw");
    equip_armor("/d/deathland/armour/cloth05");
    equip_armor("/d/deathland/armour/necklace01");
    equip_armor("/d/deathland/armour/gloves01");
}
int do_sit()
{
     int explore,total_points,EXPLORE1,num;
     explore  = (int)this_player()->query_explore_points();
     total_points=EXPLORE_D->query_total_explore(); 
     EXPLORE1=explore*10000/total_points;
     if (EXPLORE1 > 10000) EXPLORE1 =10000;
     if((string)this_player()->query("class") != "adventurer" ) {
     write("書記官 索菲亞說道: 你又不是冒險者，來這湊什麼熱鬧?\n");
     return 1;
     }
     if ((int)this_player()->query_level() < 4 )
     return notify_fail("書記官 索菲亞說道: 我想你的等級太低了，可能對我沒有幫助。\n");
     if ((int)this_player()->query("adv_cash") < EXPLORE1 ) {
     tell_object(this_player(),set_color("你開始敘述你最近的冒險事蹟，索菲亞聚精會神的記錄，不時流露出崇拜的眼神。\n\n", "HIG",this_player()) );
     	        tell_room( environment(this_player()),"\n"+
		this_player()->query("c_name")+"坐下來開始加油添醋的吹噓自己的冒險事情" 
		"但是索菲亞仍然是專心的傾聽。\n\n", this_player() );
     num = EXPLORE1 - (int)this_player()->query("adv_cash");
     this_player()->add("wealth/gold",num);
     this_player()->set("adv_cash",EXPLORE1);
     write("書記官 索菲亞說道: 謝謝你，這些是給你的報酬\n");
     if((string)this_player()->query("gender") != "male" ) return 1;
     else 
     write("書記官 索菲亞輕輕地在你的臉頰上親了一下.\n");
     return 1;
     }
     write("書記官 索菲亞說道: 你並沒有更好聽的冒險故事。\n"
           "多加點油，我對你有很高的期望....\n");
     return 1;      
}     
