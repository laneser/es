#include "../goomay.h"

inherit MONSTER;

int is_iced = 0;

void create()
{
	::create();
	set_level(13);

        set_name( "@@query_short", "@@query_c_chort" );
        add( "id", ({ "beast","spirit" }) );
        set_short( "@@query_c_short" );
        set_long( "@@query_c_long");

	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set( "alignment", 500 );
	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 20 );
	set( "natural_weapon_class1", 32 );
	set( "natural_min_damage1", 12 );
	set( "natural_max_damage1", 23 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"火妖怒吼道：「可惡 !! 你們製造了我，卻又要殺我 !!」 \n",
		"火妖怒吼道：「讓你嚐嚐我火焰的厲害 !! 」\n"
	}) );


}
string query_short()
{
	if ( !this_player() ) return "fire beast";
 if (this_player()->query_temp("fire_element"))
	return "fire spirit";
	return "fire beast";
}
string query_c_short()
{
	if ( !this_player() ) return "火妖" ;
 if (this_player()->query_temp("fire_element"))
        return "火精靈";
        return "火妖";
}

string query_c_long()
{
	if ( ! this_player()) return "";
 if (this_player()->query_temp("fire_element"))
    return "這隻火精靈有著火紅色的眼珠和頭髮，它的額頭上有一個火焰的印記，當\n"
              "你的視線接觸到他的眼睛時，它笑的很開心。\n";

return "這隻火妖有著火紅色的眼珠和頭髮，它的額頭上有一個火焰的印記，當\n"
	"你的視線接觸到他的眼睛時，發覺它比你想像的平和。\n";
}

int accept_item(object me,object item)
{
object ob,ob2;
     if ((string) item->query("name") !="crystal of ice" ) return 1;
     if (this_player()->query_temp("fire_element")) return 1;
     tell_object(me,
@MISSION
火妖呆呆的接過萬年冰晶，臉上突然湧起一陣激動的笑容，它驚訝又
懷疑的看著你，在你始終如一的笑容下，兩行淚水滑過它火紅的面頰
，它用顫抖的聲音說道：「這世上從沒有人瞭解過我們，我們不是邪
惡種族，在極端的環境下出生的我們需要的只是適切的關懷和滿足，
這個冰晶正可以使我們脫去火性，轉變成擁有平衡生命的妖精，謝謝
你的付出和了解，再見了 !! 我的朋友 !! 希望有一天還能再見到你」

火妖把冰晶放在它的胸口，突然強烈光華四射，你聽到「答」的一聲
輕響，好像有什麼東西落在地上，你睜開雙眼一看，火妖已經不見蹤
影了。
你的耳邊響起一陣若有若無的聲音一直重複著：西邊.. 西邊 ..
MISSION
         );

                item->remove();
                ob = new( Obj"fire_element" );
                ob->move( environment(this_object()) );

		this_player()->set_temp("fire_element",1);
                if ((string)this_player()->query("class")=="scholar") {
                   tell_object(this_player(),"火精靈的聲音回湯在你耳邊：需要幫忙的時後請CALL我，不要忘記我喔 !\n");
                   this_player()->set("demand/fire",2);
                }
                remove();
        return 1;
}

void report( object attacker, object victim )
{
   string c_message;
   seteuid(getuid());
   c_message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( 你"+c_message+" )\n");
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	spec=random(100);
	if (spec <20 && (victim = query_attackers()))
	{
	tell_room( environment(this_object()), 
		"\n火妖伸出一道火焰，掃過你的身體，你感到一陣灼燙 !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "fire", 20+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}
	else if ( spec>20 && spec<50 && (victim = query_attackers()) ) 
	{
        tell_room( environment(this_object()), 
                "\n火妖散發出強烈的光芒，你的眼睛一陣刺痛 !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	{
        ob = present("glasses", victim[i]);
        if(ob && ob->query("equipped"))
	{
	tell_object( victim[i], 
		"你的墨鏡擋住了刺眼的強光。\n\n");
	}
	else
	{
        if( victim[i]->query("stop_attack") ) continue;
        victim[i]->block_attack(8);
        victim[i]->set_temp("msg_stop_attack", 
          "( 你現在什麼也看不到 ! )\n" );
	}
	}
	return 1;
	}
	return 0;
}

void iced()
{
	is_iced = 1;
	tell_room( environment(this_object()), 
	"火妖大聲尖叫：「 該死的傢伙 ! 把那個東西拿開 !」\n" ,
		this_object() );
}

void die()
{
	object ob;
	if( is_iced )
	{
		::die();
	}
	else {
		tell_room( environment(this_object()), 
			"火妖大叫一聲，碎裂成許多小火球 ....\n\n"
			"你聽到一陣低沈的聲音從火球中發出: 「你以為這樣就結束了嗎？」\n\n"
			"小火球又重新聚在一起，火妖又從火中重生。\n\n" ,
			this_object() );
		set( "exp_reward", 1 );
		set( "alt_corpse", Mob"fire_beast" );
		::die(1);
	}
}
