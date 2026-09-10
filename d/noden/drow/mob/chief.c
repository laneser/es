#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(9);
        set_name( "Drow village leader","老村長");
        add ("id", ({ "drow", "leader" }) );
        set_short( "Drow village leader","老村長");
        set("unit","位");
        set_long(
@C_LONG
他的年紀一大把卻仍然擔任著村內的協調工作，他就是黑暗精靈村的
老村長，最近神官執意將一位女祭司送往神壇祭祀，似乎造成了老村　
長的煩惱(trouble)，你可以幫幫他嗎？
C_LONG
        );
        set_perm_stat("str", 12);
        set_perm_stat("dex", 11);
        set_natural_weapon(10,6,9);
        set_natural_armor(25,10);
        set( "special_defense",
                (["all":15,"fire":-10,"cold":-10,
                        "evil":30,"divine":-30,"none":5 ]) );
        set("gender", "male");
        set("wealth/copper",500);
        set("weight" , 700);
        set ("race", "drow");
        set( "inquiry", ([
                "trouble" : "女祭司嗎？唉．．可憐的蒂德，誰能去幫(help)她呢？ \n",
                "help" : "蒂德被神官送到司娜可神殿(temple)了，就已經獻給神了，要如何救她呢？\n",
                "temple" : "喔．．神殿平常人是不能進去的啦，除非是勇者(valor)的傳人才能進入啦！\n",
                "valor" : "@@ask_valor",
      "mark" : "還問？你到底要不要去拿啦？\n",
               ]) );
        wield_weapon(OBJ"copper_blunt");
        equip_armor(ARM"bracers");
        equip_armor(ARM"ring1");
}

int ask_valor()
{
        tell_object(this_player(),@LONG
村長說：唷，你也覺得自己是是勇者嗎？前幾天來玩的都說是勇者，
結果都騙我～～～所以，我決定，除非你能得到修凱思的認可，能通過他
的考驗並且拿他的徽章(mark)給我，證明 (certification)你是勇者，我
再教你如何靠近神殿！
LONG
        );
        this_player()->set_temp("drow_certi",1);
        return 1;
}


int accept_item(object me, object item)
{
        string name;
        object ob;

        name=(string)item->query("name");
        if (!name || (name!="captain's seal"))
                return 1;

        write("老村長說：嗯，是徽章沒錯，你等等．．．．\n");
        if (!this_object()->query("scale"))
        {
                write("老村長說：拿去吧，這片蛇鱗得來不易，相信對你會有幫助的。\n");
                ob=new(OBJ"scale");
                ob->move(this_player());
                set("scale",1);
        }
        else
                write("老村長慢慢的說道：真可惜，有人也給我徽章了，你的是仿冒品吧！\n");
                return 1;
}
// QCing.
