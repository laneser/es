
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(4);
        set_name( "servant", "皮條" );
        set_short( "皮條");
        set("unit","位");
        set_long(
@C_LONG
你看到一個猥瑣的漢子，他約莫三四十來歲，可是看起來卻更老，
營養不良的臉上還留著縱慾過度的痕跡，一雙水泡眼卻盯著每個過往
的人，看到那些比較老實或是有點意思的遊客就上前一陣亂扯，口裡
還嘟囔著好些不三不四的話，當真恬不知恥。
C_LONG
);
        set("alignment",-350);
		set("wu_appear",0);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",8);
        set_perm_stat("kar",6); 
        set_natural_weapon(5,4,9);
        set ("natural_armor_class", 25);
        set_skill("dodge",45);
		set( "defense_type","dodge");
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "human");
        set_c_verbs(({"%s用雙手向%s亂抓",
                      "%s用腳向%s亂踢",
                      "%s用頭向%s撞去"}));
       
        set( "inquiry", ([
                "wu" : "@@ask_wu"]));
	
}
int appear_wu(object who)
{
	object ob;
	tell_room( environment(), 
	"一個提著一隻大茶壺的矮小漢子，一晃一晃的走了過來 ...\n" ,
	who );
        new(Mob"servant_wu" )->move( environment() );
	return 1;
}
int ask_wu()
{
if ( query("wu_appear") ) {
tell_object(this_player(),
@C_WUA
那皮條的一對眼睛很無禮的上下打量你，他邪邪的笑道：「別猴急嘛 !! 
已經幫你叫了，吶～～那不是來了嗎？嘻嘻嘻嘻 ～～～
C_WUA
);
return 1;
}

tell_object(this_player(),
@C_WU
那皮條的一對眼睛很無禮的上下打量你，他邪邪的笑道：「來到怡紅院不找
姑娘，卻要找一個提大茶壺的王八，嘿嘿 !! 」接著他提起嗓子用他職業性
的大嗓門大喊：「王八老吳 ～～　見客啦 ～～」所有人都轟然大笑。
C_WU
);
	set("wu_appear",1);
        call_out("appear_wu", 5,this_object());
        return 1;
}
