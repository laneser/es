//  File     : /adm/simul_efun/tell_room.spec.c
//  /adm/simul_efun/tell_room.c 的 spec。
//
//  這個函式全樹有 2500 多個呼叫點，其中 95 個只給兩個參數。
//  新驅動的 efun message() 第四個參數不接受 0，而 tell_room() 是 varargs ——
//  exclude 沒給時它是 0 卻照樣傳下去，一走到就拋錯打斷呼叫端的流程。
//  這組測試就是釘住「少給參數也不能炸」。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

object lest_subject(string target)
{
	//  需要一個真的房間當訊息目標
	return load_object("/d/std/rooms/void");
}

void test_two_args_does_not_throw(object room)
{
	mixed err;

	err = catch( tell_room(room, "【lest】只給兩個參數\n") );
	expect_true( !err, "省略 exclude 不該拋錯" +
		(err ? "：" + err : "") );
}

void test_three_args_object(object room)
{
	mixed err;

	err = catch( tell_room(room, "【lest】exclude 給單一物件\n", this_object()) );
	expect_true( !err, "exclude 給 object 不該拋錯" + (err ? "：" + err : "") );
}

void test_three_args_array(object room)
{
	mixed err;

	err = catch( tell_room(room, "【lest】exclude 給陣列\n", ({ this_object() })) );
	expect_true( !err, "exclude 給 array 不該拋錯" + (err ? "：" + err : "") );
}

void test_explicit_zero_exclude(object room)
{
	mixed err;

	//  明確傳 0 —— 舊碼裡到處都是這種寫法，規範化之後也必須吃得下
	err = catch( tell_room(room, "【lest】exclude 明確給 0\n", 0) );
	expect_true( !err, "exclude 明確給 0 不該拋錯" + (err ? "：" + err : "") );
}

void test_rejects_non_string_message(object room)
{
	mixed err;

	err = catch( tell_room(room, ({ "不是字串" })) );
	expect_true( err, "訊息不是字串時應該要拋錯（這是刻意的防呆）" );
}
