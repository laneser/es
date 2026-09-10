
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master Fan", "九城名捕－方傲天" );
        add ("id",({ "fan","master"}));
        set_short( "九城名捕－方傲天");
        set("unit","位");
        set_long(
@C_LONG
    他就是名聞天下的「飛鷹」方傲天，也就是當今皇上眼下最紅的一位
名捕，在他的手下，不知道破了多少奇案、斬了多少奸惡。聽說他一向在
皇帝面前當差，不知道為什麼現在在這裡出現，這應該不是偶然吧 !!
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
	set("alignment",1000);
        set_natural_armor( 90, 40 );
        set_natural_weapon( 10, 10, 23 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "shortblade", 100 );
        set_skill( "parry", 100 );
        set_skill( "block", 100 );
        set( "hit_points", 900 );
        set( "max_hp", 900 );
        set( "special_defense", ([ "all": 40 ]) );
        set( "wealth/gold", 100 );
        wield_weapon( Obj"icey_sword" );
        equip_armor( Obj"flame_shield" );
	
        set( "inquiry", ([
                "wine" : 
@WINE
「嗯 !! 本座一向久仰趙燕居的酒名，今天還特地來一試，
沒想到也沒什麼大不了的，跟京城的太白樓也相差不多，真是頗為失望，難道這裡真
的沒有好酒嗎？ ...」
WINE
]));

}
int accept_item(object me,object item)
{
     if ((string) item->query("name") !="old wine" ) return 1;
     tell_object(me,
@MISSION
方傲天拍開老酒的封泥，一陣酒香已經透了出來，他豎起拇指對你笑道：「好酒 !!」。
於是你們連桌共飲，談天說地不亦快哉 !! 喝到後來，他跟你談起此行的任務 ...
原來皇上獲得密報，誠王有意謀反，意圖在皇上觀賞武道大會之時派殺手刺殺他，
於是命方傲天前來查辦。方傲天已經派了一個得力助手賈老六先來了，可是一直沒
有消息，所以他自己趕來查探。
MISSION
	);
                item->remove();
	return 1 ;
}
