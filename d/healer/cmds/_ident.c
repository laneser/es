//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int cmd_ident(string arg)
{
  object target;
  string c_realname;
  string realname;
  string s;
  string temp;
  int skills;
  int skill_require;
  int intelligent;
  
  if (! ( arg || arg=="") ) 
    return notify_fail("你要辨識什麼東西??\n");
  if (! target = present(arg,environment(this_player() ) ) )
    return notify_fail("你要辨識的東西不在這裡。\n");
  c_realname = target->query("c_realname");
  realname   = target->query("realname");
  skills     = this_player()->query_skill("herbs");
  skill_require = target->query("skill_require");
  intelligent = this_player()->query_stat("int");
  
  tell_room(environment(this_player()),this_player()->query("c_name")+
            "戴上他的老花眼鏡,對著"+target->query("c_name")+
            "仔細的觀查半天。\n",this_player() );
  if ( (! c_realname) || (! realname) || 
     ( skills < skill_require ) || (intelligent <10) )
    return notify_fail("你對著"+target->query("c_name")+"辨識半天,還是看不出個所以然來。\n");
  
  tell_object(this_player(),
              "根據你的經驗, 你判斷這是一棵"+c_realname+"("+realname+")。\n");
  sscanf(identify(target),"%s/%s",s,temp);
  if (this_player()->query_temp("last_verify")==0)
    this_player()->set_temp("last_verify",temp+"\n" );
  else
    this_player()->add_temp("last_verify",temp+"\n" );
  return 1;
}

int help()
{
  write(
  @C_HELP
指令格式: ident <植物名>

這個指令讓你能夠正確辨識出一種植物。
由於藥用植物很多都長的極為相似, 如果不加辨識就加以採集,
很可能會發生藥物誤用的事情, 甚至造成無法彌補的錯誤, 因此
刑老爹規定所有healer在採藥前一定要先加以辨識。

如果你無法成功的辨識一種不知名的植物, 可能是因為你的智慧
太低, 也可能是因為對藥草辨識<herbs> 的技能認識不夠, 可以
先到公會充實自己後再試一次。
C_HELP
  );
  return 1;
}
