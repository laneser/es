#include <mudlib.h>

inherit MONSTER;

void init()
{
	::init();
		add_action( "tip_me", "pay");
        add_action( "ask_me", "ask");
}

int payed;
void create()
{
        ::create();
        set_level( 12 );
	set_name( "soothsayer", "有所不知" );
	add( "id", ({ "man" }) );
        set_short( "有所不知" );
        set_long(
@LONG
    他就是江湖上大名鼎鼎的「無所不知」，一身青衫的他乍看之下就像是
一個落拓的的老學究，只有從他那對微閉著的眼中偶而射出的精光才使你覺
得他的特異，傳說中他能夠知過去未來，但是他卻很少接受江湖人的委託卜
卦，不過，十年前和七年前他對武林大會結果的預測卻使人記憶深刻。
LONG
        );
        set( "gender", "male" );
	set("race","human");
	payed=0;
        set( "alignment", 300 );
        set_natural_armor( 70, 25 );
        set_natural_weapon( 21, 10, 20 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed",100);
        set_skill( "target",60);
        set_skill( "concentrate",60);
        set_skill( "black-magic",60);

        set( "tactic_func", "my_tactic" );
        set ("defense_type","dodge");
        set("spell_levels/black_magic",15);
        set( "spells/ether-bolt",2);
		set("spell_power",0);
        set( "max_sp",500);
        set( "spell_points",500);
        set( "hit_points", 450 );
        set( "max_hp", 450 );
        set( "special_defense", ([ "all": 30 ]) );
        set( "wealth/gold", 20 );
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
        if (mon_name!="soothsayer")
        {
                this_player()->command("ask "+str);
                return 0;
		}
        if (!payed) {
                write(
                "有所不知道：「付一次掛金才能問一個問題 !! 這是規矩 !! 」 \n" );
                return 1;
		}

switch (subject) {
        case "goddess" :
        tell_object(this_player(),
"有所不知點頭道：「女神？你是指月神吧 !! 月神是本鎮的守護神，數百年前\n"
"這裡曾經有一座月神神殿，那真是一幢壯麗美觀的宏偉建築，據說是月神用她\n"
"的神法一夜之間建成的，光是神殿的祭司就有數百人。後來，不知什麼原因，\n"
"神殿突然消失了，於是那些虔誠的祭司和信徒們就在這裡定居下來，他們就是\n"
"本鎮的開創者。」\n" );
                break;

        case "richman" :
        tell_object(this_player(),
	"有所不知道：「錢不多嘛 !! 他真是個奇特的人，誰也不知道他的來歷\n"
    "幾年前他突然兩手空空的帶著老婆來到本鎮，短短幾年之間他就大發特\n"
	"發起來，也不知道他是怎麼賺錢的，不過別以為他是個典型的暴發戶，\n"
	"我覺得他學問頂好，才情不少，而且常常有一些超乎常人的見解，算得\n"
	"上是個奇人。」\n" );
                break;
        case "blacksmith" :
        tell_object(this_player(),
        "有所不知道：「段鐵的劍爐是火妖作祟吧 !! 其實這真的也不能怪火妖\n"
	"，天地大道就是如此，火妖因火而生以火為食，當然不能說它錯，但是\n"
	"段家又以火為生，如此煩惱糾結，真不是殺戮能夠解決的，聽說萬年冰\n"
	"晶可以剋制火妖，不過我想內情並不那麼單純。段家的前幾代也曾經被\n"
	"火妖困擾，最後好像把它困在一個洞裡，你可以問問段家的人」\n" );
                break;
        default :
        write(
        "有所不知笑道：「 客官 ... 這種小事你認為很重要嗎？你去問路人說不定就可以知道\n"
	"何必要來問我？不過錢還是要照算的 !!\n" );
                break;
}
        payed = 0;
        return 1;
}

int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
        if( this_object()->query_temp("cast_busy") )
                return 0;
        if( (int)this_player()->query("spell_points") < 100 )
                set( "spell_points",500);
        command("cast ether-bolt at "+(string)victim->query("name"));
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
                        "無所不知說道: 客官 ! 對不起，老漢只收金幣。\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 10 ) {
	tell_room( environment(), 
                 "無所不知說道: 客官 ! 你想知道的秘密難道只值這些錢嗎？\n" ,
                        this_object() );
		return 1;
	}
        tell_room( environment(), 
                 "無所不知點點頭道: 客官 ! 你想要問些什麼？運勢還是流年？\n" ,
                        this_object() );
	payed=1;

	return 1;
}
