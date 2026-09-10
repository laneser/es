//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int help();
/*
int cmd_eujian(string str)
{
	object me,weapon;
	mapping where;
	int i;
	string msg,dest,*node_name,first,second,n,d;
	
	me = this_player();
	weapon = (object)me->query("weapon1");
	
        if ( !str ) return help();
        
        if ( !weapon || (string)weapon->query("type") != "longblade" ) 
        	return notify_fail( "你沒有適當的武器耶 !!\n" );
        
        if ( me->query_attackers() )
        	return notify_fail( "喂 !! 你還在戰鬥中耶，想被打下來嗎 ??\n" );
        	
        if ( me->query("gonfu_busy") || me->query_temp("gonfu_busy") ) 
        	return notify_fail( "你正在使用其他功夫，所以無法馭劍。\n" );
        
	if ( str == "where" ) {
		where = (mapping)me->query("node");
		
		if (!where || sizeof(where) == 0 ) {
			write("你不記得任何地方可以馭劍飛去。\n");
			return 1; }
		else {
		
		msg = "你目前記得的地方有 : \n" ;
		
		node_name = keys(where);
		for( i=0; i < sizeof(node_name); i++ ) 
			msg += sprintf("  %d : %s\n", i+1, node_name[i]);
		write(msg);
		return 1; } 
		}
	if ( sscanf(str, "%s %s", first, second) ) {
		write(first+second+"\n");	
		n = (string)environment(me)->query("short");
		d = base_name(environment(me));
		
		if ( first == "here" ) {
			where = (mapping)me->query("node");
		
			if (!where || sizeof(where) == 0 ) {
				me->set("node/"+n, d);
				return 1; }
			} 
		else return help(); } 
	
        if ( str == "guild" ) {
        	tell_object( me,
        		"你聚精會神、默運玄功於劍身上，身劍合一向目的地飛去 !!\n" );
 		tell_room( environment(me), 
 			sprintf("%s手掐劍訣，身劍合一向遠方飛去 !!\n", me->query("c_name")), me );       		
        	me->move_player( "/d/scholar/scholar/scholar_guild", "SNEAK" );
        	tell_room( "/d/scholar/scholar/scholar_guild", 
        		sprintf("一道銀白色的劍氣載著%s而來 !!\n", me->query("c_name")), me );
 		return 1; }      
	return 1;
}
*/

int help()
{
		write( @C_HELP
指令格式: eujian <參數>

這個指令讓你用來馭劍飛行。你可以加上下列的參數 :

	where       :     列出你目前所記得的地方。
	guild       :     飛回公會。
	here 1,2,3  :     記住此地。
	1,2,3       :     馭劍到那兒。 
C_HELP
		);
    return 1;
}
