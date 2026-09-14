//#pragma save_binary
// _meditate.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
	"一團朦朧的光霧，環繞著一個發著紅光的球體，旋轉著....。\n",
	"兩股穿梭交叉的火柱，在天空中互相追逐，它們所掉落的火焰將地面燃成\n"
	"火海....。\n",
	"淡紫色的雲彩中，許多亮晶晶的透明水晶球懸浮著，遠方傳來陣陣的樂聲....。\n",
	"一群穿著黑色袍子的巨人，無聲無息地穿過山中的一個峽谷，兩旁躺滿了\n"
	"動物的屍體與枯黃的植物....。\n",
	"水中有一個巨大的黑影敏捷地遊動著，空中映在水面的一隻大鳥的影子，\n"
	"正緊緊地追逐著水中的龐然大物....。\n",
	"兩個相貌完全一樣的俊美少年正在爭吵，他們手中各拿著一個金光閃閃的\n"
	"水瓶，水花濺得陽光下一片珍珠般的霧氣....。\n",
	"從一片烏黑黏稠的泥漿中升起一個個的泡沫，每個泡沫一破裂，就有一張\n"
	"猙獰可怖的臉飛出來....。\n",
	"森林中許多藍色的蝴蝶在飛舞著，然後一隻燃著熊熊火焰的獨角獸衝入蝴\n"
	"蝶群中....。\n",
	"兩個身穿紅衣的騎士在一片躺滿死屍的高地上決鬥，一名戴著面具的少女在\n"
	"一旁沈默地看著 ....。\n",
	"成千上萬的士兵如痴如醉地狂喊著「殺呀！殺呀！」，一個被士兵包圍著的\n"
	"白衣胖子臉上用不屑的眼神瞪視著這些瘋狂的士兵。\n",
	"一隻巨大的藍色火龍正側著頭，傾聽著一旁兩名精靈少年吹奏著的長笛。\n",
	"黑夜中許多紅色的身影無聲無息地向一座聳立在懸崖上的城堡飄去，天空\n"
	"中正飄著細雨 .....。\n"
});

void do_meditate( object player, int skill, int degree )
{
	int mana, max, g_lvl;

	tell_object( player, "你看到....");
	g_lvl = (int)player->query_guild_level();
	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		(skill+g_lvl) > random(degree*degree*2) ) {
		message( "illusion", 
			c_illusion[random(sizeof(c_illusion))]
			, player
		);
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->receive_damage(3-(g_lvl/30));
		if( mana + degree * (3+g_lvl/30) > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * (3+g_lvl/30) );
		call_out( "do_meditate", 3, player, skill, degree + 1 );
	} else {
	    player->set_temp("meditating", 0);
	    if( !wizardp( player ) ) {
	      player->set_temp("block_defense",0);
		  player->set_temp("block_command",0);
		  player->set_temp("block_message",0);
	    }
		tell_object( player, "一片漆黑，什麼也沒有的空間....。\n");
		tell_object( player, "然後周圍的聲音、景象逐漸由虛幻而具體，你從冥思中醒了過來。\n");
		tell_room( environment(player), 
			player->query("c_name")+ "睜開眼睛，看了看四周，站了起來。\n",
			player );
		player->gain_guild_experience(1+skill/10);
	    call_out( "quit_meditate", degree*12, player );
	    player->set("next_meditate", (int)player->query("age") + degree*12 );
	}
}

void quit_meditate( object player )
{
    tell_object( player, "你覺得精神又能集中了。\n" );
}

int cmd_meditate()
{
	int med_skill, hp;

	med_skill = (int)this_player()->query_skill("meditate");
	if( !med_skill ) return notify_fail( "你沒有學過冥思的方法，可能會在冥思過程中迷失....。\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( "你現在受傷過於沈重，無法冥思....。\n" );
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_meditate" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("你需要一段時間休息，才能再集中精神冥思....。\n" );
	write( "你席地坐了下來，集中精神，開始冥思....。\n");
	tell_room( environment(this_player()),
		this_player()->query("c_name")+ "席地而坐，閉上眼睛，開始冥思....。\n",
		this_player() );
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
      this_player()->set_temp("block_defense", 1 );
   	  this_player()->set_temp("block_command", 1 );
	  this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_meditate", 3, this_player(), med_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax: meditate

This command is to sit down and meditate. When you are meditating, spell
points recovery is much faster than usual. How long you can meditate depends
on your meditate skill. Once you are awake from meditating, you'll have have
some headache. But that's normal.
HELP
	);
    return 1;
}
