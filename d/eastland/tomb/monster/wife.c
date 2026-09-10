#include "mudlib.h"
 
inherit MONSTER;
 
void create()
{
	
	::create();
	set_level(18);
	set_name( "Archmaster's Wife Hsiao", "蕭小小" );
	add ("id", ({ "wife","hsiao" }) );
	set_short( "蕭小小" );
	set_long(
"在你面前的就是大國師的妻子 -- 蕭小小。她有著花一般的容貌，玉一樣的\n"
"肌膚，腰枝嫋娜，身材苗條，真是行一步也可人意兒，看一眼也使人魂消。\n"
"然而在她的眉宇之中，卻隱含著一股淡淡的憂愁，讓人覺得好生心疼。也許\\n"
"你可以問問她是如何跟大國師相識的。\n"
	);
    set( "gender", "female" );
    set( "race", "human" );
    set( "unit", "位" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 23);
	set ("max_hp", 799);
	set ("hit_points", 799);
	set ("wealth", ([ "gold": 150 ]) );
	set_natural_weapon(20,10,25);
	set_natural_armor(99,36);
	set ("special_defense",(["all":33,"none":33,"monk":33,"scholar":33]));
	set("aim_difficulty",(["vascular":30,"weakest":30,"ganglion":30]) );
    set ("weight", 400);
    set_skill("dodge",90);
    set_skill("dagger",100);
    set_skill("anatomlogy",70);
    set("aiming_loc","weakest");
    equip_armor("/d/eastland/tomb/armors/cloth");
    equip_armor("/d/eastland/tomb/armors/armband1");
    wield_weapon("/d/eastland/tomb/weapons/dagger");
    set( "inquiry", ([
         "archmaster" : "@@ask_master" ,
         "master" : "@@ask_master",
         "nickname" : "@@ask_name" ,
         "jade" : "@@ask_jade",
         "box" : "@@ask_box"
           ]) );
}
 
void ask_box()
{       object obj;
        if (this_player()->query_temp("tombkey") == 1) {
        command("bonk "+(string)this_player()->query("name"));
        command("say 箱子就是用來裝東西的啦....你要問幾次啊？\n");
        command("gag "+(string)this_player()->query("name"));
        } else {
        command("smile "+(string)this_player()->query("name"));
        command("say 箱子不是用來裝東西的嗎....不然你以為呢？\n");
        tell_object(this_player(), @ASK
 
蕭小小順手把箱子一移，在原來箱子的底下的位置有一隻鑰匙，不過她似乎沒有發現到。
 
奸詐的你趁著她一個低頭不注意，偷偷把鑰匙撿起。
 
ASK );
        obj=new("/d/eastland/tomb/item/key1");
        obj->move(this_player());
        this_player()->set_temp("tombkey",1);
        return;
        }
}
 
void ask_name()
{
        command("giggle");
        command("say 妾身小名叫 「阿福」。\n");
        command("blush");
        return;
}
 
void ask_master()
{
	command("sigh");
	command("say 不要再問了.....\n");
	command("twiddle");
	return;
}
