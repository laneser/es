//  File     : /adm/simul_efun/verify_password.c
//  Purpose  : 統一的密碼驗證，相容新舊兩種雜湊格式。
//
//  FluffOS 2019 以後 crypt() 改走系統 crypt()：第二個參數不是字串時
//  產生 $6$ 開頭的 SHA512 雜湊，是舊式 salt 時只取前兩個字元當 key。
//  本 mudlib 在 MudOS / FluffOS 2017 時代存下來的密碼是驅動內建演算法
//  的產物（41 個字元，不以 $ 開頭），新版只有 oldcrypt() 認得它。
//
//  回傳值：
//    0  密碼錯誤
//    1  密碼正確，且已是新格式
//    2  密碼正確，但存的是舊格式雜湊 —— 呼叫端應該就地改存 crypt(pass, 0)
//
//  06-09-10 升級為 FluffOS v2026 驅動時新增
int verify_password(string pass, string stored)
{
	if( !stringp(pass) || !stringp(stored) || strlen(stored) < 2 ) return 0;

	//  新格式（$1$ / $2a$ / $5$ / $6$）直接交給系統 crypt
	if( stored[0] == '$' ) return stored == crypt(pass, stored);

	//  舊 mudlib 存檔：先試驅動內建的舊演算法，再試系統 crypt（DES）
	if( stored == oldcrypt(pass, stored) ) return 2;
	if( stored == crypt(pass, stored) ) return 2;
	return 0;
}
