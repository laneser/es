//#pragma save_binary
// _brood.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
// modified by Oldcat@Eastern.Stories (1-18-95)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
        "神將八卦分八節，一氣統三為正宗。\n",
        "陰陽二遁分順逆，一氣三元人莫測。\n",
        "五日都來換一元，接氣超神為準的。\n",
        "認取九宮為九星，八門又遂九星行。\n",
        "九宮逢甲為直符，八門直使自分明。\n",
        "符上之門為直使，十時一位堪憑據。\n",
        "直符常遣加時幹，直使逆順遁宮去。\n",
        "六甲元號六儀名，三奇即是乙丙丁。\n",
        "陽遁順儀奇逆布，陰遁逆儀奇順行。\n",
        "吉門偶爾合三奇，直此雖雲百事宜。\n",
        "更合從傍加簡點，餘宮不可有微疵。\n",
        "三奇得使誠堪取，六甲遇之非小補。\n",
        "乙逢犬馬丙鼠猴，六丁玉女騎龍虎。\n",
        "又有三奇遊六儀，號為玉女守門扉。\n",
        "若作陰私和合事，請君但向此中推。\n",
        "天三門兮四地戶，問君此法如何處。\n",
        "太沖小吉與從魁，此是天門私出路。\n",
	"地戶除危定與開，舉事皆從此中去。\n",
        "六合太陰太常君，三辰元是地私門。\n",
        "更得奇門相照耀，出門百事總欣欣。\n",
        "太沖天馬最為貴，卒然有準宜迴避。\n",
        "但當乘取天馬行，劍戟如山不足畏。\n",
        "三為生氣五為死，勝在三難難逃五。\n"
});

void do_brood( object player, int skill, int degree )
{
	int mana, max;

	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		skill > random(degree*degree*2) ) {
		message( "illusion", 
                        "你默想...."+c_illusion[random(23)],player );
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->add("hit_points",-3);
		if( mana + degree * 3 > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * 3 );
		call_out( "do_brood", 3, player, skill, degree + 1 );
	} else {
	    player->delete_temp("meditating");
		player->delete_temp("block_defense");
		player->delete_temp("block_command");
//		player->delete_temp("block_message");
		tell_object( player,"突然你覺得腦中一片空白....。\n");
		tell_object( player,"然後周圍的聲音、景象逐漸由虛幻而具體，你從打坐中醒了過來。\n");
		tell_room( environment(player), 
			player->query("c_name")+ "睜開眼睛，看了看四周，站了起來。\n",
			player );
	    call_out( "quit_brood", degree*12, player );
	    player->set("next_brood", (int)player->query("age") + degree*12 );
	}
}

void quit_brood( object player )
{
    tell_object( player,set_color("你覺得精神又能集中了。\n","HIY") );
}

int cmd_brood()
{
	int brood_skill, hp;

	brood_skill = (int)this_player()->query_skill("brood");
	if( !brood_skill ) return notify_fail( 
		"你沒有學過打坐的方法，可能會在打坐過程中迷失....。\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( 
		"你現在受傷過於沈重，無法打坐....。\n");
        if( this_player()->query_temp("exercising") ) return notify_fail("你正在聚丹，無法打坐...。\n");
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_brood" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("你需要一段時間休息，才能再集中精神打坐....。\n");
	write("你席地坐了下來，集中精神，開始打坐....。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+ "席地而坐，閉上眼睛，開始打坐....。\n",
		this_player() );
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
 		this_player()->set_temp("block_defense", 1 );
 		this_player()->set_temp("block_command", 1 );
// 		this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_brood", 3, this_player(), brood_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
指令格式： brood

這個指令使你坐下開始打坐，當你打坐的時候你的精神力(sp)會恢復的比平常快，
你打坐時間的長短是依據你的技能高低來判斷，當你從打坐中醒來後會有一段時間
沒有辦法再打坐。
HELP
	);
    return 1;
}
