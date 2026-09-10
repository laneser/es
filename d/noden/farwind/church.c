#include "farwind.h"
#define MARRIAGE_FILE "d/noden/data/marriages.o"

inherit ROOM;

string *couples, *pending;
int i, j, numcouples, numpending;
string str ;


void create()
{
        ::create();
        seteuid(getuid()) ;
    set("objects", ([ "priest" : FARWIND"monster/nolen" ]) );
//    set("objects", ([ "priest" : "/u/e/elon/nolen" ]) );
    reset() ;
        set ("light", 1) ;
    set_short("教堂");
    set_long(@TEXT
這是一間小小的教堂, 地上鋪著光滑的石磚, 從天花板上照下來的光使得
地面看來閃閃發亮. 兩邊牆上掛了一些畫及各式浮雕, 其中一片牆上刻著歷年
來在這個世界上結為夫妻的人名. 正前方有一個講臺, 旁邊立了一個告示牌(sign).

TEXT
    );
        set("exits", ([ "south" : FARWIND"ebazz" ]) );
    set("item_desc", ([
//    "wall" : "@@list_couples",
    "sign" : @SIGN
查看已結過婚的人:

couples

如何結婚:
首先, 找個結婚對象. 然後找個公證人,(注: 跟據這個世界的某些不成文的規
訂, 我們會建議您請一個巫師級的人物當公證人, 不過如果您堅持不要找巫師
當證婚人, 我們也不會反對).找齊觀禮人後由公證人輸入:
marry <男方> <女方>
這裡的牧師就會為您主持婚禮了.

注: 要取消婚禮... 用 cancel 指令.
    只有公證人可以取消一場婚禮, 如果公證人不在場則任何人都可以取消.

如何離婚:
    必須請一位巫師級的人物公證離婚, 由他(她)輸入:

    divorce <男方> <女方>
這裡的牧師就會為您主持婚禮了.
SIGN
    ]) );
//    numpending = 0 ;
//    pending = allocate(10) ;
        str = read_file(MARRIAGE_FILE,1,1) ;
        if (!str) {
                numcouples = 0 ;
                couples = allocate(1) ;
                return ;
        }
        if (sscanf(str,"%d",numcouples)!=1) {
        write ("嗯... 牆上的字有點模糊不清, 你最好跟教堂工作人員講一下!\n") ;
                return ;
        }
        couples = allocate(numcouples+1) ;
        for (i=0;i<numcouples;i++) {
                str = read_file(MARRIAGE_FILE,i+2,i) ;
                sscanf (str,"%s\n",couples[i]) ;
        }
        set("busy",0);

}
void divorce_end()
{
    set("busy",0);
}
void init()
{
    add_action("setup_marriage", "marry");
    add_action("cancel_marriage", "cancel");
    add_action("list_couples", "couples");
    add_action("setup_divorce", "divorce");
}

int cancel_marriage()
{
    object ob;
    if (!query("witness")) return notify_fail("沒有正在進行的婚禮!\n");
    ob=present(query("witness"),this_object());
    if ((string)this_player()->query("name")!=(string)query("witness"))
        {
        if (ob) {
                return notify_fail("你沒有權取消這場婚禮!\n");
        }
    }
    set("witness");
    tell_room(environment(this_player()), "婚禮取消了!!\n", this_object());
    // clean up everything..
    ob=present("nolen",this_object());
    ob->set("husband");
    ob->set("wife");
    ob->set("witness");
    ob->set("step",1);
    ob->set("wait");
        set("busy",0);
    return 1;
}

int setup_marriage(string str)
{
    string n1,n2,n3;
    object ob1, ob2;
    if (!str) return notify_fail("語法: marry <男方> <女方>\n");
    if ((int)query("busy") == 1) return 
      notify_fail("有人正在結婚或離婚... 請稍等一會!\n");
    if (sscanf(str,"%s %s",n1,n2)!=2) return
        notify_fail("語法: marry <男方> <女方>\n");
    n3=(string)this_player()->query("name");
    if ((n3==lower_case(n1)) || (n3==lower_case(n2))) return
        notify_fail("幫自己證婚? 這麼可憐, 沒人要幫你證婚啊?\n"+
            "去去去... 路上抓個人來不會啊.\n");
    ob1=present(lower_case(n1),this_object());
    ob2=present(lower_case(n2),this_object());
    if ((!ob1 || !ob2)) return notify_fail("人沒到齊結什麼婚啊?!\n");
    if (ob1->query("spouse") || ob2->query("spouse")) return
        notify_fail("嗯..... 兩人之中有一個已婚了... 還是不要...\n");
    if (ob1->query("npc") || ob2->query("npc")) return
        notify_fail("你只能幫玩家證婚.\n");
    if ( ((string)ob1->query("class") == "monk" && (int)ob1->query("18brass") != 2) ||
       ((string)ob2->query("class") == "monk" && (int)ob2->query("18brass") != 2) ) return
        notify_fail("和尚不能結婚! \n");
    ob1=present("nolen",this_object());
    if (!ob1) return notify_fail("那個... 牧師今天放假. 改天吧!\n");
    ob1->set("husband",lower_case(n1));
    ob1->set("wife",lower_case(n2));
    ob1->set("witness",this_player()->query("name"));
    set("witness",this_player()->query("name")); // for cencel
        set("busy",1);
    return ob1->perform_marriage();
}

int setup_divorce(string str)
{
    string n1,n2,n3;
    object ob1, ob2,me,nolen;
    seteuid(getuid());
    me=this_player();
    if ( !wizardp(me) ) return notify_fail("離婚必須由巫師為見證人!\n");
    if (!str) return notify_fail("語法: divorce <男方> <女方>\n");
    if ((int)query("busy") == 1) return 
      notify_fail("有人正在結婚或離婚... 請稍等一會!\n");
    if (sscanf(str,"%s %s",n1,n2)<2) return
        notify_fail("語法: divorce <男方> <女方>\n");
    n3=(string)this_player()->query("name");
    n1=lower_case(n1);     n2=lower_case(n2);
    ob1=present(n1,this_object());
    ob2=present(n2,this_object());
    if(!ob1 && ! ob2) return notify_fail("沒人要離婚啊.... \n");
    nolen=present("nolen",this_object()); 
    if (!nolen) return notify_fail("那個... 牧師今天放假. 改天吧!\n");

    if(!ob1)
      if( lower_case(ob2->query("spouse"))==n1 )
       if(file_size("/data/std/connection/"+n1[0..0]+"/"+n1+".o")<0) 
       {
           tell_object(ob2,"原來配偶死了, 熬不住了?\n");
           tell_object(ob2,"好吧， 就完成你的心願吧!\n");
           shout(ob2->query("c_name")+"自從喪偶後，慾火中燒, 終於熬不住要離婚了!!!\n");
           tell_object(ob2,"好了, 你的心願完成了!\n");
           ob2->delete("spouse");
           return 1;
        }
      else  return notify_fail("夫妻雙方都健在的必須同時到場! \n");
    
    if(!ob2)
      if( lower_case(ob1->query("spouse"))==n2 )
       if(file_size("/data/std/connection/"+n2[0..0]+"/"+n2+".o")<0) 
       {
           tell_object(ob1,"原來配偶死了, 熬不住了?\n");
           tell_object(ob1,"好吧， 就完成你的心願吧!\n");
           shout(ob1->query("c_name")+"自從喪偶後，慾火中燒, 終於熬不住要離婚了!!!\n");
           tell_object(ob1,"好了, 你的心願完成了!\n");
           ob1->delete("spouse");
           return 1;
        }
      else  return notify_fail("夫妻雙方都健在的必須同時到場! \n");

    if(!ob1 || !ob2) return notify_fail("你是不是敲錯名字了? \n");
    if (! ob1->query("spouse") || ! ob2->query("spouse")) return
        notify_fail("喂..... 還沒結婚就想離婚?\n");
    if(lower_case(ob1->query("spouse"))==n2 && lower_case(ob2->query("spouse"))==n1)
    {
      if(ob1->query("gender")=="male") 
      {
        nolen->set("husband",n1);
        nolen->set("wife",n2);
      }
      else
      {
        nolen->set("husband",n2);
        nolen->set("wife",n1);
      }
      nolen->set("witness",me->query("name"));
      nolen->set("male_agree",1);
      nolen->set("female_agree",1);
      set("busy",1);

      return nolen->perform_divorce();

    }
    else return notify_fail("你們倆可不是夫妻哦! \n");
    return 1;
}


int list_couples()
{
        int i ;
        string s1, s2, date ;

        if (numcouples==0) {
        write("現在並沒有任何正式登記的夫妻 ....可憐喔...\n");
        return 1;
    }
        for (i=0;i<numcouples;i++) {
                sscanf( couples[i],"%s-%s %s",s1, s2, date);
                write( i + "." +s1+" 和 "+s2+" 於 "+date+" 結婚.\n");
        }
    return 1;
}

int marriage_done(string n1, string n2)
{
        seteuid(getuid());
    shout("你聽到遠風鎮的教堂鐘聲歡欣地當當齊響 .... \n"+
          "路人們都歡欣唱道：「恭喜這對新人 !! 祝福 "+capitalize(n1)+" 和 "+capitalize(n2)+
         " 永遠幸福快樂 !!」\n");
    couples[numcouples] = n1+"-"+n2+" "+ctime(time());
        numcouples++;
        set("witness");
        set("busy",0);
        rm(MARRIAGE_FILE) ;
        write_file(MARRIAGE_FILE, numcouples+"\n") ;
        for (i=0;i<numcouples;i++)
                write_file (MARRIAGE_FILE, couples[i]+"\n") ;
        return 1;
}
