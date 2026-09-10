#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "shu ju", "掃地僧 虛竹" );
        add ("id", ({ "monk","shu","ju" }) );
        set_short( "掃地僧 虛竹");
        set("unit","位");
        set_long(@C_LONG
在少林寺眾多的高僧中，虛竹要算是最沒有名氣的了。他從年輕的時候就開始
負責藏經樓的打掃工作，平日甚少跟外界接觸，就連少林寺中知道他的也沒有
幾個人。但是多年來打掃藏經樓的結果，他幾乎讀遍所有的經書，所以如果你
要找人討論經書的話，他應該是最合適的人選了。
C_LONG
        );
        set("alignment",2000);
        set("wealth/silver",38);
        set("gender","male");
        set("race","human");
        set("chat_chance",10);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 400);
        set("force_points", 400);
        set("special_defense", ([ "all" : 45, "none" : 40 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50 ]) );
        set_perm_stat("str", 24);
        set_perm_stat("dex", 28);
        set_perm_stat("pie", 30);
        set_perm_stat("kar", 18);
        set_natural_weapon( 35, 20, 35 );
        set_natural_armor( 75, 20 );
        set_skill("dodge",100);
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
        set_skill("bo",100);
        set ("chat_output",({
        	"虛竹說道：最近藏經樓好像有小偷，掉了幾本經書(sutra)。\n"
        }));
        wield_weapon( SAULIN_OBJ"whisk" );
//	equip_armor( SAULIN_OBJ"boot2" );
//	equip_armor( SAULIN_OBJ"shield3" );
        equip_armor( SAULIN_OBJ"grey_pallium" );
        equip_armor( SAULIN_OBJ"ring3" );
        set("inquiry",(["sutra":
@C_LONG
最近寺中清點經書的時候發現掉了幾本，大部分都不是很重要的
經書，可是其中有一本愣加經似乎方丈特別重視，要求我們一定要找回來，可
是這本經書對我們研究佛經的人來說並不是很重要，實在有點奇怪。不過既然
是方丈的意思，我們只有照著做。
C_LONG
]));

}

