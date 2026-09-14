#include "/d/eastland/story/story.h"
int time=0,k=0;
string *cast_msg1=
     ({ "%s開始凝聚空氣中寒冷的氣流，匯聚成一股巨大的冰團！\n",
        "%s口中開始冒出陣陣的白煙，噴出些微火星!\n",
        "%s不斷地喃喃自語跟著眼中微閃著異芒！ \n" }),
       *cast_msg2=
     ({ "%s身旁的冰團急速地撲向你面前，彷佛四肢百駭都要被凍僵了！\n",
        "%s口中大喊「三昧真火」，漫天烈焰往你身上澆去，使你炙痛難當!\n",
        "只見%s眼中的異芒射穿了你卑微的身子!\n" }) ;
inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "Archmaster Chn.", "巫真" );
	add ("id", ({ "archmaster","master","chn","chn."}) );
	set_short( "護國師 巫真");
	set_long(@CLONG
護國師 巫真 是城內僅次於城主，權位最高的人，平時只聽命於城主，可說是「一
人之下，萬人之上。」富貴榮寵俱在一身！巫真年約六、七十歲年紀，一副道貌岸
然，和藹可親，兩眉業已垂到地下，不見任何驕貴之氣，儼然是位慈祥老者。巫真
同時是城中見識最多，歷練最為豐富的人，平時城主有猶豫不決的事情都會來向他
請教，結果往往都是獲益而歸，因此，他是為城主最好的左右手。巫真最擅長於巫
筮禁咒之類，愈接近年老，魔法力愈是高強！巫真的魔法力可由他手中的沌混之杖
看出一番，如果你有什麼遇到魔杖型武器之類(wand)的困擾或許可以向他討教。
CLONG
	);
	set("gender","male");
        set("race","巫師");
	set_perm_stat("str", 18 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 30 );
	set( "alignment", 1000 );
	set( "hit_points", 750 );
	set( "max_hp", 750 );
        set( "max_fp",350);
	set( "force_points",350);
	set_natural_weapon( 22, 8, 18 );
	set_natural_armor( 45, 30 );
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":40,"weakest":40 ]) );
        set("wealth/gold",100);
        set("stun_difficulty",100);
        set_temp("bs",20);
        set_temp("be_joke",3);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("wand",70);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"wiz_wand1");
        equip_armor(SWARM"wiz_robe1");
        equip_armor(SWARM"wiz_ring1");
        equip_armor(SWARM"wiz_amulet1");
        set("special_defense",(["all":100,"none":40,"cold":70,"monk":30]));
        set("inquiry",([
          "special_things":"@@ask_things",
         "entrance_palace":"@@ask_entrance", 
                    "help":"@@ask_help",
            "golden_older":"@@ask_older",
            "fly_building":"@@ask_building",
           "great_vampire":"@@ask_vampire",
             "spirit_ball":"@@ask_ball",
            "heaven_water":"@@ask_water",
                    "wand":"@@ask_wand",
                     "fix":"@@ask_fix"
        ]) );  
}
int convert_value(object ob)
{
    mixed *charge;
    int val;
    charge = ob->query( "value" );
    if( !charge || !pointerp(charge) ) 
        return 2000;
    if( !intp(charge[0]) || charge[0]==0 || !stringp(charge[1]) ) 
        return 2000;
    val = charge[0] * coinvalue( charge[1] ) / coinvalue("silver");
    if( val < 1000 ) val = 2000;
    return val;
}
void ask_fix(object asker)
{
    object wea1;
    string name;
    int value;
    wea1=asker->query("weapon1");
    if (!wea1 || (wea1->query("type")!="wand") ) {
       write("巫真說道：你手上並沒有任何魔杖型武器可供我修理。\n");
       return ;
    }
    if ( wea1->query("charge_left") ) {
       write("巫真搖搖頭道：依我的能力看來，這把魔杖型武器並沒有壞掉。\n");   
       return ;  
    }
    value=convert_value(wea1);
    name = wea1->query("c_name");
    if ( !asker->debit("silver", value/2) ) {
       write(sprintf("巫真說道：對不起，要修復這把 %s 需要 %d 個銀幣！\n"
            ,name,value/2));
       return ;
    }
    wea1->unwield();
    write(sprintf("\n只見巫真唸唸有詞，然後一道青色的光芒籠罩在你手上的 %s ..\n\n",name));
    wea1->create();
    write(sprintf("巫真說道：好了，收取你 %d 個銀幣並把你手上 %s 修復完畢，你試試看。\n\n",value/2,name));
    return ;
}                             
              
void ask_wand(object asker)
{
write(@LONG
巫真說道：我是可以幫你修理(fix)某些毀損的魔杖型武器，但會視情節收取若
　　　　　幹費用。
LONG
   );
}
void ask_water(object asker)
{
write(@LONG
巫真說道：天堂之水？傳說中的天堂之水位於極北寒冷地帶，又有神物呵護，
　　　　　是極難取得的。天堂之水在室溫下是處於氣體狀態，你最好帶著特
　　　　　別的容器之類，像是吉神泰逢常背的大紅葫蘆，在原產處予以盛貯
　　　　　方是良策。不過嘛，泰逢是不會隨便給人的他的葫蘆的，他一定會
　　　　　裝死假裝不知道。    

LONG
   );
}

void ask_ball(object asker)
{
write(@LONG
巫真說道：「巽靈珠」？是城主叫你來找我的嗎？
巫真續道：「巽靈珠」原本是城內至寶，是一種殺傷力極大的武器，有點類似
　　　　　火藥之類的，可是那珠更厲害，珠內的毒藥會隨著敵人的血液到達
　　　　　到心臟，給敵人致命的一擊。原本是極陰損的東西，自古以來只有
          交給最善良的人保管，無怪乎城主會那麼緊張，萬一落到壞人的手
          中，那將是一大浩劫。不過水能覆舟亦能載舟，千古以來，「巽靈
          珠」只曾拿來對付蚩尤大軍之用。
　　　　　
LONG
   );

}
void ask_vampire(object asker)
{
write(@LONG
巫真說道：谷辰乃是一具僵屍精，如果你想要收拾它，最好帶著我恩師的
         「滅魔符」(ghost_spell) 比較有勝算。可是，自從我恩師被
         天帝懲罰之後，下落不明，我就再也沒有遇到他了。

LONG
   );
   asker->set_temp("wizelder",1);
}
int accept_item(object player, object item)
{
    object mark;
    if ( !item->query("basket_used")  ) {
       write("巫真笑道：謝謝，我不需要這樣東西。\n");
       item->move(environment());
       return 1;
    }
    write(@LONG
巫真接過你給他的籃子，說道：
　　　真謝謝你，幫我找回那隻白狗，我也沒什麼東西好給你的，
　　　我聽人說你到處打聽想進入皇宮，我這裡有個令牌，你可以
　　　持著它就不會有人攔你了。
　　　　　　　　　　　　　　
LONG
    );
    item->remove();
    mark=new(SWITEM"mark1");
    mark->move(environment());
    return 1;
}

void ask_building(object asker)
{
  write(@LONG
巫真說道：天都？沒去過咩，你再去問別人吧。  
LONG
  );  
}
void ask_older(object asker)
{
   write(@LONG
巫真說道：金石老人？喔，那是個脾氣古里古怪的人，我還跟他見過幾次面，
LONG
   );   
}
void ask_help(object asker)
{
  write(@LONG
巫真說道：去年，我買了一隻純白的狗名叫吉利(lucky)給我那小孫女兒玩，
　　      前幾天卻失縱了，害得她茶不思飯不想，我看也難過，你能幫我
　　　　　找回來嗎？        　　　
LONG
   );
}
void ask_entrance(object asker)
{
   write("巫真說道：你想進去皇宮？除非你幫我一件事(help)，我就替你設法。\n");
}
void ask_things(object asker)
{
   tell_room(environment(),@LONG
巫真說道：特別的東西？哦，我手上的魔杖也很特別啊？

巫真說完便拿起他的魔杖向你炫耀一番，^_^。
LONG
    );
}
void haha()
{
   delete_temp("block_command");
}
void cast_run(string type,string msg,string mob_name,int damage)
{
   object env,*all;
   int i,max;
   env=environment(this_object());
   all=all_inventory(env);
   tell_room(env,sprintf(msg,mob_name));
   max=sizeof(all);
   for (i=0;i<max;i++)
     if ( all[i]!=this_object() )
        all[i]->receive_special_damage(type,damage);
   k--;
   if ( !k ) call_out("haha",2);
}
void chn_attack()
{
  object victim,env;
  string mob_name,msg1,msg2,type;
  int damage,i;
  env=environment(this_object());
  mob_name=query("c_name");
  for ( i=1;i<3;i++) {
    k++;
    switch( random(3) ) {
    case 0:
       msg1=set_color(cast_msg1[0],"HIW");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[0],"HIW");
       type="cold";
       damage=50+random(10);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    case 1:
       msg1=set_color(cast_msg1[1],"HIR");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[1],"HIR");
       type="fire";
       damage=45+random(15);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    default:
       msg1=set_color(cast_msg1[2],"CYN");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[2],"CYN");
       type="devil";
       damage=55+random(5);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    }
  }  
  set_temp("block_command",1);
}
int my_tactic()
{
    int i,max;
    object victim,env,*atk;
    string power,name;
    set("force_points",350);
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    if ( time ) {
       if ( time>1 ) 
         tell_room( env,set_color("巫真手中正在凝聚一顆巨大的金球...\n","HIY"));     
       else {
         tell_room( env,set_color(sprintf(
            "巫真向前一指把手中栲栳大的金球往地上一丟，登時炸得眾人血肉橫飛！\n\n"),"HIY"));         
         if ( atk=all_inventory(env) ) {
            max=sizeof(atk);
            for(i=0;i<sizeof(atk);i++)
               if ( atk[i]!=this_object() ) 
                  atk[i]->receive_special_damage("electric",90+random(10));
         } 
       }
       time--;
       return 1;
    }
    switch( random(15) ) {
    case 0..2:
        if ( query_temp("block_command") ) break;
        chn_attack();
        break;
    case 3:
        time=3+random(1);
        break;    
    default :
        break;
    }
    return 0;
}
