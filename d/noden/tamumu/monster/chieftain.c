#include <mudlib.h>
inherit MONSTER;

void create()
{
        object ob1, ob2;

        ::create();
        set_level(18);
        set_name( "sa-ba'tuka", "撒巴吐卡" );
        add( "id", ({ "chieftain", "tamumu", "tamumu chieftain" }) );
        set_short( "塔姆姆酋長 撒巴吐卡" );
        set_long(@C_LONG
撒巴吐卡是塔姆姆族的酋長，他不但是塔姆姆最偉大的戰士，而且他
智慧也很高，你看到他的臉上有五道藍色的刺青，代表他是塔姆姆族
最強壯的勇士。
C_LONG
                );
        set( "max_hp", 550 );
        set( "hit_points", 550 );
        set( "unit", "位" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", -900 );
        set( "tactic", "berserk" );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 23 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "pie", 14 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 90 );
        set_skill( "block", 100 );
        set_skill( "tactic", 100 );

        set( "wealth/gold", 60 );
        set( "natural_armor_class", 70 );
        set( "natural_defense_bonus", 25 );
        set( "inquiry", ([
                "juraken":"@@ask_juraken",
             "flesheater":"@@ask_flesh"
                        ]) );

        ob1 = new( "/d/noden/tamumu/obj/sword" );
        ob1->move( this_object() );
        wield_weapon( ob1 );

        ob2 = new( "/d/noden/tamumu/obj/chief_shield" );
        ob2->move( this_object() );
        equip_armor( ob2 );
}

int ask_juraken()
{
        tell_object( this_player(),@LONG
撒巴吐卡大聲的說道：哼！！可惡的裘拉根。當年發現他欲謀奪我們塔姆
姆族歷代相傳的寶藏，於是被我趕出來，想不到短短沒幾年，當年沒有斬草除
根的後果就出現了：仗著自己學到了錫卡拉教的邪法，現在的裘拉根以經不是
簡簡單單可以應付的掉的。所以上次我們決定帶肉食獸(flesheater)一起攻擊
鳥人谷，因為肉食獸不怕裘拉根的錫卡拉結界。想不到作戰到最激烈的時候，
用來控制肉食獸的寶珠竟然失去了魔力，發狂的肉食獸敵我不分，把我們塔姆
姆戰士殺的血流如河，費了千辛萬苦才擒服它，帶了回來。也因此上次的作戰
失敗了，真是可惜啊~~~
LONG
        );
        return 1;

}

int ask_flesh()
{
        object obj;
        if (this_player()->query_temp("kill_juraken") != 1)
        {
                tell_object(this_player(),@LONG
撒巴吐卡說：食肉獸，是我們塔姆姆族世代相傳保護著我們的聖獸，銳利
的爪子和強有力的牙齒撕碎敵人有如切菜一樣簡單。但是我們塔姆姆族有祖先
所留給我們的幻魔珠。這珠子的魔力可以使肉食獸的聽從我們的命令。上次一
場大戰，寶珠魔力消耗過大，因此失去了光芒。現在寶珠的魔力又補充好了，
如果你需要的話，只要幫我們殺死裘拉根，我就送你這顆寶珠。
LONG
                );
                return 1;
        }

        if (this_player()->query_temp("kill_juraken") == 1)
        {
                tell_object(this_player(),@LONG
撒巴吐卡說：嗯，謝謝你為我殺了裘拉根，上次講好的謝禮就是這東東。

撒巴吐卡拿出了一顆血紅色的珠子。
撒巴吐卡說：拿著這顆寶珠，走到食肉獸旁，喃喃的念著"ern!-sdl"就可降伏
那頭魔獸。
LONG
                );
		obj = new( "/d/noden/hawk/obj/pearl" );
                obj -> move(this_object() );
                command("give pearl to " + this_player()->query("name") );
                call_out("part2",5,this_player() );
                return 1;
        }
        return 1;
}


int part2()
{
        tell_object(this_player(),@LONG
撒巴吐卡告訴你：對了，你要得到神明的認可才行喔。也就是說要幫助在天上的
諸神取回他們流落人間的寶物。否則寶珠就沒有用了。
LONG
        );
        return 1;
}
