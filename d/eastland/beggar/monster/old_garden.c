#include "../dony.h"

inherit MONSTER;
 
int receive_damage(int damage);
void create()
{
        object ob1;
	::create();
	set_level(19);
	set_name( "Old gardener", "老院長" );
	add( "id", ({ "old","gardener" }) );
        set_short( "祠堂 老院長" );
	set_long(@C_LONG
老院長是『新膽村』中最長壽的人, 相傳他己經活了三百年之久,這得歸功於他多
年研究長生不老之術。老院長平時掌管祠堂大大小小的事物, 近幾天以來為了『
丐幫』祭祖大典忙得不可開交,忙歸忙可是他仍然精神奕奕絲毫不輸那些年輕的小
夥子喔!!
C_LONG	
	);
        set("hit_points",2000);
        set("max_hp",2000);    
        set("weight",700);
        set("wealth/gold",200);
        set_perm_stat("str",25);
        set_perm_stat("int",35);
        set_perm_stat("dex",23);
        set_perm_stat("kar",40);
        set_natural_armor(70,0);
        set_natural_weapon(31,15,25);
        set_skill("dodge",60);
        set_skill("blunt",60);
        set( "race", "human" );
	set( "gender","male");
	set( "unit", "位" );
        set_temp("be_joke",10);
        set("aim_difficulty",
           (["critical":200,"vascular":70,"ganglion":50,"weakest":60]) );
        set("stun_difficulty",90);
        
        wield_weapon(DWEAPON"broom");
        equip_armor(DARMOR"enforcer_robe");
        ob1 = new( DITEM"life_ball" );
        ob1->move( this_object() );
        set( "inquiry", ([
                   "hau":"@@ask_hau",
               "history":"@@ask_history", 
                "before":"@@ask_before", 
             "continue1":"@@ask_continue1",      
             "continue2":"@@ask_continue2",
             "continue3":"@@ask_continue3",
                   "uki":"@@ask_uki",
              "worship":"@@ask_worship"       
                    ]) );
}
void init()
{
    ::init();
    add_action("do_backstab","backstab");
}
    
void do_backstab(string str)
{
    tell_object(this_player(),"想 bs ? \n");
    this_player()->set_temp("block_command",1);
    call_out("recover1",5,this_player());
}
void recover1(object obj)
{
    obj->delete_temp("block_command");
    tell_object(obj,"請不要在這種神聖的地方幹這碼事。\n");
}
void ask_hau(object asker)
{
   if ( asker->query_temp("uki_asked") ) {
      tell_object( asker,
        "祠堂 老院長說道:喔,你問霍先生內人的病?\n"
        "祠堂 老院長說道:其實小雪子說的沒有錯啦,只是九轉熊蛇丸生性屬陰需要一\n"
        "                屬陽的藥物才能達到『陰陽和合』的境界,把效用發揮到極\n"
        "                限,以至於起死回生。\n"
        "祠堂 老院長嘆道:唉,我本有多年研製的『六陽正氣丹』可以和熊蛇丸配合達\n"                         
        "                到『陰陽和合』的境界,可是不知道遺失在那裡.....\n\n"
        "祠堂 老院長想了一會兒......\n\n");
        asker->set_temp("old_asked",1);
        call_out("recover2",10,asker);
   } 
   else 
      tell_object( asker,
        "祠堂 老院長說道:我不清楚。\n"
      );     
}
void ask_history(object asker)
{
write(@C_LONG
老院長說道:你問『薪膽村』的歷史?那可是要從很久以前說起(before)?
C_LONG
      );
}
void ask_before(object asker)
{
write(@C_LONG
老院長說道:    大約在二百八十年前,中原江湖上各大幫派林立;多餘千人的大幫會少說
           有二、三百個;小如一、兩百人的小派門更是不下千個,一時風雲湧起襲捲著
           武林的每一個角落。
               然而, 學過經濟學的人都知道,在這塊有限的土地資源之下,一旦幫派多
           了起來相對的能分配給眾人的區域就少了起來。 更由於人類的惡根性---『
           深信著暴力就能夠解決一切』的支使之下, 凡是有地盤之爭或者彼此理念不
           同或者其它的芝麻小事都能使人大動幹伐。若是單純兩派之鬥還好,就是有那
           些想趁火打劫,想從中分一杯羹的, 往往引得一派的覆亡累至滿門於一夜之間
           悉數消失殆盡。不過總是有人會看不慣因而從中加以調停,調停的結果雖然表
           面上能使之罷鬥,但彼此總還會有或多或少的隙縫存在, 甚至有那些不甘於調
           停結果的,往往呼朋引伴其結果是引來更大的鬥爭。
老院長頓了一下,喝了一口茶,說道:要繼續(continue1)?           
C_LONG
    );
}
void ask_continue1(object asker)
{
write(@C_LONG
老院長繼續說道:  這時, 就有些屬於『較大』的門派倡議大家選一個武林盟主來領導眾
           人,一時頗得江湖中人的支持。但是,人人為爭那一個盟主席位更是打的頭破
           血流,引來的卻是另一場更大的血腥。出乎意料的是,選出來的武林盟主卻能
           夠帶來江湖上數十年的安寧, 想必是人類天生的努役性驅使吧!數十年之後,
           武學日式衰微, 江湖上再也找不到一個足以擔當武林盟主之位的人,於是,幹
           戈大起,引發了一場更大的浩劫。
老院長說道:對不起,口又渴了。老院長喝了一口茶。
老院長說道:要繼續(continue2)?                        
C_LONG
     );
}
void ask_continue2(object asker)
{
write(@C_LONG
老院長說道:   這時正值異族入侵,朝廷正苦於無法把整個中原勢力納入統治之中,見到江
          湖上那些武人自相殘殺,更是樂於旁觀。但為保千秋大業,勢必要把整個幫會勢
          力給連根拔起。於是,朝廷計劃籌謀,正當佈置好了所有準備, 但恰逢選出武林
          盟主相安後的數十年,於是宣告作廢。無奈數十年之後,武林又開始自鬥並且給
          了朝廷一個最好的機會,朝廷也知道這個良機一蹤即失,遂派遺鷹門爪牙逐一鏟
          除各大幫派。出手不外乎是威脅利誘,如有順從歸順那是最好不過,不服就連根
          給拔起,手段極其狠毒,僅僅幾個月之間,各大幫派已十之去九,這時武林像一盤
          散沙,又有那一個派門能抵擋得了朝廷的攻勢呢?
老院長說道:要繼續(continun3)?                            
C_LONG
     );
}
void ask_continue3(object asker)
{
write(@C_LONG
老院長說到這裡,面色有點慘白:   位天下第一大幫的丐幫在面臨朝廷這波的攻擊之下,不
          免也有些狠狽,更何況在異族還未入侵之前,丐幫處處在跟異族作對;入關之後,
          丐幫又到處滋擾生事表示不服異族統治,種種舉動早已被朝廷視為眼中釘,背後
          的芒刺。最後,丐幫在與朝廷的一場重要的決戰裡,自八袋弟子已上,悉數陣亡,
          所幸一名七袋見得快,得以保住幫中重要的物事, 更憂於朝廷防不勝防的攻勢,
          無奈只好退居到一處隱密之處,俟機復幫, 並把所在之地命名為『薪膽村』取'
          臥薪嚐膽'之意。到了這裡,仍然是推選一位幫主來管理一切的事務。日子飛逝
          ,漸漸地,丐幫在這裡安居下來,大部份的弟子也都娶妻生子,安和樂利了一百多
          年。可是,十多年前.......
你看老院長的樣子不想繼續再說下去,他臉上顯現遭遇到一件極悲慘的事。                    
C_LONG
    );
}
void ask_uki()
{
write(@C_LONG
老院長說道:小雪子是一個很不錯的女孩子,這些年多虧有她,否則,村內的人生病真不知道
           該怎麼辦?
C_LONG
    );           
}
void recover2(object obj)
{
      tell_object( obj,
        "祠堂 老院長說道:我記得在□完雞以後就不見了,你可以去找找。\n");
}
void ask_worship()
{
write(@C_LONG
祠堂 老院長說道:你問祭祖大典喔,那是村裡一年一度的盛事,幫主會招集所有的人考核過
                去一年來的功過。還有就是,如遇新舊幫主交接也是由那時完成。通常,
                在大典上都會邀請一些武林成名人士,唉, 已經在這裡生活了這麼久了,
                還有需要再去管那些江湖上的事嗎?
C_LONG
      );
}
int receive_damage(int damage)
{
    int hits;
    object victim,act_ob;
    string mob_name,vic_name;
    
    victim=query_attacker();
    if ( !victim ) return ::receive_damage(damage);
    mob_name=this_object()->query("c_name");
    vic_name=victim->query("c_name");
    
    act_ob = previous_object();
    if( act_ob && living(act_ob) ) set("last_attacker", act_ob);

    if ( ( victim->query("class")=="mage" ) )
       victim->set("spell_points",0);
    
    if (random(6)>2){
       tell_room( environment(this_object()),set_color(
            "嚇!!"+mob_name+"運起挪移心法,把所受到的傷害悉數由"+vic_name+"接收!!\n","HIW"),victim);
       tell_object( victim, set_color(
            "嚇!!"+mob_name+"運起挪移心法,把所受到的傷害悉數由你接收!!\n","HIW"));         
       hits = (int)victim->query("hit_points");
       hits -= damage;
       if( hits < 1 && wizardp(victim) && victim->query("immortal") )
          hits = (int)victim->query("max_hp");
       victim->set("hit_points",hits);
    }
    else{
       hits= (int)this_object()->query("hit_points");
       hits-=damage;           
       this_object()->set("hit_points",hits);
    }
    return 1;
}                                  
