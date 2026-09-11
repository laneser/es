#include "../goomay.h"
inherit Mob_special;
int payed;
void init()
{
	::init();
	add_action( "tip_me", "pay");
        add_action( "ask_me", "ask");
}

void create()
{
        ::create();
        set_level( 5 );
        set_name( "the waiter", "店小二" );
        add( "id", ({ "waiter" }) );
        set_short( "店小二" );
        set_long(
@LONG
你看到一個十來歲的小夥子，戴著一頂青布小帽，笑容滿面的臉上長了幾顆
青春痘，一雙溜溜的大眼睛顯得十分靈動，他是本店的店小二，出了名的包
打聽，只要你能瞭解他的需要，他一定會滿足你的要求，當然，你也要先讓
他滿足才行。
LONG
        );
        set( "gender", "male" );
	set("race","halfling");
	payed=0;
        set_natural_armor( 25, 10 );
        set_natural_weapon( 6, 5, 11 );
        set_skill( "dodge", 80 );
        set_perm_stat("dex",10);
        set_perm_stat("str",10);
	set( "defense_type","dodge");
        set( "alignment", 150 );
        set( "wealth/silver", 20 );
        set("special_attack",(["damage_type" : "none","main_damage" : 5,
                                "random_dam" : 5 , "hit_rate" : 13]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"店小二用他的抹布望你身上抽來，拍的一聲重重的打在你身上，你感到一陣劇痛..\n\n");
set("c_room_msg","店小二用抹布抽打");
set("c_room_msg2", "把他打得暈頭轉向 ...\n");
}
void ask_scribe()
{
        tell_object(this_player(),
        "店小二道：「這些當官的人架子大得很，等閒是見不著的，但是如果你是\n他們的上司，那就另當別論嘍」\n" );
}
int ask_me(string str)
{
        string mon_name,subject;

        if (!str)
                return notify_fail(
                "要問非玩者人物問題，請用 \"ask <誰> about <關鍵字>\"。\n");

        if (sscanf(str, "%s about %s", mon_name, subject) != 2)
                return notify_fail(
                "要問非玩者人物問題，請用 \"ask <誰> about <關鍵字>\"。\n");
	if (mon_name!="waiter")
	{
		this_player()->command("ask "+str);
		return 0;
	}
        if (!payed) {
                write(
                "店小二笑道：「 客官 ... 總得意思意思吧 !! 瞭解嗎？」 \n" );
                return 1;
	}

switch (subject) {
        case "hunter" :
        tell_object(this_player(),
	"店小二道：「獵人阿三啊，這幾天沒見他拿野味出來賣啊，魚販子宋九跟他很熟，\n"
        "你可以找他問問 ..」\n" );
                break;

        case "herb" :
        tell_object(this_player(),
	"店小二道：「說到這個藥草啊，還不都是錢不多搞的鬼嗎？大概是世德堂的\n"
	"老醫生得罪他了，所以他打算不讓他做生意了，誰知道呢？不過這世上如果\n"
	"有誰能勸的了錢不多的，那一定非綠珠姑娘不可了。」\n" );

                break;
	case "maid" :
        tell_object(this_player(),
	"店小二道：「你是說小翠這兇丫頭嗎？勸你最好別去招惹她，不過她對綠珠姑娘\n"
        "真的非常忠心，嗯 ～～聽說她最近迷上了收集珍珠。」\n" );

		break;
        case "magistrate" :
			ask_scribe();
                break;
        case "captain" :
                        ask_scribe();
                break;
        case "scribe" :
                        ask_scribe();
                break;

        default : 
	write(
	"店小二笑道：「 客官 ... 雖然我不知道你想知道的事，可這也算一個問題啊」 \n" );
                break;
}
	payed = 0;
	return 1;
}

int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "付誰？多少錢？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
                tell_room( environment(), 
                        "小二哥說道: 客官 ! 對不起，今年好像流行金幣耶。\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 50 ) {
                tell_room( environment(), 
                 "小二哥說道: 客官 ! 小的一條賤命難道只值這些錢嗎？\n" ,
                        this_object() );
		return 1;
	}
	payed=1;
	tell_object(this_player(),
		    "店小二向你眨眨眼笑道：「那麼 ... 客官 !! 你想知道些什麼呢？」\n" );

	return 1;
}

