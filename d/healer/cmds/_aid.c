////#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int cmd_aid(string arg)
{
	object dest;
	int hp, max_hp, skill ;
        string target,target1,myname ;

        if( this_player()->query("stop_attack")!=0) 
             return notify_fail( "你的上個動作還沒完成,無法施行急救。\n" );

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "你要對誰施行急救？\n" );

	if( !living(dest) ) 
		return notify_fail( "那個「東西」不需要急救。\n" );
        
        target  = dest->query("c_name") ;
        target1 = dest->query("c_name") ;
        
	if( dest->query("ghost") ) return notify_fail( 
		sprintf("太遲了 .... %s已經死了。\n",target ) );
	if( dest->query("no_aid") ) return notify_fail(
	        dest->query("c_name") +
	        "笑著對你說:謝謝你的好意, 不過我想有必要時, 我自己動手可能比較好。\n"
	);	
        if( dest->query_current_attacker()!=0) 
             return notify_fail( "你的目標正在戰鬥中,你無法對他急救。\n" );

	hp = (int)dest->query( "hit_points" );
	max_hp = (int)dest->query( "max_hp" );

//   傷太重則不能對自己急救...

	if( dest==this_player()&& hp < max_hp/6 ) 
               return notify_fail( "你傷勢太重而無法對自己施行急救。\n" );        

        if(dest == this_player())
           {
               target = "自己" ;
               target1 = "你自己" ;
            }                    

	if( hp==max_hp ) return notify_fail( 
		sprintf( "%s並沒有受傷。\n",target1 ) );

	if( dest->query_temp("aided") ) return notify_fail( 
		sprintf( "%s已經被急救過了。\n",target1 ) );

	if( hp > max_hp/3 ) return notify_fail(
		sprintf("%s的傷勢還沒有嚴重到需要急救的地步。\n",target1) );

	skill = (int)this_player()->query_skill( "first-aid");
	if( !skill ) return notify_fail( 
		"你並沒有學過急救的技能。\n");


	write(sprintf("你對%s進行急救 ....\n",target1) );

        myname = this_player()->query("c_name") ;
        
        if(dest != this_player())
     	    tell_object( dest, 
		sprintf("%s對你進行急救 .... 你覺得好多了！\n",myname ) );

	tell_room( environment(this_player()), 
		sprintf("%s對%s進行急救 ....\n",myname,target),
		({ this_player(), dest }) );
		
	if( dest!=this_player() ) this_player()->add( "alignment", 25 );
	dest->receive_healing( skill/2 + random(skill/2) );

 //    急救對玩家最多只能加到一半的 HP
	hp = (int)dest->query( "hit_points" );
        if( !wizardp(this_player()) && hp > max_hp/2 ) 
           dest->set("hit_points",max_hp/2) ;

	dest->set_temp( "aided", 1 );
	this_player()->receive_experience( skill );
	call_out( "remove_aided", 300, dest );
    return 1;
}

void remove_aided(object player)
{
	if( player ) player->set_temp("aided", 0);
}

int help()
{
    write(
    @C_HELP
指令格式: aid <某人>

這個指令讓你對某個人物( 或 NPC )施行急救，有關急救的細節與限制請參
考 help first-aid。
C_HELP
	);
    return 1;
}
