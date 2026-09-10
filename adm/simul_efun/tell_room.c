varargs void tell_room(mixed room, mixed msg, mixed exclude)
{
	if( stringp(msg) ) {
        if( !room || !objectp(room) ) return;
		//	FluffOS 2019 以後 efun message() 的第四個參數只接受 object 或 array，
		//	不再接受 0。省略不傳是合法的（tell_object() 就是這樣），
		//	但這個函式是 varargs —— exclude 沒給時它是 0，卻照樣被當成第四個
		//	參數傳下去。全樹有 95 個 tell_room() 呼叫點只給兩個參數，
		//	一旦走到就會拋出 Bad argument 4 to EFUN message() 打斷呼叫端的流程。
		if( objectp(exclude) ) exclude = ({ exclude });
		else if( !pointerp(exclude) ) exclude = ({ });
		message( "tell_room", msg, room, exclude );
		return;
	}
    error("Tell_room: Message must be a string.\n");
}
