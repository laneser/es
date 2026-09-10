
#include "../goomay.h"

inherit MONSTER;

void create()
{
        object ob1,ob2;
        ::create();
        set_level(15);
        set_name( "guard of mine", "礦坑守衛" );
        add ("id", ({"guard",}) );
        set_short( "礦坑守衛" );
        set_long(
        "他是一個長的十分雄壯威武的礦坑守衛，負責守衛礦坑和保護礦工的安全\n"
        "，此刻他正上下地打量著你，並且用眼神警告你不要靠得太近。\n"
        );
	set("alignment",400);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "unit", "個" );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "str", 23 );
        set_perm_stat( "int", 17 );
        set_perm_stat( "con", 20 );
        set_perm_stat( "piety", 15);
        set_perm_stat( "karma", 17);
        set_skill("thrusting",70);
        set_skill("parry",70);
        set ("max_hp", 470);
        set ("hit_points", 470);
        set ("wealth", ([ "gold": 10 ]) );
        set_natural_weapon(19,10,25);
        set_natural_armor(35,15);
	set ("weight", 400);
	wield_weapon(Obj"iron_spear");
        equip_armor(Obj"iron_plate");


        set( "inquiry", ([
                "小四" : "@@ask_forsy",
		"forsy" : "@@ask_forsy"]));

}

int appear_forsy(object who)
{
        object ob;

	ob = new( "/d/eastland/goomay/monster/forsy" );
	if( environment(this_object())->query("forsy_appear")!=1 )
	return 0;
        tell_room( environment(), 
	"你聽到一陣軸轤的轉動聲，一輛臺車慢慢的從礦坑深處升起來\n"
        "一個扛著一把十字鎬的年輕漢子，推著一車鐵砂走了出來 ...\n" ,
	this_object() );
	ob->move(environment(this_object()));
	environment(this_object())->set("forsy_appear",2);
        return 1;
}

int ask_forsy()
{
        if( (int)this_player()->query_quest_level("Goddess_statue") != 1 ){
                tell_object(this_player(),
			"守衛很不耐煩地道：「小四？你找小四做啥？」\n" );
                return 1;
		}
        if ( this_player()->query_temp("get_paper") ) {
        tell_object(this_player(),
        "守衛很不耐煩地道：「你不是已經見過他了嗎？」\n" );
        return 1;
        }
	
	if ( environment(this_object())->query("forsy_appear")==1  ) {
		tell_object(this_player(),
			"守衛很不耐煩地道：「急什麼 !! 已經幫你叫了，吶～～那不是來了嗎？」\n" );
		return 1;
	}
	
	if ( environment(this_object())->query("forsy_appear")==2  ) {
		tell_object(this_player(),
			"守衛很不耐煩地道:「小四小四, 怎麼成天淨有人要找小四? 他現在不在啦!」\n");
		return 1;
	}
		
tell_object(this_player(),
@C_WU
那守衛的一對眼睛很嚴肅地上下打量你，他一本正經地道：「阿三
病了？好 !! 我馬上找小四來，你當面跟他說，請稍候 !!」

那守衛反手拉了身後的一條繩子，一陣輕脆的鈴聲從左邊的礦坑口
遠遠傳來。
C_WU
		);
        environment(this_object())->set("forsy_appear",1);
        call_out("appear_forsy", 5,this_object());
        return 1;
}

