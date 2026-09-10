#include "../tsunami.h"
#include <stats.h>

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name("General Kagado","神武將軍 神我人");
    add("id",({"general","kagado"}) );
    set_short("神我人將軍");
    set_long(@LONG
神武將軍神我人是目前總領魔族軍備的指揮官，直接聽命於天皇行事。端詳此人，
身材高大魁武，大小傷痕無數，想必是已經經歷過大小戰爭無數次了。這人對王家還
算忠誠，只是也有一個非常要不得的缺點，就是愛財如命，凡事只要有錢，他都肯幫
忙，比如說：洩露皇城的通行密碼呀.....等等之類的；當然，叛國例外！
LONG
            );
    set("unit","位");
    set("gender","male");
    set("race","daemon");
    set("alignment",-1000);
    set("time_to_heal",5);
    set_natural_armor(30,30);
    set_natural_weapon(5,15,17);
    set_perm_stat("str",20);
    set_perm_stat("dex",20);
    set("max_hp",800);
    set("hit_points",800);
    set_skill("parry",80);
    set_skill("longblade",100);
    set_skill("block",80);
    set("wealth/gold",200);
    set("special_defense",(["all":30,"none":20]) );
    set("aim_difficulty",(["critical":80,"vascular":10,"ganglion":40]) );
    set("exp_reward",15000);
    set("inquiry",([
         "password":"@@ask_passwd"]) );    
    wield_weapon(TWEP"sword1");
    equip_armor(TOBJ"shield2");
    equip_armor(TOBJ"helmet1");
    equip_armor(TOBJ"boot1");
    equip_armor(TOBJ"chainmail");
}

void init()
{
    add_action("do_pay","pay");
}

int do_pay(string str)
{
    string who, type;
    int num;
    if( !str || str=="" || sscanf(str, "%s %d %s",who, num, type) !=3)
    return notify_fail("付誰?多少錢？\n");
    
    if(!id(who)) return 0;
    
    if(type != "copper") {
    tell_object(this_player(),
    "神我人將軍以不屑的口吻說：你們都只知道用金的，銀的....我偏偏就要銅的啦！\n");
    return 1;
    }
    
    if( !this_player()->debit(type, num)){
      write(
      "神我人將軍怒道：錢不夠還敢來？來人，把這傢伙轟出去！\n");
      tell_room( environment(this_player()),
      "將軍突然喝來左右，將"+this_player()->query("c_name")+"轟了出去！\n"
      ,this_player() );
      this_player()->move_player(CITY"sway3","SNEAK");
      tell_room( environment(this_player()),
      "哇～～！突然前方一團黑影落下，哦～～！原來是"+this_player()->query("c_name")+"被人扔了出來啦！\n"
      ,this_player() );
      return 1;
    }
    if(num < 500){
    write("神我人將軍瞪大著眼兒看著你的錢袋：小鬼，不夠哦！！\n");
    return 1;
    }
    if(num >= 500){
    write(@BLONG
神我人將軍笑咪咪的說：小子，你有前途，不錯哦！！
                      聽仔細了，只說一次............
                      很久很久以前有一個老公公和一個老婆婆........

你伸長著脖子仔細的聽著............
BLONG
               );
    this_player()->set_temp("block_command",1);  
    call_out("leave",5,this_player());
    return 1;
    }           
}    
    
int leave()
{
   write(@CLONG
神我人將軍突然有氣無力的說：我累了，你退下吧！！
CLONG
        );
   this_player()->set_temp("block_command",0);
   this_player()->set_explore("island#3");
   return 1;     
}   

int ask_passwd()
{
    write(@CLONG
神我人將軍說：問通行密碼？當然沒問題呀........
說著說著把臉轉向窗外，偌大的手掌攤在你面前晃呀晃的，你知道該怎麼做了.......
CLONG
         );
    return 1;
}          
