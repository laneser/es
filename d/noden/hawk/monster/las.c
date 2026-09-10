#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Poet Las", "吟遊詩人 拉斯" );
        add ("id", ({ "las", "poet" }) );
        set_short( "吟遊詩人 拉斯");
        set_long(@LONG
拉斯是魔族中罕見的吟遊詩人，天性好殺，卻不喜和人結伴，正巧
與裘拉根結識為好友，為了要尋找高強的敵手，他就風塵僕僕的趕到死
亡競技場，為那些不自量力的冒險者開起地獄之門。他看起來臉色慘白
無光，青筋暴露，一副弱不禁風的樣子，不過你可千萬不要以為他這樣
就是好欺負的。
LONG
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_perm_stat("int", 30 );
        set_perm_stat("dex",15);
        set_skill( "dodge", 100 );
        set_skill( "blunt", 85 );
        set( "alignment", -1500 );
        set( "race", "daemon" );
        set( "gender", "male" );
        set( "hit_points", 900 );
        set( "max_hp", 900 );
        set( "killer", 1);
        set( "pursuing", 1);
        set( "tactic_func","my_tactic");
        set( "aim_difficulty",
        ([ "critical":80,"weakest":20,"ganglion":30,"vascular":50 ]) );
        set_natural_weapon( 20, 20, 30 );
        set_natural_armor( 25, 40 );
        set ("special_defense", ([
                "monk": 20, "scholar": 20, "all": 20 , "none" : 20]) );
        command("party form");
	wield_weapon(WEAPON"flute");
        equip_armor(ARMOR"shield1.c");
        equip_armor(ARMOR"god_2.c");
        equip_armor(ARMOR"white_suit.c");
}

int stop_attack(object player)
{
        call_out( "defend_las", 1, player);
        return 0;
}

void defend_las(object obj)
{
        int i;
        object env, *inv, atk;

        env = environment( this_object() );
        if( !env ) return;

        inv = all_inventory(env);
        atk = query_attacker();
        for( i=0; i<sizeof(inv); i++ ) {
                if( (string)inv[i]->query("name")=="Dead Spirit Knight" &&
inv[i]!=atk){
        //      && (!atk || member_array( inv[i], atk )==-1) ) {
                        tell_room( env,
                                inv[i]->query("c_name") +
"衝到拉斯面前，全力保護著拉斯！\n",
                                inv[i] );
                        inv[i]->force_me( "protect king" );
                        inv[i]->kill_ob(atk);
                }
        }
        return;
}

int my_tactic()
{
        int choice;
        object victim;

        if (!victim = query_attacker()) return 0;
        switch(choice=random(3) )
       {
        case 0 : return 0;
                 break;
        case 1 :
//地獄交響曲
        if ( random(20) < 16) return 0;
        tell_room(environment(victim),
"\n拉斯緩緩的將長笛拿到嘴邊，對著"+
(string)victim->query("c_name")+"吹奏出氣勢澎湃的地獄交響曲，一時
雷電交加，天地變色，彷佛地獄之門已為"+(string)victim->query("c_name")+"打開。\n"
,victim
        );
        tell_object(victim,@C_LONG

拉斯將長笛拿到嘴邊，似笑非笑，吹奏起悽絕的地獄交響曲！
～～～嗡～～嗚～～嗚嗚～～～～～嗡～～～～
音樂一起，霎時間天地變色，空氣凝結了！黑暗鬥氣隨著笛聲將你團團圍住！

你感覺到身上的皮肉開始脫離你的軀殼，而你只能不由自主的隨著笛音起舞，
腦中開始回憶起從小到大的所有美好回憶，你看見遠方有著飛翔在空中的精靈
在跟你招手，在更遠的前方似乎還有個拿著鐮刀的傢伙在冷笑著.......

C_LONG
    );
        victim->receive_special_damage( "evil", random(10)+30);
        return 1;
      break;
    case 2:
//死亡詩篇
        if ( random(20) < 17 ) return 0;
        tell_room(environment(victim),
"\n拉斯轉過身子，面對著"+
(string)victim->query("c_name")+"悠悠的念出一段長而優美的詩篇，只見"+
(string)victim->query("c_name")+"臉上露出笑容，身子不住的搖晃著！！\n"
        );
        tell_object(victim,@C_LONG

拉斯轉過身來面對著你，看著手中的詩集，對你喃喃吟頌著：
        若有那自稱高貴超凡，
                必被那善良純潔所恥；
        若有那自命惡貫滿盈，
        　　　　必受那邪靈奸佞所困。
        無知的欲求有靈的無限，
        　　在殞落的剎那，重生之門也為之開啟啊！

你邊聽著拉斯所吟唱的詩篇....一邊心有所感....不由得心中一陣
絞痛....慚愧不已....
C_LONG
    );
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack",
                "( 你心中充滿悔意，無法攻擊！ )\n" );
        victim->receive_special_damage( "devine", random(25)+40);
        return 1;
        break;
        default: return 0;
        break;
     }

}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/las",1);
        ::die();
        return;
}
