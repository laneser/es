
// Deathland/ruin1/ruin55.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟");
     set_long(@Long

Long
,@C_Long
一座破舊的遺蹟 ,這裡似乎已經荒廢很久了 .地上到處是殘磚破瓦 ,更讓人覺得
這地方已經許久未曾有人煙了 .一種綠色的蘚苔植物附在兩旁的牆壁上 ,使得這地方
的氣氛更顯得十分的詭異 .這個地方是遺蹟的東北角 ,你來到這個地方的時候 ,你發
覺這裡似乎讓人有種被壓迫的感覺 ,這種感覺似乎來自那些似乎向你撲來的奇奇怪怪
石像 ,那些石像實在太嚇人了 ,讓人無法安心地待在這裡 .
C_Long
);
     set("now_weapons",([
         "longblade": 0,
         "thrusting": 0,
         "dagger": 0,
         "shortblade": 0,
         "chain": 0,
         ]));
     set("correct_weapons",([
         "longblade": 1,
         "thrusting": 0,
         "dagger": 0,
         "shortblade": 0,
         "chain": 1,
         ]));
     set("item_func",([
         "statue":"look_statue",
         ]) );
     set("search_desc",([
          "statue":"@@search_statue",
         ]) ); 
     set("exits",([
         "southwest":Deathland"/ruin1/ruin44",
         ]) );
     
     reset();
}

int look_statue()
{

    write(can_read_chinese() ?
          "一些駭人的石像 ,這些石像非常的逼真 ,它的樣子就像是張牙舞爪地向你侵\n"
          "襲 .這些石像之中每一個的造型都不盡相同 ,其中以他們手上所拿的武器讓\n"
          "你可以瞭解到這些石像的創作者是一個對於武器十分精通的人 ,長劍長矛短\n"
          "刀匕首連枷 ,每座石像所拿的武器都不盡相同 .這時你不盡懷疑了起來 ,這\n"
          "些石像放在這裡到底有甚麼目的呢 ?這個地方位於城市的角落 ,這些石像明\n"
          "顯地並不是守護著城市用的 ,也不會是讓人欣賞的 ,這些石像隱藏的秘密是\n"
          "什麼呢 ?\n" :
          "???"
         );
   return 1;
}

string search_statue()
{
    return 
      "當你仔細的搜尋這些雕像的時候 ,你發現在拿著短劍 ,匕首 ,長矛 ,長劍 ,\n"
      "以及連枷的五座雕像的底部各有一個小小的圓洞 ,似乎通到某個地方 ,但是\n"
      "由於洞口實在是太窄而且似乎很深 ,你無法看到裡面有什麼 ?\n" ;
}

void init()
{
     add_action("to_throw","throw");
}

int compare_weapon()
{    
     mixed weapons;
     int i;
     weapons=keys(query("now_weapons"));
     for(i=0;i<sizeof(weapons);i++)
       if ( (int)query("now_weapons/"+weapons[i]) !=  (int)query("correct_weapons/"+weapons[i]) )
        return 0;
     return 1;
}

int to_throw(string str)
{
    object player,ob;
    string weapon ,type;
    int i,chinese_mode;
    
    player=this_player();
    chinese_mode=can_read_chinese(player);
    
    if ( !str || str=="") 
       return notify_fail("The Syntax: throw <weapon> to hole\n"); ;
    if ( sscanf(str, "%s to hole", weapon) == 1 )
	   {
       ob=present(weapon,player);
       if(!ob)
	     return notify_fail( chinese_mode?
			"你身上沒有這樣東西。\n":
			"You don't have that on you.\n"); 
       if( ob->query("prevent_drop") || ob->query("secure") )
 		 return notify_fail( chinese_mode?
 			"你沒有辦法將它丟掉。\n":
 			"You can't drop that object.\n");       
       type =ob->query("type");
       if (  undefinedp( query("now_weapons/"+type) )  )
             return notify_fail(chinese_mode?"Error\n":"Error\n");
       tell_object(player,chinese_mode? "OK\n":"OK\n");
       ob->remove();
       i=(int)query("now_weapons/"+type) ;
       set("now_weapons/"+type,i?0:1);
       if ( (int)query("now_weapons/"+type) ==(int) query("correct_weapons/"+type) )
          {
          write("你聽到從洞中傳來一聲迴音 ......Ding......\n");
          if ( compare_weapon() ) {
            this_player()->move_player(Deathland"/ruin1/down01",
            ({"","","%s go here.\n","%s 從上面掉了下來.\n"}),"");
            write("你忽然地掉進一個地下室裡.\n");
            }
          }
       else 
          write("你聽到從洞中傳來一聲迴音 ......Dong......\n");
       
       return 1;
       }
    else 
      return notify_fail("The Syntax: throw <weapon> to hole\n"); 
}

void set_correct_weapons()
{
     set("correct_weapons/longblade",random(2)); 
     set("correct_weapons/shortblade",random(2)); 
     set("correct_weapons/dagger",random(2)); 
     set("correct_weapons/chain",random(2)); 
     set("correct_weapons/thrusting",random(2)); 
     return;
}


void reset()
{
     ::reset();
     set_correct_weapons();
     set( "direction" , random(3) );
     
}
