
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "Pawnbroker", "劉朝奉" );
        add ("id",({ "liu"}));
        set_short( "劉朝奉");
        set("unit","位");
        set_long(
@C_LONG
    他是一個戴著一隻玻璃鏡片的老朝奉，一身藍天長袍加上瓜皮小帽，
一看就覺得他是個十分謹慎的人，別看他老，他可是京城最有名的三大
朝奉之一，商業界響噹噹的第一買賣高手，這次是專門受錢不多重金禮
聘來管理他在古梅鎮的各家行號的。或許你可以向他請教有關於商店的
種種。
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
	set( "alignment",300);
        set_natural_armor( 50, 20 );
        set_natural_weapon( -10, 1, 3 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "kar", 12 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "blunt", 80 );
        set_skill( "parry", 60 );
        set( "hit_points", 280 );
        set( "max_hp", 280 );
        set( "special_defense", ([ "all": 20 ]) );
	set("wealth/gold",20);
        wield_weapon( Obj"abacus" );
        equip_armor( Obj"long_garb" );
        equip_armor( Obj"round_cap" );
        equip_armor( Obj"emerald_ring" );
        set( "inquiry", ([
		"statue"  : "@@ask_statue",
        ]) );

}

int ask_statue()
{
        object me ;
        me=this_player();
       if ((int)this_player()->query_quest_level("Goddess_statue")>2 ) {
                tell_object(me,
                "劉掌櫃笑道：「月神像已經找回來了，多謝您的幫忙 !!」\n");
                return 1;
	}
        else
        {
	tell_object(me,@C_STATUE
劉掌櫃嘆道：「那月神像是月神教的精神象徵，據說隱藏有強大的力量，一向
為該教的鎮教之寶，半個月前我回京城辦事，回到店裡，夥計們居然收了這麼
一個燙手山芋，結果當天晚上就有人夜闖庫房，單單只偷走了這尊神像，嚇得
我六神無主，果然幾天以後，月神教的人紛紛找到我頭上，威脅利誘、要殺要
剮的，可是我哪裡有辦法？後來聽說那賊被抓了，我趕緊到衙門疏通，結果也
沒有神像的下落，最後那賊居然越獄了 ... 我 ... 我乾脆死了算了」
C_STATUE
	);
                return 1;
	}
}

int accept_item(object me,object item)
{
     if ( ((string) item->query("name") !="The statue of Goddess" &&
	 (string) item->query("name") !="broken symbol") ||
       (int)this_player()->query_quest_level("Goddess_statue")>2 ) {

     tell_object(me,
        "劉掌櫃道：「謝謝 !! 但是我是個誠實的生意人，不能亂收你的東西。 」\n");
	command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}

	if ( (string)item->query("name") == "broken symbol" ) {
     tell_object(me,@SYMBOL
劉掌櫃道：嗯 !! 這東西看起來似乎很不平凡，你何不請高手匠人幫你修修。 
或許能恢復舊觀也說不定，劍盧主人段鐵應該有這份功力吧 !!
SYMBOL
		 );
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
@MISSION
劉掌櫃把月神像翻來覆去的看了一遍：「這 .. 這是真的月神像 !! 謝謝你 !! 我有
救了 !! 我有救了 !! 」他高高興興的把女神像秘密的收藏起來，打開庫房，準備恢
復營業。

MISSION
);
	if (item->query("who_get_me") == this_player()->query("name")) {
	tell_object(me,
	"你終於完成了尋找月神像的任務 !! "+set_color("[ 你得到 15000 點經驗 ]","HIC")+"\n" );
	me->finish_quest("Goddess_statue",3);
        me->gain_experience(15000);
	}

        item->remove();

        return 1;
}
