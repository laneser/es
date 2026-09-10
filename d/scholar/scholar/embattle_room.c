#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	seteuid( getuid() );
	set_short("青松軒");
	set_long(
@LONG
這是舞墨軒的陣法研究室, 名曰「青松」。牆上刻畫著各種陣法的排列、要訣、
步法以及佈陣攻擊的方法。你可以看到幾位書生一起走著奇特的步法，正在試著模擬
這些陣法，幾個書生正低頭沉思要如何運用這些陣法。或許你也可以試著去看看牆壁
上(wall)的那些陣法精要。
LONG
	);
        set("item_desc", ([
             "wall": @LONG
牆上刻著：舞墨軒不傳之秘，書生陣法精要。
┌——————————————————┐
│   須習得一定基本技能之後方能學習   │
│   否則於修行時對自己有莫大的危險   │
│   現在你可以試著去研習(study)。    │
│   ==============================   │
│                                    │
│      1.  兩儀微塵陣 (two)          │
│      2.  天地人三才陣 (three)      │
│      3.  四象璇璣陣 (four)         │
│      4.  八卦游龍陣 (eight)        │
│                                    │
└——————————————————┘
     請使用(help_require)查詢學習陣
     法所需要的基本技能。
LONG
            ]) );
	set( "light", 1 );
	set( "exits", ([ 
                "up" : "/d/scholar/scholar/storage",
		"down" : "/d/scholar/scholar/hall" ]) );
	reset();
}

void init()
{
        add_action("do_help_require","help_require");
	add_action("do_study", "study");
}

int do_help_require()
{
  tell_object(this_player(),@LONG
┌———————————————————————┐
│==============================================│ 
│        陣法                  技能需求        │ 
│  1.  兩儀微塵陣         陣法(embattle) >= 31 │
│  2.  天地人三才陣       陣法(embattle) >= 51 │  
│  3.  四象璇璣陣         陣法(embattle) >= 71 │ 
│  4.  八卦游龍陣         陣法(embattle) >= 91 │ 
│==============================================│  
└———————————————————————┘
LONG);
  return 1;
}

int do_study(string str)
{
  int emb,ok,ok2=0,is_member=-1,flag;
  string *embat,msg;
  mapping known;

  if (!str)
    return notify_fail("你要研習什麼 ?\n");
  emb=this_player()->query_skill("embattle");
  if (!emb || emb<=30)
    return notify_fail("對不起，你的陣法技能不足以研習這些陣法。\n");
  known=(mapping)this_player()->query("embattle");
  if (known && sizeof(known)!=0) {
    embat=keys(known);
    ok2=1;
  }
  switch (str) {
    case "two":
       if (emb>30) {
         ok=1;
         this_player()->set("embattle/two",1);
       }
       msg="兩儀微塵";
       break;
    case "three":
       if (emb>50) {
         ok=1;
         this_player()->set("embattle/three",1);
       }
       msg="天地人三才";
       break;
    case "four":
       if (emb>70) {
         ok=1;
         this_player()->set("embattle/four",1);
       }
       msg="四象璇璣";
       break;
    case "eight":
       if(emb>90) {
         ok=1;
         this_player()->set("embattle/eight",1); 
       }
       msg="八卦游龍";
       break;
    default: return notify_fail("Syntax: study <陣法名>\n");
  }; 
  if (ok2)
    is_member=member_array(str,embat,flag);
  if ((ok==1)&&(is_member>=0))
    ok=2;
  switch (ok) {
    case 1: write("經過一番思考、練習之後，你成功的學會了"+msg+"陣。\n");
            break;
    case 2: write("你已經會"+msg+"陣了。\n");
            break;
    default: write("你的陣法技能還不夠修行"+msg+"陣。\n");
  };
  return 1;
}
