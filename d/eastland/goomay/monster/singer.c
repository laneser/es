#include "../goomay.h"
#include <stats.h>

inherit Mob_special;
int *c_length = ({ 0,4,8,16,20 });

string *c_song = ({
"燎沈香，消溽暑。鳥雀呼晴，侵曉窺簷語。 \n",
"葉上初陽乾宿雨，水面清圓，一一風荷舉。 \n",
"故鄉遠，何日去？家住吳門，久作長安旅。 \n",
"五月魚郎相憶否？小楫輕舟，夢入芙蓉浦。 \n",
"尊前擬把歸期說，未語春容先慘咽。 \n",
"人生自是有情痴，此恨不關風與月。 \n",
"離歌且莫翻新闋，一曲能教腸寸結。 \n",
"直須看盡洛城花，始共春風容易別。 \n",
"洞庭青草、近中秋，更無一點風色。 \n",
"玉界瓊田三萬頃，著我扁舟一片。 \n",
"素月分輝，明河共影，表裡俱澄澈。 \n",
"悠然心會，妙處難與君說。 \n",
"應念嶺表經年，孤光自照，肝肺皆冰雪。 \n",
"短髮蕭騷襟袖冷，穩泛滄溟空闊。\n",
"盡挹西江，細斟北斗，萬象為賓客。\n",
"扣舷獨笑，不知今夕何夕。\n",
"驛外斷橋邊，寂寞開無主。\n",
"已是黃昏獨自愁，更著風和雨。\n",
"無意苦爭春，一任群芳妒。\n",
"零落成泥碾作塵，只有香如故。\n",

});


void create()
{
	::create();
	set_level(6);
        set_name( "singing girl", "賣唱少女" );
        add( "id", ({ "girl" }) );
        set_short("賣唱少女" );
        set_long(
@LONG
她是一個三分靦腆中透著十分清麗的女孩，雖然身上的衣服已經破舊了，
可是還是洗的很乾淨。她抱著一把琵琶，眼睛望著地上，在潮來潮往的人海
裡，顯得無限寂寞孤單。或許你可以駐足休息一下，只要付(pay)她十塊金幣
，你就能在欣賞美妙歌曲的同時又幫助一個落難的少女。
LONG
        );
        set( "gender", "female" );
	set( "race", "human" );
	set_natural_weapon( 7, 6, 14 );
	set_natural_armor( 35, 12 );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 12 );
	set_skill( "dodge", 60 );
	set("defense_type","dodge");
	set( "wealth/gold", 1 );
        set_natural_weapon( 20, 6, 16 );
        set_natural_armor( 30, 10 );
        set_c_verbs(({"%s用指甲抓向%s","%s用琵琶砸向%s","%s用腳踹向%s"}));
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "賣唱少女用她的琵琶往你的身體砸來..\n\n");
set("c_room_msg","賣唱少女的用她的琵琶掃過");
set("c_room_msg2", "的身體，把他打得腳步踉蹌 ...\n");
}

void init()
{
	::init();
	add_action( "do_fortell", "pay");
}
void sing(int i,int j)
{
 tell_room(environment(),c_song[i] ,this_object());
 i++;
if (i<j)
 call_out("sing",3,i,j);
 else
 tell_room(environment(),
   "\n琵琶聲漸漸低沈不可聞～～\n"
   "賣唱少女微微一福，低聲道：多謝各位大爺 !!\n",this_object());
 return;
}

int do_fortell(string arg)
{
	string who, type, race;
	int num, age,song_no=0;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
		return notify_fail( 
			"付誰？多少錢？\n" );
	if( !id(who ) ) return 0;
	if( type != "gold" ) {
		tell_room( environment(), 
			"賣唱少女說道: 對不起，客官 ! 我只收金幣。\n" ,
			this_object() );
		return 1;
	}
if( !this_player()->debit(type, num) ) return notify_fail(
	"客官 ! 請你不要欺負一個可憐的女孩好嗎？你明明沒有那麼多金幣 !\n");
	if( num < 10 ) {
		write(
			"賣唱少女向你靦腆一笑，搖一搖頭，把錢退還給你。\n");
		this_player()->credit(type, num);
		return 1;
	}
	if ( num >=10){
        tell_room( environment(),
		"賣唱少女向在場眾人一福，低聲道：獻醜了。\n"
		"說畢，玎玎地撥了兩聲琵琶，曼聲唱道：\n\n",this_object());
	song_no=random(4);
	call_out("sing",2,c_length[song_no],c_length[song_no+1]);

	return 1;
	}
}

