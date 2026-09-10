//#pragma save_binary

/*
// Help added by Brian (1/28/92)
// Revised by Buddha@TMI (8/1/92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_emote(string str) {
    string first,tail,insert;

    if(!str) {
      write("你看起來表情豐富.\n");
      say(this_player()->query("c_name")+"作出豐富的表情.\n");
      return 1;
    }
    if (!wizardp(previous_object())) first = "-> ";
    else first = "";
    if (sscanf(str," %s",tail)==1) insert = "";
    else if (sscanf(str,"'%s",tail) == 1) insert = "";
    else insert = " ";
    write(wrap("你表達 : " + first + this_player()->query("c_name") +
	 insert + str));
    say(wrap(first + this_player()->query("c_name") + insert + str));
    return 1;
}

int
help() {
  write(@HELP
指令格式: emote <動作詞>
這條指令可以讓你表達一個系統沒有預設的動作詞。
系統會將你輸入的文字後加上你的姓名後顯示給同一個地區的生物看。

例：emote 大笑
    在同一地區的生物都會看到：->x大笑 (x=使用指令人名)

相關指令有：semote
HELP
);
  return 1;
}
/* EOF */
