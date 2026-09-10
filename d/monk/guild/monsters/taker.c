#include <mudlib.h>
//#define YUU_DROP "/u/m/mate/yuu_drop"

inherit MONSTER;

void create()
{
  ::create();
  // seteuid(getuid());
  set_level(19);
  set_name( "yuu", "油光老和尚" );
  set_short( "油光老和尚" );
  set_long(
    "橫列在你眼前的是功德坊管理員--油光老和尚，旁大的身驅，油光的大頭，\n"
    "把功德坊打掃的一塵不染。據說當年他在少林寺山腳下被智痴老和尚發現\n"
    "時，雖然才兩三歲左右，已經足以一手拔起少林寺大門外的蒼松，所以你\n"
    "最好別打他的歪主意。他最恨別人隨地亂丟垃圾，所以如果亂丟垃圾被他\n"
    "發現，生死可要自行負責。\n"
    "    你看他身上掛滿了袈裟，也許可以請他幫幫忙(help)拿點東西。\n"
  );

//  equip_armor ( "/u/m/mate/item/gloves.c" ); 
  set( "gender", "male" );
  set( "race", "dwarf" );
  set( "unit", "位" );
  set ( "no_attack", 1 );
	modify_stat("str",1000);
  set ("chat_chance", 1);
  set ("chat_output", ({
       "老和尚說: 歡迎光臨功德坊。\n",
       "老和尚說: 據說想在此留名的人必須闖過十八銅人陣。\n",
       "老和尚說: 你知道達摩祖師嗎?\n",
       "老和尚說: 既來之，則安之。\n",
       "老和尚說: 請各位慢慢參觀。\n",
       "老和尚說: 別忘了好好唸經, 超渡, 練功哦\n",
       "老和尚說: 見賢思齊焉，見不賢.....加點鹽吧....\n",
       "老和尚說: 好好參觀就好，不要太吵雜哦。\n",
       "老和尚說: 你能不能幫我打掃一下這間功德坊?\n",
       "老和尚說: 我好不容易才打掃乾淨的，請勿隨手丟東西。\n",
       "老和尚說: 我好不容易才打掃乾淨的，請勿隨手丟東西。\n"
  }) ); 
}

void init()
{
  add_action ( "do_ask",  "ask"  );
  add_action ( "do_give", "give" );
  add_action ( "do_drop", "drop" );
}

int do_drop ()
{
  write ( "老和尚說道: 師弟，在本功德坊內請勿亂丟東西!!\n" );
  return 1;
}

int weapon_armor ( object ob )
{
  if ( ob->query ( "armor_class" ) || ob->query ( "weapon_class" ) )
    return 1;
  return 0;
}

int do_give ( string arg )
{
  object yuu, me;
  object here;
  object ob, *ao;
  string name, what;
  object *usr;
  int    order, i, m, n;

  me = this_player();
  yuu = this_object();
  name = me->query ( "name" );
  here = environment (me);

  if ( !arg ) return 0;
  if ( sscanf ( arg, "%s %d", what, order ) == 2 ) {
    ao = all_inventory (me);
    n = sizeof (ao);
    m = i = 0;
    ob = ao[0];
    while ( i < n && m < order ) {
      if ( ao[i]->id (what) ) { m++; ob = ao[i]; }
      i++;
    }
    i--;
    if ( m == order ) {
      n = 0;
      if ( !ob->query ( "secure" ) && !ob->query ( "prevent_drop" ) &&
           weapon_armor ( ob ) ) {
        ob->move ( yuu );
        ob->delete("value");
        n = 1;
      }
    }
  }
  else if ( arg == "all" ) {
    n = 0;
    ao = all_inventory (me);
    for (i=0; i<sizeof (ao); i++) {
      ob = ao[i];
      if ( !ob->query ( "secure" ) && !ob->query ( "prevent_drop" ) && 
           weapon_armor ( ob ) ) {
        ob->move ( yuu );
        ob->delete("value");
        n++;
      }
    }
  }
  else if ( ob = present ( arg, me ) ) {
    n = 0;
    if ( !ob->query ( "secure" ) && !ob->query ( "prevent_drop" ) &&
         weapon_armor ( ob ) ) {
      ob->move ( yuu );
      ob->delete("value");
      n = 1;
    }
  }

  if ( n > 0 ) {
/*
    usr = users();

    for (i=0; i<sizeof(usr); i++)
      if ( (string)usr[i]->query ( "class" ) == "monk" )
        tell_object ( usr[i],
          "[少林和尚] 老和尚(yuu): 感謝"+name+"為本公會供應"+n+"件東西!!!\n" );
*/
    tell_room ( here, "老和尚說道: 大家謝謝"+name+"為大夥兒提供東西吧!!\n" );
  }
  else if ( ob )
    write ( "老和尚說道: 師弟啊!!我又不是垃圾筒，"+
            "這種東西給我女兒麻由美還差不多!!\n" );
  else
    write ( "老和尚說道: 師弟啊!!你是想累死我嗎!!\n" );

  return 1;
}

int ask_help ()
{
  tell_object( this_player(), 
    "你可以請他丟下裝備，或請他幫忙拿裝備。\n"
    "問老和尚有那些東西    : ask yuu about eqs\n"
    "請老和尚丟東西到地上  : ask yuu about drop <種類>\n"
    "請老和尚丟東西到地上  : ask yuu about drop <裝備名稱>\n"
    "請老和尚撿起所有東西  : ask yuu about get\n"
    "把你身上的東西給老和尚: give <東西>\n"
    "請按 ask yuu about types 查看可以要求老和尚幫忙的種類\n\n"
  );
  return 1;
}

int ask_types ()
{
  tell_object ( this_player(),
"\n頭盔	鎧甲	臂環	護手	脛甲	鞋子	盾	披風	護身符	戒指\n" +
"head	body	arms	hands	legs	feet	shield	cloak	amulet	finger\n" +
"\n" +
"\n" +
"核心	球	馬鞍	尾巴	長刃		杖槌\n" +
"kernel	globe	saddle	tail	longblade	blunt\n\n"
  );
  return 1;
}

int ask_drop ( string s )
{
  object *ao;
  object ob;
  object here, me, yuu;
  object *usr;
  string name;
  int   i, n, m;

  if ( !s ) {
    write ( "老和尚說道: 師弟到底要老衲做什麼咧?!\n" );
    return 1;
  }
  else if ( s == "all" ) {
    write ( "老和尚說道: 師弟，偷懶不行喔!!\n" );
    return 1;
  }
  me = this_player();
  name = (string)me->query ("c_name");
  yuu = this_object();
  here = environment (me);

  tell_room ( here, "老和尚說道: "+name+"要老衲幫忙? 待老衲瞧瞧....\n" );

  ao = all_inventory (yuu);
  n = sizeof (ao);
  m = 0;

  for (i=0; i<n; i++) {
    ob = ao[i];
    if ( (string)ob->query ("type") == s ) {
      if (command ( "drop " + ob->query ( "name" ) ))
        m++;
    }
    else if (command ( "drop " + s ) )
        m++;
  }
  if ( m == 0 ) {
    tell_room ( here,
      "老和尚說道: 抱歉哦，"+name+"，老衲實在是愛莫能助。\n" );
  }
  else
    tell_room ( here,
      "老和尚說道: 和尚們注意，"+name+"要老衲丟了"+m+"件東西!!!\n" );
/*
  else {
    usr = users();

    for (i=0; i<sizeof(usr); i++)
      if ( (string)usr[i]->query ( "class" ) == "monk" )
        tell_object ( usr[i],
          "[少林和尚] 老和尚(yuu): 和尚們注意，"+name+
          "要老衲丟了"+m+"件東西!!!\n" );
  }
*/
  return 1;
}

int ask_get ( )
{
  object *ao;
  object ob;
  object here, me, yuu;
  int   i, n, m;

  me = this_player();
  yuu = this_object();
  here = environment (me);

  tell_room ( here, "老和尚說道: 很好，不隨手亂丟東西是好習慣....\n" );
  command ( "get all" );
  tell_room ( here, "老和尚說道: 老衲能撿的都撿了。\n" );
  return 1;
}
int ask_eqs(object me)
{
	object *inv;
	string msg, color ;
	int i;
	inv = all_inventory(this_object());
	if ( sizeof(inv) ) {
		msg = "老和尚把他的收藏給你看，他身上帶著 : \n" ;
		for ( i = 0 ; i < sizeof(inv) ; i ++ ) {
			if ( inv[i]->query("weapon_class") )
				color = "HIY" ;
			else if ( inv[i]->query("armor_class") || inv[i]->query("defense_bonus"))
				color = "HIC" ;
			else
				color = "WHT" ;

			msg += set_color(sprintf("	%s(%s)\n",inv[i]->query("short"),
							capitalize(inv[i]->query("name"))),color,me) ; 
		}
	}	else {
		msg = "老和尚說道 : 可憐 ... 和尚我現在四大皆空 ....\n";
	}
	tell_object(me,msg);
	return 1;
}
int do_ask ( string s )
{
  string what, name;

  if ( this_player()->query("class") != "monk" ) {
     tell_object(this_player(),@MESS1
老和尚說道：哼！你又不是少林僧人，如何可以命我如何如何......
MESS1 );
     return 1; }
 
  if ( !s ) {
    write ( "老和尚說道: 師弟到底要老衲做什麼咧?!\n" );    return 1;
}
  if ( sscanf ( s, "yuu about %s", what ) == 1 ) {
  	if ( what == "eqs" ) return ask_eqs(this_player());
    if ( what == "help" ) return ask_help();
    if ( what == "type" || what == "types" ) return ask_types();
    if ( what == "get" ) return ask_get ();
  }
  if ( sscanf ( s, "yuu about %s %s", what, name ) == 2 ) {
    if ( what == "drop" ) return ask_drop ( name );
  }
  return 0;
}
