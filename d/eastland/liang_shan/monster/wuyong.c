#include "../takeda.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(16);
	set_name("Wu Yong", "吳用");
	add ("id", ({ "wu", "yong" }) );
	set_short( "吳用");
	set_long(
		"外號智多星，鄆城縣人，多才多智，有勇有謀，為梁山泊兼管機密軍\n"
		"師，又有賽諸葛之稱。你若在山寨內看到任何不平凡的事物，他都能\n" 
		"給你滿意的解答，他現在正在一張棋盤前看的目不轉睛。\n"
		);
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("int",30);
	set_skill( "parry", 50 );
	set_skill( "dodge", 80 );
	set( "max_hp", 460 );
	set( "hit_points", 460 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set_natural_armor( 80, 28 );
	set_natural_weapon( 35, 15, 40 );
	set("special_defense", ([ "all":40, "none":20 ]) );
	set("inquiry",([ "meat":"@@ask_meat" ]));
	               
	set("aim_difficulty",
			([ "vascular":45, "ganglion":60 ]) );
	set( "tactic_func", "my_tactic" );

	wield_weapon("/d/eastland/goomay/obj/iron_chain");
	equip_armor(TARMOR"scholar_hood");
        equip_armor(TARMOR"sun_book");
        equip_armor(TARMOR"jade_cloth");
        equip_armor(TARMOR"scholar_cape");
}

int my_tactic()
{
	object *atk;

	if( !(atk = query_attackers()) || random(20)<16) return 0;
	else {
	tell_room(environment(this_object()), 
	"吳用念道: 天羅神，地羅神，人離難，難離身，一切災難化為塵。\n"
	"一道光芒貫穿吳用的身體......\n",
	this_object());
	this_object()->receive_healing(90);
	return 1;
}
}
int ask_meat()
{
        if (!(this_player()->query_temp("fat_quest/ask")) || (int)this_player()->query_temp("fat_quest/ask")<2)
        write(
        "吳用很有禮貌的說道: 請別干擾我研究圍棋，好嗎?\n");
        else
        {
        write(
        "吳用聽完你的陳述後，稍微思考了一下，轉頭對你說道: \n"
        "我想關於經費的問題，我可能幫不上什麼忙，這幾年來，我們都很少出去\n"
        "做買賣，山寨支出完全靠商人營業稅，公營事業和以前存在錢莊裡的錢的\n"
        "利息來維持，大概是維持一個收支平衡的局面。若給肥東多餘的經費，就\n"
        "有人沒有經費了..........\n\n"
        "說完，吳用陷入了沉思\n\n");
        call_out("fish",15,this_player());
        }
        return 1;
}
int fish()
{        
        write(
        "吳用摸著鼻子喃喃自語: 肉? 肉? 那裡有便宜的肉呢?\n\n");
        call_out("fish1",5,this_player());
        return 1;
}
int fish1()
{
        write(
        "吳用緩緩的抬起頭，說道: 有一個辦法，應該可以解決肥東的麻煩。\n"
        "在我們山寨外面，有一個非常大的湖泊，裡面盛產各種魚蝦，如果能\n"
        "夠拿它們來作料理，應該是不錯的主意。你回去建議肥東，拿一些魚\n"
        "蝦來試試看，至於材料嘛，你去找水軍裡一個名叫張順的人，跟他說\n"
        "我叫他送一些魚蝦去給肥東作試驗，如果試驗可以的話以後就這樣辦\n"
        "吧。說完，吳用微笑著繼續看著棋盤。\n");
        this_player()->set_temp("fat_quest/fish",1);
        return 1;
       
}                