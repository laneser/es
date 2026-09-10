/*
Message: 用來簡化一些常見動作訊息的寫作
Wrote by EGA, 11-21-1994
添加關於延遲效果的演出	/EGA, 3-8-1995
*/

/* Document
NAME
	emote - 將一個動作的敘述轉換成適當的文字傳送給在場的人
	
SYNOPSIS
	varargs void emote( string format, object me, 
						object where, object victim);
DESCRIPTION
	format 是一個特殊格式的字串, 裡面以 $NS, $NO 等符號代表動作
	者的名字、動作對象的名字等。emote 會根據後面的各個參數對這個
	字串做適當的代換, 並將處理後的訊息送給 me, victim, 以及 where
	裡的所有人。
	me 是動作者, victim 則是動作的對象, where 則是動作發生的房間
	
	victim 可以略去, 此時 $NO, $GO 兩個參數將不會生效。
	
	where 與 victim 可以一起略去, 此時 where 將自動被設定為 me 
	所在的房間。
	
	format 裡可用的參數如下:
	$NS		me 的名字
	$NO		victim 的名字
	$GS		me 的代名詞, 依性別為他、她或它
	$GO		victim 的代名詞
	
	要使用 emote 函數, 你必須在你的 object 中
	inherit "/std/message.c";
	如果你先前曾經 include <mudlib> 的話, 你也可以寫成:
	inherit MESSAGE;
	個人比較推薦後者。
               
EXAMPLE
	emote( "$NS抬起$GS的腳, 向$NO的屁屁重重地踢下去\n", ppla, 
			environment(ppla), pplb );
	ppla 將會看到: 你抬起了你的腳, 向 pplb 的屁屁重重地踢下去
	pplb 則會看到: ppla 抬起了他的腳, 向你的屁屁重重地踢下去
	如果 ppla 是男的話, 房間中的其他人則會看到: ppla 抬起了他的腳, 
		向 pplb 的屁股重重地踢下去
	
SEE ALSO
	emote_message
*/

/*
NAME
	emote_message_me
	emote_message_victim
	emote_message_other - 將一個動作的敘述轉換成適當的文字
	
SYNOPSIS
	varargs string emote_message_me( string format, object me, 
						object where, object victim);
	varargs string emote_message_victim( string format, object me, 
						object where, object victim);
	varargs string emote_message_other( string format, object me, 
						object where, object victim);
DESCRIPTION
	與 emote 相同, emote_message_xx 會將 format 裡的字串做適當的
	代換。不過並不會將訊息直接出去, 而是作為一個傳回值, 讓呼叫它
	的巫師自己處理。
	emote_message_me 所傳回的是由 me 所會看到訊息
	emote_message_victim 所傳回的則是由 victim 所會看到訊息
	emote_message_other 所傳回的則是在場的旁觀者所會看到訊息
	
	有時候, 一個動作的對象可能有很多個而非一個, 此時 emote 就無
	法使用。你必須對每個動作的對象做一次 emote_message_victim()
	以其傳回值做 tell_object() 的動作才能得到正確的結果。
	
	emote_message 系列的函數也可以省略掉 where 與 victim, 不過
	當你省掉 victim 時, emote_message_victim 會傳回空字串。因為
	沒有動作的對象了。
	
	另外, me 與 victim 兩個變數可以放入「非生物」的物件, 但是此
	時 format 字串中若有$GS, $GO 兩個參數, 結果將無法預料。
	
SEE ALSO
	emote
*/

//PUBLIC FUNCTIONS
varargs	void	emote( string format, object me, object where, object victim);
varargs	string	emote_message_me( string format, object me, object where, 
				object victim);
varargs	string	emote_message_victim( string format, object me, object where,
				object victim);
varargs	string	emote_message_other( string format, object me, object where, 
				object victim);
varargs void	step_tell_object( mixed ob, string msg, int time_step);
varargs void	step_tell_room( mixed room, string msg, mixed exclude,
				int time_step);
varargs	void	step_object_msg( mixed ob, string message, object me, 
				object player);
varargs	void	step_room_msg( mixed room, string message, mixed exclude,
				object me, object player);

//VARIBLES
mapping	gender = (["male" : "他", "female" : "她", "neuter" : "它" ]);

varargs	void	emote( string format, object me, object where, object victim)
{
	string	me_message, victim_message, other_message;
	
	if	(where && victim)	{
//填入行動者的名字
		me_message = replace_string( format, "$NS", "你");
		victim_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( format, "$NS", me->query("c_name") );
//填入行動對象的名字
		me_message = replace_string( me_message, "$NO", victim->query("c_name") );
		victim_message = replace_string( victim_message, "$NO", "你");
		other_message = replace_string( other_message, "$NO", victim->query("c_name") );
//填入行動者的性別
		me_message = replace_string( me_message, "$GS", "你" );
		victim_message = replace_string( victim_message, "$GS", gender[me->query("gender")] );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
//填入動作對象的性別
		me_message = replace_string( me_message, "$GO", gender[victim->query("gender")] );
		victim_message = replace_string( victim_message, "$GO", gender[victim->query("gender")] );
		other_message = replace_string( other_message, "$GO", "你" );
//發送訊息給在場的人
		tell_object( me, me_message );
		tell_object( victim, victim_message );
		tell_room( where, other_message, ({me, victim}) );
	}
	else if (!victim)
	{
//填入行動者的名字
		me_message = replace_string( format, "$NS", "你");
		other_message = replace_string( format, "$NS", me->query("c_name") );
//填入行動者的性別
		me_message = replace_string( me_message, "$GS", "你" );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
//發送訊息給在場的人
		if (!where)	where = environment(me);
		tell_object( me, me_message );
		tell_room( where, other_message, me );
	}
}

// emote_message_me: 傳回一個給動作者本身的訊息
varargs	string	emote_message_me( string format, object me, object where, object victim)
{
	string	me_message;
	mapping	gender = (["male" : "他", "female" : "她", "netural" : "它" ]);
	
	
	if (!format || !me) return "";
	if	(where && victim)	{
		me_message = replace_string( format, "$NS", "你");
		me_message = replace_string( me_message, "$NO", victim->query("c_name") );
		me_message = replace_string( me_message, "$GS", "你" );
		me_message = replace_string( me_message, "$GO", gender[victim->query("gender")] );
	}
	else if (!victim)
	{
		me_message = replace_string( format, "$NS", "你");
		me_message = replace_string( me_message, "$GS", "你" );
	}
	return me_message;
}

// emote_message_victim: 傳回一個給動作對象的訊息
varargs	string	emote_message_victim( string format, object me, object where, object victim)
{
	string	victim_message;

	if (!format || !me) return "";	
	if	(where && victim)	{
		victim_message = replace_string( format, "$NS", me->query("c_name") );
		victim_message = replace_string( victim_message, "$NO", "你");
		victim_message = replace_string( victim_message, "$GS", gender[me->query("gender")] );
		victim_message = replace_string( victim_message, "$GO", gender[victim->query("gender")] );
	}
	else if (!victim)
	{
		victim_message = "";
	}
	return victim_message;
}

// emote_message_other: 傳回一個給旁觀者的訊息
varargs	string	emote_message_other( string format, object me, object where, object victim)
{
	string	other_message;
	
	if (!format || !me) return "";
	if	(where && victim)	{
		other_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( other_message, "$NO", victim->query("c_name") );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
		other_message = replace_string( other_message, "$GO", "你" );
	}
	else if (!victim)
	{
		other_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
	}
	return	other_message;
}

varargs void	step_tell_object( mixed ob, string msg, int time_step)
{
	string	*msg_array;
	int		i;

	if (!time_step) time_step = 2;
	msg_array = explode( msg, "\n" );
	for ( i = 0; i < sizeof(msg_array); i++ )
	{
		call_out( "step_object_msg", i * time_step, ob, msg_array[i]+ "\n", 
					this_object(), this_player() );
	}
}

varargs void	step_tell_room( mixed room, string msg, mixed exclude,
				int time_step)
{
	string	*msg_array;
	int		i;
	
	if (!time_step) time_step = 2;
	msg_array = explode( msg, "\n" );
	for ( i = 0; i < sizeof(msg_array); i++ )
	{
		call_out( "step_room_msg", i * time_step, room, msg_array[i]+"\n", 
					exclude, this_object(), this_player() );
	}
}

varargs	void	step_object_msg( mixed ob, string message, object me, 
				object player)
{
	if ( (!me) || (!ob) )	return;
	tell_object( ob, message );
}

varargs	void	step_room_msg( mixed room, string message, mixed exclude,
				object me, object player)
{
	if ( (!me) || (!room) )	return 0;
	tell_room( room, message, exclude);
}
