//  File     : /adm/simul_efun/verify_password.spec.c
//  /adm/simul_efun/verify_password.c 的 spec。
//
//  這是升級驅動時新增的東西，也是全站唯一的密碼驗證入口 ——
//  舊存檔（FluffOS 2017 以前驅動內建演算法的產物）全靠它才進得來，
//  一旦壞掉所有既有玩家都會被鎖在門外，值得釘死。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

//  這個受測對象是 simul_efun，不是可以 clone 的物件
object lest_subject(string target)
{
	return 0;
}

void test_old_hash_accepted(object ob)
{
	//  admin 的原始存檔雜湊，密碼是 12345。回傳 2 代表
	//  「密碼正確，但存的是舊格式」，呼叫端據此把它升級成 SHA512。
	expect_eq( verify_password("12345",
		"ale`eakf!fkhecckjnjkn`k`nmggafnldg`hmmamh"), 2,
		"舊格式雜湊應該驗得過，並回報 2 要求升級" );
}

void test_old_hash_wrong_password(object ob)
{
	expect_eq( verify_password("wrong",
		"ale`eakf!fkhecckjnjkn`k`nmggafnldg`hmmamh"), 0,
		"舊格式雜湊配錯密碼應該回 0" );
}

void test_new_hash_accepted(object ob)
{
	string hash;

	//  crypt() 第二個參數不是字串時產生 $6$ 開頭的 SHA512
	hash = crypt("hunter2", 0);
	expect_true( verify_password("hunter2", hash),
		"新格式（SHA512）雜湊應該驗得過" );
}

void test_new_hash_wrong_password(object ob)
{
	expect_eq( verify_password("nope", crypt("hunter2", 0)), 0,
		"新格式雜湊配錯密碼應該回 0" );
}

void test_new_hash_reports_no_upgrade(object ob)
{
	expect_eq( verify_password("hunter2", crypt("hunter2", 0)), 1,
		"已經是新格式時應該回 1，不要求升級" );
}

void test_rejects_garbage(object ob)
{
	expect_eq( verify_password("x", ""), 0, "空的雜湊不該驗過" );
	expect_eq( verify_password("x", "a"), 0, "太短的雜湊不該驗過" );
	expect_eq( verify_password(0, "whatever"), 0, "密碼不是字串時不該驗過" );
	expect_eq( verify_password("x", 0), 0, "雜湊不是字串時不該驗過" );
}
