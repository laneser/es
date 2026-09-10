#include "/d/noden/drow/iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(15);
        set_name( "Captain Shukaise","侍衛隊長修凱思" );
        add ("id", ({ "drow", "captain","shukaise" }) );
        set_short( "Captain Shukaise","侍衛隊長修凱思" );
        set("unit","位");
        set("alignment",700);
        set("weight",400);
        set("wealth/copper",6000);
        set_long(
@C_LONG
這位英勇的戰士是黑暗精靈村的侍衛隊長，也是士兵們的領導者
，他看來已經有四十來歲了，但炯炯有神的目光環繞四周，他現
在正在為士兵的排班休假的問題煩惱著。
C_LONG
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex",14);
        set_perm_stat("str",21);
        set("max_hp",480);
        set("hit_points",480);
        set_natural_weapon(20,10,20);
        set_natural_armor(32,15);
        set ("inquiry",([
                "certification" : "@@ask_certification",
                        ]) );
        set ("special_defense",(["all":30, "cold":-10,
                        "fire":-10, "divine":-30,"evil":30, "none":15]));
        set ("race", "drow");
        set ("gender", "male");
        set_skill("longblade",70);
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill("block",75);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(OBJ"scale_lb");
        equip_armor(ARM"plate");
        equip_armor(ARM"shield");
        equip_armor(ARM"arms");
        equip_armor("/d/noden/asterism/armor/leggings02.c");
}

void die()
{
        object obj,who;
        tell_room(environment(this_object()),
                "侍衛隊長說道：你......你...你好壞哦~~~~~~。\n");
        ::die(1);
}

int ask_certification()
{
        object obj;
        if (!this_player()->query_temp("drow_certi")
                || this_player()->query_temp("drow_certi") == 3 )
        {
                tell_object(this_player(),@LONG
隊長吆喝道：去去，小朋友不要在這邊搗蛋，沒看到我在忙嗎？
LONG
                );
                return 1;
        }

        if (this_player()->query_temp("drow_certi") == 1 )
        {
                tell_object(this_player(),@LONG
隊長抬起頭來上下打量了你一番，點點頭說：嗯，那我們比劃兩招吧，
看看你夠不夠格稱的上是一名勇者，為了避免別人的打擾，我帶你到軍營
裡的教練場吧。
LONG
                );
                tell_room(environment(this_object()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "跟著修凱斯隊長走進軍營裡。\n",this_player() );
                this_player()->move_player("/d/noden/drow/square1.c","SNEAK");
	call_out("message",5,this_player() );
                return 1;
        }

        if (this_player()->query_temp("drow_certi") == 2 )
        {
                tell_object(this_player(),@LONG
修凱斯隊長說道：嗯，我以經聽到巴圖的報告了，這個徽章讓你帶在身上，
村長就會知道我的意思了。
LONG
                );
                obj = new("/d/noden/drow/obj/mark");
                obj->move(this_object() );
                command("give seal to "+(string)this_player()->query("name") );
                this_player()->set_temp("drow_certi",3);
                return 1;
        }
        return 1;
}
void message()
{
	tell_object(this_player(),@LONG
你聽到修凱斯隊長的聲音從空中傳來：小朋友，往南走一格就可以
碰到這次比武的主試者，想辦法打敗他吧。
LONG
	);
}
