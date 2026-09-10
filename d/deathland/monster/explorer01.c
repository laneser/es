
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(13);
	set_name( "orc explorer Lawierda","半獸人探險家蘭耳達");
	add ("id", ({ "orc", "explorer","lawierda" }) );
	set_short("半獸人探險家蘭耳達");
	set_long(@DESC
半獸人探險家蘭耳達,一個喜愛冒險的半獸人,曾經旅行過很多地方.
這次他聽說莫拉德矮人國度的礦坑充滿著財富,所以趕來這裡尋寶.
DESC
    );
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "orc" );
    set( "unit", "個" );
	set_perm_stat( "str", 20 );
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon(26,10,23);
	set_natural_armor(57,17);
    set ("weight", 300);
    set ("chat_chance", 15);
    set("chat_output",({
        "這半獸人探險者揮動著他的拳頭,一副囂張的樣子.\n"
        }));
    set_skill("dagger",80);
    set_skill("dodge",100);
    set( "inquiry", ([
         "lucksis" : "@@ask_lucksis",
         ]) );
    wield_weapon(Weapon"/dagger02");     
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,@MSG1
蘭耳達說:我不知道為何你要提起她.
那是一段傷心的往事.我不想再提起
MSG1
                       );
     else
       {
         tell_object(who,@MSG2
蘭耳達說:你是拉克希絲派來的?
我想那已經是一段往事了.雖然當時我和她有一段快樂的時光,
但是現在的我只對冒險有興趣,你想想,前往未知的區域,到處
都是死亡和刺激,是多麼過癮的一件事啊!
蘭耳達轉頭繼續尋找這裡的秘密.


一個只會追求刺激的人對於別人的生死會在意嗎?
你想現在的蘭耳達與拉克希絲認識的蘭耳達已經截然不同了.
MSG2
                    );
         who->set_temp("lucksis_quest/lawierda",1);             
       }
     return;
}

void die()
{
	object killer;
	killer = query("last_attacker");
	killer->set_explore( "deathland#34" );
	::die();
}
