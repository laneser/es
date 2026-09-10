#define dead ({"會陰","膻中","乳中","神闕","神道","靈臺","百會" })
#define diff ({ 6,3,5,3,4,3,5 })

int dam,i,acu_sk,con_sk,my_dex,tar_con,tar_dex,tar_dod,diffculty;
string point,part,tar_name,my_name ;
object me,target ;

int sucess(string point,string part) ;
int fail(string point,string part) ;

int remove_block(object obj)
{
    obj->delete_temp("block_command") ;
    return 1 ;
}

int damage(object killer,object tar,string pt,string par)
{
     me = killer ;
     target = tar ;
       acu_sk = me->query_skill("acupuncture") ;
       con_sk = me->query_skill("concentrate") ;
       tar_dod = target->query_skill("dodge") ;
       tar_name = target->query("c_name") ;  
       tar_con = target->query_perm_stat("con") ;
       tar_dex = target->query_perm_stat("dex") ;
       my_dex  = me->query_perm_stat("dex") ;
       my_name = me->query("c_name") ;
       tar_name = target->query("c_name") ;
       point = pt ;
       part = par ;
       
       if(acu_sk>100) acu_sk = 100 ;
       if(con_sk>100) con_sk = 100 ;

     if(target == me)
       {
          write("想自殺打SUICIDE就夠了,不要太虐待自己。\n") ;
          return -1 ;
       } 
     if(target->query_level()<10)
       {
          write("大神往你腦袋敲了下去說道: 不要欺負小朋友。\n") ;
          tell_room(environment(me),my_name+"的手突然伸到"+tar_name+
                "面前,正當千鈞一髮之際,\n他的手莫名其妙的僵在半空, 頭上同時多了好幾個包。\n",me);
          return -1;
       }  
     me->set_temp("block_command",2) ; 
     target->kill_ob(me) ;
     if(member_array(point,dead)) diffculty = diff[member_array(point,dead)]  ;
    if(random(my_dex*2+acu_sk/2+con_sk/2) > random(tar_dex*diffculty)+tar_dod/2) 
      {
         return sucess(point,part) ;
       }
     else
       {
         return fail(point,part) ;
       }
}

int sucess(string point,string part)
{
    int db = target->query("defense_bonus") ;
    write(sprintf("你用銀針往%s%s的%s穴紮了下去。\n在一聲悽慘的哀號後,他開始攻擊你。\n"
                  ,tar_name,part,point) );
    
    me->block_attack(2) ;
    me->set_temp("msg_stop_attack",
            "( 一種違抗傳統道德價值的變態快感讓你忘了正在戰鬥中。 ) \n" ) ;
               
    tell_object(target,sprintf(
              "%s往你%s的%s穴紮了下去。\n在一陣巨痛後,你開始攻擊%s。\n"
              ,my_name,part,point,my_name) ) ;
                       
    tell_room(environment(me),sprintf(
              "%s拿出銀針往%s%s紮了下去,隨著一聲慘叫,\n%s開始攻擊%s。\n"
              ,my_name,tar_name,part,tar_name,my_name)
              ,({me,target}) ) ;
    call_out("remove_block",3,me) ; 

    dam = (((acu_sk+con_sk)*diffculty)/(tar_con+tar_dex))-db/3 ;
    return dam ;   
}

int fail(string point,string part)
{
    write(sprintf("當你用銀針往%s%s的%s穴扎過去時。\n"
                  "他似乎發現了你的意圖而開始攻擊你。\n"
                  ,tar_name,part,point) );
    
    tell_object(target,sprintf(
              "%s往你%s的%s穴紮了下來。你發現他不懷好意。\n"
              "於是你先發制人開始攻擊%s。\n"
              ,my_name,part,point,my_name) ) ;
                       
    tell_room(environment(me),sprintf(
              "%s拿出銀針往%s%s紮了下去,但是%s大喝一聲:『 你想做什麼? 』\n"
              "%s和%s不知怎麼的就打了起來。\n"
              ,my_name,tar_name,part,tar_name,tar_name,my_name)
              ,({me,target}) ) ;
    call_out("remove_block",3,me) ;
    return -1 ;
}


