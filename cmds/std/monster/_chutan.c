
#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({
"一股真氣由你的氣海穴流出, 緩緩的流向背部的陽堂穴...\n",
"一縷細微的真氣經由督脈流向足三履穴, 卻似忽遇到了阻礙而無法向前催動...\n",
"它強任它強, 清風過山崗... 我自一口真氣足 千苦萬苦也不苦... \n",
"........\n" 
});
void do_chutan( object player, int skill, int degree )
{
	int mana, max, dex, parry, block, dodge,level;

    tell_object( player, can_read_chinese(player)?
		"你感到...": "You see" );
	level =(int)player->query_level();
        if( degree < 10 && skill > random(degree * degree * 2+level) 
	&& (int)player->query("hit_points") > 20 ) {
		
                message("illusion", can_read_chinese(player)?
                        c_illusion[random(sizeof(c_illusion))]:
                        "you see some colorful illusions. \n", player);

                mana = (int)player->query("force_points");
		max = (int)player->query("max_fp");
		player->receive_damage(5);
		if( mana + degree * 3 > max )
			player->set("force_points", max );
		else
   		   player->set("force_points", mana + degree * 3 );
 		   call_out( "do_chutan", 3, player, skill, degree + 1 );
	} else {
	    player->set_temp("chutan", 0 );
	    if( !wizardp( player ) ) {
		  player->set_temp("block_command",0);
		  player->set_temp("block_message",0);
		  dex = player->query_perm_stat("dex");
	      parry = player->query_perm_skill("parry");
	      block = player->query_perm_skill("block");
	      dodge = player->query_perm_skill("dodge");
	      player->modify_stat("dex", dex);
	      player->modify_skill("parry", parry);
	      player->modify_skill("block", block);
	      player->modify_skill("dodge", dodge);
	    }
		  tell_object( player, "... 周遭的空氣在流動著... 你體內的真氣也不再聚集了...... \n");
		tell_object( player, 
	"你從清明之境返回這個紛擾的世界，你的運功結束了。\n");
		tell_room( environment(player), 
			player->query("c_name")+ "神清氣爽地站了起來。\n",
			player );
	    call_out( "quit_chutan", degree*20, player );
	}
}

void quit_chutan( object player )
{
    player->set_temp( "layuter_chutan", 0 );
    tell_object( player, 
"你覺得丹田熱烘烘的，一股內力從中湧出... 你又能運功聚氣了。\n" );
}

int cmd_chutan()
{
	int chu_skill, hp, dex, parry, block, dodge;

	chu_skill = (int)this_player()->query_skill("chutan");
	if( !chu_skill ) return notify_fail( "你沒有學過聚丹功，你不能使用它來聚集內力....。\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <35 ) return notify_fail( "你現在受傷過於嚴重，無法運功.。\n" );
    if( this_player()->query_temp( "layuter_chutan" ) )
      return notify_fail( "你需要一段時間休息，才能有足夠真氣運功..。\n");
	write( 
"你坐了下來, 默頌內功心法, 將精神運至空靈之境... 你開始運功聚氣使真氣運行全身。\n");
	tell_room( environment(this_player()), 
	this_player()->query("c_name")+ "盤腿而坐，開始運功聚氣...。\n",
		this_player() );
	this_player()->set_temp("chutan", 1 );
	this_player()->set_temp("layuter_chutan", 1 );
    if( !wizardp( this_player() ) ) {
	  this_player()->set_temp("block_command", 1 );
	  this_player()->set_temp("block_message", 1 );
	  dex = (int)this_player()->query_perm_stat("dex");
	  parry = (int)this_player()->query_perm_skill("parry");
	  block = (int)this_player()->query_perm_skill("block");
	  dodge = (int)this_player()->query_perm_skill("dodge");
	  this_player()->modify_stat("dex", -dex);
	  this_player()->modify_skill("parry", -parry);
	  this_player()->modify_skill("block", -block);
	  this_player()->modify_skill("dodge", -dodge);
	}
	call_out( "do_chutan", 2, this_player(), chu_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax: chutan

This command is to sit down and chutan. When you are chutaning, inner_force
points will recovery . How long you can chutan dependson your chutan skill.
Once you are awake from chutan, you'll have have some headache. But that's 
normal.
HELP
	);
    return 1;
}
