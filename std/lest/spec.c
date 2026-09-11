//  File     : /std/lest/spec.c
//  Purpose  : 所有 *.spec.c 測試檔都繼承這個檔，它提供斷言與結果收集。
//
//  一個 spec 檔長這樣（假設要測 /obj/bandage.c，檔名就是 /obj/bandage.spec.c）：
//
//      #include <lest.h>
//      inherit SPEC;
//
//      void test_有中文名(object ob) { expect_eq(ob->query("c_name"), "繃帶", "中文名"); }
//      void test_有重量(object ob)   { expect_gt(ob->query("weight"), 0, "重量為正"); }
//
//  規則：
//    - 函式名以 test_ 開頭的都會被自動找出來執行，收到的參數是受測物件。
//    - 受測物件預設是 clone_object(受測檔案)。房間、daemon 這類不該 clone 的，
//      在 spec 裡覆寫 lest_subject() 自己決定怎麼取得。
//    - 測完 lest 會呼叫 lest_cleanup() 把東西收掉，預設是 destruct()。
//
//  06-09-11 建立

#include <lest.h>

nosave mixed *lest_log;

void lest_reset()
{
	lest_log = ({});
}

mixed *lest_results()
{
	return lest_log ? lest_log : ({});
}

//  所有斷言最後都走這裡。cond 為真算通過。
varargs void expect(int cond, string desc, string detail)
{
	if( !lest_log ) lest_log = ({});
	lest_log += ({ ({ cond ? 1 : 0,
		desc ? desc : "(無描述)",
		detail ? detail : "" }) });
}

void expect_true(mixed got, string desc)
{
	expect( got ? 1 : 0, desc, sprintf("得到 %O，預期為真", got) );
}

void expect_eq(mixed got, mixed want, string desc)
{
	expect( got == want, desc, sprintf("得到 %O，預期 %O", got, want) );
}

void expect_ne(mixed got, mixed want, string desc)
{
	expect( got != want, desc, sprintf("得到 %O，預期不等於 %O", got, want) );
}

void expect_gt(int got, int want, string desc)
{
	expect( got > want, desc, sprintf("得到 %d，預期大於 %d", got, want) );
}

void expect_object(mixed got, string desc)
{
	expect( objectp(got), desc, sprintf("得到 %O，預期是物件", got) );
}

void expect_string(mixed got, string desc)
{
	expect( stringp(got) && got != "", desc,
		sprintf("得到 %O，預期是非空字串", got) );
}

//  取得受測物件。預設 clone；房間或 daemon 請在 spec 裡覆寫。
object lest_subject(string target)
{
	return clone_object(target);
}

//  測完的清理。預設把 clone 出來的東西收掉。
void lest_cleanup(object subject)
{
	if( subject ) destruct(subject);
}
