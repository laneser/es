
#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

inherit SELLER ;
inherit "/std/teacher";
inherit MONSTER ;
inherit DAEMON ;

void init()
{
	::init();
	teacher::init();
	seller::init();
	add_action( "tip_me", "pay");
}

void create()
{
	object bandage;
	int payed;
	::create();
	set_level(8);
        set_name( "Ann Dao Chun", "安道全" );
        set_short( "安道全" );
	add( "id", ({ "doctor","healer","ann","dao","chun" }) );
	set_long(@C_LONG
你看見一箇中年人，作遊方郎中的打扮，他就是聞名的神醫安道全．建康府人
，醫術通神，任何疑難雜症遇到他，只需要花點小錢就可以解決，現為梁山泊內
專治內外科諸病醫士。
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "pie", 25 );
        set_perm_stat( "kar", 20 );
        set_lessons( ([
	"depoison": ({ 150, 80 })
	]) );
	set_perm_stat("int",22);
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "anatomlogy", 85 );
        set_skill( "bandage",90);
	set("defense_type","dodge");
	payed=0;
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 150 );
        set( "hit_points", 150 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "evil": 30,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "heal": "@@ask_heal",
		"clot": "@@ask_clot",
		"cure": "@@ask_cure",
	        "sick": "@@ask_sick",
	        "diet": "@@ask_diet",
	        "bandage": "@@ask_bandage",
	        "sister": "@@ask_sister",
                "da": "@@ask_da",
                "depoison" : "@@ask_depoison"
        ]) );
        set_inventory( ({
                    ({ "/d/noden/farwind/items/plaster",40,40 }),
                    ({ "/d/noden/farwind/items/white_plaster",40,40 }),
                    ({ "/d/eastland/easta/obj/spicy_plaster",30,30 }),
                    ({ TOBJ"snow_lily",3,3 })
                    }));
        wield_weapon( TWEAPON"poblade" );
        equip_armor( TARMOR"small_cloth" );
        equip_armor( TARMOR"simple_boots");
          bandage=new("/obj/bandage");
          bandage->move(this_object());
}
    
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), 
        "安道全怒道: 卑鄙的傢伙 !! 打我還叫我醫你 !! 看我怎麼教訓你 ! \n" ,
        this_object() );
        (CONDITION_PREFIX +"simple_poison")->apply_effect(this_player(),8,5);
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"安道全說道: 你身體很好呀? \n" ,
	this_object() );
	return 1;
	}
	num=(hpmax-hp)*3;
        if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全搖搖頭道：「無錢免談。」\n",
	this_object() );
	return 1;
        }
	tell_room( environment(), 
	"醫生說道：哈哈..有錢好辦事，拿出一瓶小藥膏塗在你的傷口上，一陣清涼的感覺後，\n"+
	"你的傷連疤痕都沒留下。\n" ,
	this_object() );
	this_player()->set("hit_points",hpmax);
	return 1;

}
int ask_cure()
{
int num;

	if (I_hate_killer()) return 1;
        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/simple_poison"))
        {
        tell_room( environment(), 
        "安道全笑道: 你沒有中毒啊? 要不要我幫你施點毒?? \n" ,
        this_object() );
        return 1;
	}
        num=25;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全搖搖頭道：「無錢免談。」\n",
	this_object() );
	return 1;
        }
        tell_room( environment(), 
        "安道全拿出一匙黑色的刺鼻藥水，捏著你的鼻子灌了下去，你感覺全身痠軟無力，\n"+
	"頭重腳輕，但體內毒素似乎都消失了。\n" ,
        this_object() );
        this_player()->delete("conditions/simple_poison");
        command("say 在荒郊野外，毒蟲猛獸特別多，如果沒有學過解毒技巧，最好不要到處探險.......");
        return 1;

}

int ask_clot()
{
int num;

	if (I_hate_killer()) return 1;

        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/bleeding"))
        {
        tell_room( environment(), 
        "安道全說道: 你一滴血都沒流，省省吧... \n" ,
        this_object() );
        return 1;
	}
        num=15;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全搖搖頭道：「無錢免談。」\n",
	this_object() );
	return 1;
        }
        tell_room( environment(), 
        "醫生說道：好 !! 看我金針封穴，突然拿出一大把金針插入你的身體，你的流血\n"+
	"暫時停止了。\n" ,
        this_object() );
        this_player()->delete("conditions/bleeding");
        return 1;
}
int ask_sick()
{
  int num;
     if(I_hate_killer()) return 1;
     command("look "+(string)this_player()->query("name"));
     if (!this_player()->query("condition/sick"))
 {
     tell_room(environment(),
     "安道全說道: 你很健康呀? 奇怪...\n",
     this_object());
     return 1;
 }
      num=30;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全搖搖頭道：「無錢免談。」\n",
	this_object() );
	return 1;
        }
       tell_room(environment(),
       "安道全拍著你的頭念道: 抓邪抓鬼，驅魔除病，抓邪抓鬼，驅魔除病.....\n"
       "，雖然頭被拍受傷，但你發現你的病完全治好了．\n",
       this_object());
       this_player()->receive_special_damage("none",3);
       this_player()->delete("condition/sick");
       this_player()->set("medication_resistance",(int)this_player()->query("medication_resistance")*8/10);
       return 1;
}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3)
write(
"安道全說道: 你當我是幹什麼的啊??\n");
else {
write(
"\n安道全說道: 我們東方的醫術，是緩慢且溫和的，你如果要快速減肥，我可能\n"
"做不到，但是假如你身體夠好的話，你可以去找那個獸醫，他好像有一種讓馬\n"
"下痢的藥喔，天天吃，一定可以瘦下來的。說完，");
command("grin "+(string)this_player()->query("name"));
return 1;
}
}
int ask_bandage()
{
 int num,hpmax,hp;
	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"安道全說道: 你身體很好呀? \n" ,
	this_object() );
	return 1;
	}
	if (this_player()->query_temp("bandaged")!=0)
	{
	tell_room( environment(),
	"安道全笑道: 你已經接受過包紮醫療了.....\n",
	this_object() );
	return 1;
	}
	num=6;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全搖搖頭道：「無錢免談。」\n",
	this_object() );
	return 1;
        }
	if( !present("bandage",this_object() ) )
	{
	tell_room(environment(),
	"安道全嘆道：早知道那麼好賣，就多拿點繃帶出來。現在除非你能給我\n"
	"一些繃帶，否則我可是無能為力的。\n",
	this_object() );
	return 1;
	}
	command("bandage "+(string)this_player()->query("name"));
	command("rub "+(string)this_player()->query("name"));
        this_player()->set_explore("eastland#23");
	return 1;

}

int ask_sister()
{
write(
"\n安道全說道: 沒錯，我是有一個妹妹，叫作安小慧，生性刁蠻古怪，從小就不\n"
"太聽我的話，不過因為她是我唯一的妹妹，我也對她非常好，只是偶而會虧虧她\n"
"有一天，我有一個病人送我一顆大珍珠，由於小慧自小就非常喜歡珍珠，所以我\n"
"回家就把珍珠送給她，順便虧了她幾句人老珠黃之類的話，沒想到她就離家出走\n"
"了..........現在想想真是後悔.....................\n\n");
call_out("ask_sister2",10,this_player());
return 1;
}
int ask_sister2()
{
write(
"安道全抬頭看了你一眼，又說道: 是皇甫端告訴你的吧? 他這個人倒還好，只是\n"
"很喜歡道聽途說，說話都要打對摺，你還是不要抱太大的希望....\n"
"說完，安道全嘴裡嘰哩咕嚕的走回櫃檯，仔細一聽，好像是在說什麼女子很難養\n"
"的，但是他說的不清不楚，你聽的也很模糊。\n");
this_player()->set_temp("fat_quest/diet",1);
return 1;
}
int ask_da()
{
write (
"安道全想了一下，說道: 你問的是石碣村的達婆婆嗎? 她是少數我治不好的病人\n"
"之一。事實上，她根本只是營養不良而已，只是因為她相信自己活不久了，不相信我\n"
"的話，不吃藥，也不吃飯，才會搞成現在這個樣子。只要她肯吃飯和吃藥，她的病，\n"
"對我來說根本不是問題。說完，安道全繼續做他的事。\n");
return 1;
}
int ask_depoison()
{
command("say 你如果是常常在野外冒險的話，我倒是可以教你一些基本的解毒技巧，但是.......");
return 1;
}

int check_trainee(object trainee)
{
	if( (string)trainee->query("class")=="adventurer" 
	&& (int)trainee->query_level() > 9 && (int)trainee->query_temp("give_money")==1 )
		return 1;
	else
             return notify_fail( 
                    "安道全說道: 我只教夠資格的冒險者，如果你願意表現一下你的\n" 
                    "誠意的話，我就教你解毒的方法。\n");
}
int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail(
                        "付誰？多少錢？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
                tell_room( environment(), 
                        "安道全說道: 好漢 ! 對不起，我只收金幣。\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 100 ) {
	tell_room( environment(), 
                 "安道全說道: 好漢 ! 你的誠意不夠喔？\n" ,
                        this_object() );
		return 1;
	}
        tell_room( environment(), 
                 "安道全點點頭道: 好漢 ! 你現在就要開始學解毒術(depoison)了嗎？\n" ,
                        this_object() );

	this_player()->set_temp("give_money",1);
	return 1;
}

