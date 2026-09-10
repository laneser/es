//#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int help();
void op_fail(object healer,string patient);
void op_success(object healer,string patient,object corpse);
int operate_living(string patient, string target);
int rate;


string *messages =({
"發現患者血管破裂了, 急忙用止血鉗止血。\n",
"細心的將已經壞死的組織細胞切除。\n",
"用鑷子將傷口中的異物挾了出來。\n",
"將內出血的地方小心的縫合起來。\n",});

int cmd_operate(string arg)
{
	    object dest,*inv,*inv2,me,weapon;
	    int hp,sp, max_hp,i,j , size,corpse_here ;
	    int stats, op_skill,clot,first_aid,anatomlogy;
        string myname,*ids;
        string patient,target;
        
        me = this_player();
        
        if( !me->query_skill("operation") ) 
          return notify_fail ("你沒學過手術學, 不敢動手。\n");
        weapon = (object) me->query("weapon1");
        
        if ( (!weapon) || (string)weapon->query("type")!="dagger" )
          return notify_fail ("你沒有裝備適當的工具, 沒辦法進行手術。\n");
          
        if( me->query("stop_attack")!=0) 
             return notify_fail( "你的上個動作還沒完成,無法動手術。\n" );

    	if( !arg || arg=="" ) return help();
        
        if (sscanf(arg,"%s at %s", patient,target)==2)
        {
           operate_living(patient,target);
           return 1;
        }   
        
        inv= all_inventory(environment(me));
        size = sizeof(inv);
        corpse_here=0;
        
        for ( i = 0 ; i < size ; i++) {
           ids=inv[i]->query("id");
           for (j = 0 ; j < sizeof(ids) ; j++) {
             if ( (sscanf(ids[j],"corpse of %s",myname)==1) && 
                lower_case(myname)==lower_case(arg) ) {
               inv[i]->set("prevent_get",1);
               corpse_here=1;
             }  
           }
           if (corpse_here==1) break;
        }       
        if(! (dest=find_player(arg) ) ) 
             return notify_fail("沒有這個人存在, 打錯字了吧?\n");
        if( ( (int)dest->query("ghost")!= 1 ) )
             return notify_fail(dest->query("c_name")+"活的好好的, 你是在咒他早死嗎?\n");     
        if( corpse_here==0) 
             return notify_fail(dest->query("c_name")+"的身體並不在這裡, 你想幫他動手術, 卻心有餘而力不足。\n");
        inv2= all_inventory(inv[i]);
        if(sizeof(inv2)!=0) 
             return notify_fail("你要先把病患身上的累贅拿掉才方便動手術。\n");
        if (dest->query_temp("operate")) 
             return notify_fail("已經有人在替他動手術了, 你現在進去插一腳只會越幫越忙。\n");     
        sp= (int) me->query("spell_points");
        if (sp<200) 
             return notify_fail("你現在精神力不夠, 無法集中精神進行手術。\n");
        
        sp = sp - 200;
        this_player()->set("spell_points",sp);

        op_skill=me->query_skill("operation");
        first_aid =me->query_skill("first-aid");
        clot = me->query_skill("clotting");
        anatomlogy= me->query_skill("anatomlogy");
        stats= me->query_stat("int")+me->query_stat("pie");
        op_skill=op_skill+op_skill;
        if (environment(me)->query("op_room")) op_skill=op_skill+op_skill;
        rate = stats*10 + op_skill+first_aid+clot+anatomlogy;
        rate = (rate * rate) / 10000;
        if (wizardp(me))
            tell_object(me,"The score of u for operation here is "+rate+"\n");
        dest->set_temp("operate",this_player()->query("name"));
        call_out("op_step1",3,this_player(),inv[i],weapon,arg);
        if (!wizardp(this_player()))      
            this_player()->set_temp("block_command",1);
    return 1;
}

int operate_living(string patient,string target)
{
     object doctor, pat;
     int sp;
     int skill;
     int degree;
     
     doctor = this_player();
     pat = present(patient,environment(doctor));
     if (pat == doctor) { tell_object(doctor,"你不能替自己動手術。\n");
                          return 1;
                        }  
     if (!pat || !living(pat) || !visible(pat,doctor)) {
        tell_object(doctor,"你要幫誰開刀??");
        return 1;
     }   
     skill=doctor->query_skill("operation");
     sp = doctor->query("spell_points");
     if (lower_case(target) == "eye") {
       if ( sp < 30) {
         tell_object(doctor,"你的精神力不夠, 不能動手術。\n");
         return 1;
       }  
       if (!pat->query("blind")) {
         tell_object(doctor,"他的眼睛正常的很, 不需要醫療。\n");
         return 1;
       }  
       tell_room(environment(doctor),doctor->query("c_name")+"開始替"+
                 pat->query("c_name")+"的眼睛動手術。\n",({doctor,pat}));
       tell_object(doctor,"你開始替"+pat->query("c_name")+"的眼睛動手術。\n");
       tell_object(pat,doctor->query("c_name")+"開始替你的眼睛動手術。\n");          
       sp -= 30;
       doctor->set("spell_points",sp);
       degree=pat->query("blind");
       degree=degree - ( skill/20);
       if ( degree > 0 ) { 
         pat->set("blind",degree);    
         tell_object(doctor,"你的病患經你手術後, 病情似乎有些好轉, 但仍未痊癒。\n");
         tell_object(pat,"你覺得你的眼睛在手術後似乎好了一些, 但仍然看不清楚東西。\n");
       } else {
         pat->delete("blind");
         tell_object(doctor, "你的患者已經完全康復了。\n");
         tell_object(pat, "你的視力已經完全恢復, 終於再次重見光明。\n");
       }     
     } else {
       tell_object(doctor,"你想要對患者哪裡開刀?"); 
       return 1;
     }  
         
}
void op_step1(object healer,object corpse,object weapon,string patient)
{
     object dest;
     string name;
     
     dest=find_player(patient);
     if (!dest) { op_fail(healer,patient);
                  return;
                }  
     if ( (int) dest->query("ghost")!=1 ) {
        if(environment(dest)==environment(healer)) op_success(healer,patient,corpse);
        else op_fail(healer,patient);
        return;
     }    
     if (!corpse) {
         //      write("屍體出了問題, 手術失敗\n");
               op_fail(healer,patient);
     }
     name = corpse->query("short");
     if (name=="腐爛的屍體" || name=="骸骨" || name=="枯骨") {
         op_fail(healer,patient); 
         return;
     }    
     tell_object(healer, "你小心的用手中的"+weapon->query("c_name")+
                         "將患者胸部劃開一道開口, 並立刻將它固定。\n");
     tell_room(environment(healer),healer->query("c_name")+
               "熟練的用手中的"+weapon->query("c_name")+
               "將患者胸部劃開一道開口, 並立刻將它固定。\n",healer);                    
     call_out("op_step2",2,healer,corpse,weapon,patient);
}     

void op_step2(object healer,object corpse,object weapon,string patient)
{
     object dest;
     int i;
     string name;
     
     if (!patient) {// write("no patient wrong");
                     op_fail(healer,patient);
                     return;
                   }       
     dest=find_player(patient);
     if (!dest) { //write("find_player(patient) wrong");
                  op_fail(healer,patient);
                  return;
                }  
     if ( (int) dest->query("ghost")!=1 ) {
        if(environment(dest)==environment(healer)) op_success(healer,patient,corpse);
        else {
          //write("not ghost now");
          op_fail(healer,patient);
        }  
        return;
     }    
     if ( healer->query_attackers() ) {
        op_fail(healer,patient);
        return;
     }   
     if (!corpse) {
            //   write("屍體出了問題, 手術失敗\n");
               op_fail(healer,patient);
     }
     name = corpse->query("short");
     if (name=="腐爛的屍體" || name=="骸骨" || name=="枯骨") {
       //write(name);
       op_fail(healer,patient);                    
       return;
     }  
     if (random(rate)<8) {// write (rate);
                          // write ("\nrandom fail\n");
                           op_fail(healer,patient);
                           return;
                         }  

     i = random(sizeof(messages));
     tell_object(healer, "你"+messages[i]);
     tell_room(environment(healer),healer->query("c_name")+messages[i],healer);
     call_out("op_step2",2,healer,corpse,weapon,patient);
}     

void op_fail(object healer,string patient)
{
   object dest;
   int fail_count;
   
   if (patient) {
     dest=find_player(patient);
     if (dest) dest->delete_temp("operate");
   }   
   if (fail_count=(int)healer->query("op_fail_count")) {
       fail_count++;
       healer->set("op_fail_count",fail_count);
   } else {
       healer->set("op_fail_count",1);
   }        
   healer->delete_temp("block_command");
   tell_object(healer,"你發現你的患者完全失去生命跡像, 已經回天乏術了。\n");
   tell_room(environment(healer),healer->query("c_name")+
             "一臉頹喪的表情, 緩緩的放下手中的手術刀, 可能是手術失敗了。\n",healer);
}

int op_success(object healer,string patient,object corpse)
{
   object dest;
   int stat;
   int decrease_count;
   string decrease_stats;
   int succ_count;
      
   healer->delete_temp("block_command");
   
   if (!patient) return notify_fail("手術過程出了點差錯, 請通知巫師處理。\n");
   dest=find_player(patient);
   if (!dest) return notify_fail("手術過程出了點差錯, 請通知巫師處理。\n");

   if (succ_count=(int)healer->query("op_succ_count")) {
       succ_count++;
       healer->set("op_succ_count",succ_count);
   } else {
       healer->set("op_succ_count",1);
   }
   tell_object(healer,"手術終於完成, 開始縫合傷口。\n");
   tell_room(environment(healer),healer->query("c_name")+
             "開始縫合傷口, 手術已經將近完成。\n",healer);
   tell_object(healer,"你累了個滿身大汗, 終於完成了這次手術。\n");
   tell_room(environment(healer),healer->query("c_name")+
             "累了個滿身大汗, 終於完成了這次手術。\n",healer);
   corpse->remove();
   decrease_count=0;
   if (random(rate)<50) {
     dest->set_perm_stat("str",(int)dest->query_perm_stat("str")-1);
     decrease_count++;
     decrease_stats="力量";
   }    
   if (random(rate)<50) {
     dest->set_perm_stat("int",(int)dest->query_perm_stat("int")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、智慧";
     else decrease_stats="智慧";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("dex",(int)dest->query_perm_stat("dex")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、敏捷";
     else decrease_stats="敏捷";
     decrease_count++;
   }       
   if (random(rate)<50) {
     dest->set_perm_stat("con",(int)dest->query_perm_stat("con")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、體質";
     else decrease_stats="體質";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("pie",(int)dest->query_perm_stat("pie")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、虔誠";
     else decrease_stats="虔誠";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("kar",(int)dest->query_perm_stat("kar")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、運氣";
     else decrease_stats="運氣";
     decrease_count++;
   }
   if (decrease_count==0) 
     tell_object(dest,
            "這真是一次再成功不過的手術, 不僅順利把你救活, 連一點損失都\n"+
            "沒有。你該考慮辦幾桌酒席請請這位勞苦功高的醫生。\n");
   else 
     tell_object(dest,
            "雖然這算是一次成功的手術, 但由於某些原因使你在"+decrease_stats+
            "\n各受到一點的損失。\n"+
            "話雖如此, 能把你從鬼門關拉回來, 你還是該好好謝謝你的主治大夫。\n"
            );
                      
	return 1;
}
     
int help()
{
    write(
    @C_HELP
指令格式: operate <某人> operate <某人> at <部位>

在某個人物剛停止呼吸時, 經驗豐富的行醫者仍有機會動手術將他從鬼門關
拉回來, 由於手術是一門高難度的技巧, 只有在急救術, 解剖學, 止血技能
, 以及手術技能都登峰造極的行醫者有較高的成功率。不過即使成功救活, 
該人物的某些屬性還是可能會受到一點的損失。
手術須要在極專心的情況下進行, 因此需要耗費很多的精神力, 而且過程中
不能受到干擾, 如果在手術中遭到攻擊, 手術便必然失敗。
**動手術的時機越快越好, 一旦人物屍體開始腐爛, 或是該人物已經還陽,
  再多的努力也是枉然。
除此之外, 也可以對患者的特定部位進行手術, 目前完成的有以下部位:
1.眼睛(eye) : 幫助失明的人重見光明。
C_HELP
	);
    return 1;
}
