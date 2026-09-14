// angel
// Jun 4 1994

int query_need_fp()

{ 
    return 9;
}
int gonfu_level(object me)
{
        // 傳回熟練值
        return (int)me->query("k-dragon");
        //                     ^^^^^^^^^^^^^^^^^^熟練度
}


varargs int can_use(object me, object victim, object weapon)
{
        // 確定所使用武器是否正確
	int type,i;
	string last;
        if( weapon ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "gonfu1"  : type = 1;  break;
        	  case "gonfu2"  : type = 2;  break;
        	  case "gonfu3"  : type = 3;  break;
        	  case "gonfu4"  : type = 4;  break;
        	  case "gonfu5"  : type = 5;  break;
        	  case "gonfu6"  : type = 6;  break;
        	  case "gonfu7"  : type = 7;  break;
        	  case "gonfu8"  : type = 8;  break;
        	  case "gonfu9"  : type = 9;  break;
        	  case "gonfu10"  : type = 10;  break;
        	  case "gonfu11"  : type = 11;  break;
        	  case "gonfu12"  : type = 12;  break;
        	  case "gonfu13"  : type = 13;  break;
        	  case "gonfu14"  : type = 14;  break;
        	  case "gonfu15"  : type = 15;  break;
        	  case "gonfu16"  : type = 16;  break;
        	  case "gonfu17"  : type = 17;  break;
        	  case "gonfu18"  : type = 18;  break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 18  ) {type++;}
        else {type =1;}
        me->set_temp("last_attack_skill", ("gonfu"+type));
        return type;
}

// 各式戰鬥訊息
string *attack_msg = ({




//                  黑龍偷心  狂龍亂舞  
//                  龍影縱橫  龍騰千里  雙龍吐珠   火龍吞□
                   


        "%s一掌『損則有□』擊向%s", 
        "%s力運左右雙掌，『雙龍取水』打向%s", 
        "%s左手負背，右手一掌『密雲不雨』攻向%s",
        "%s突然定住身形，一招『龍停於淵』擊向%s",
        "%s身形前欺，一招『見龍在田』出掌砍向%s",
        "%s身形迴旋不定，一招『履霜冰至』出掌劈向%s",
        "%s身形向上而後前欺，瞬間使出『鴻漸於陸』飛掌砍向%s",
        "%s右掌虛晃一招，左掌一記『利涉大川』攻向%s",   
        "%s右掌護胸，左掌突然使出一招『潛龍勿用』攻向%s",   
        "%s雙拳急打，一招『震驚百里』砍向%s",
        "%s化掌成爪，雙爪使出『蛟龍出海』抓向%s",
        "%s身形突然向西一閃，使出『神龍擺尾』出掌砍向%s",
        "%s舞掌如飛，一連六掌『時乘六龍』連續砍向%s",
        "%s變掌成拳，一記『猛龍過江』重重的打向%s",
        "%s反手拍出一掌『戰龍於野』氣勢恢宏，擊向%s",
        "%s大喝一聲，一記『亢龍有悔』挾大股內勁攻向%s",
        "%s長嘯一聲使出『突兀其來』左掌如奔雷迅速砍向%s",
        "%s凌空飛起，使出最強一式『飛龍在天』雙掌雷霆萬鈞劈向%s",


                     });



int *hits = ({ 65, 68, 71, 74, 77, 80, 83, 85,88,92,95,97,100,102,105,107,110,115 });
int *dams = ({ 47, 50, 53, 56, 59, 62, 64 ,66,68,70,74,76,78,80,85,87,90,99});



varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	int i,delta_dex;
        // 命中率調整
        if( (type<1||type>18) ) return 0;
 
       // 命中率調整值為 百分之（  熟練度/5 + 65~85 ）
        i =  gonfu_level(me)/4 + hits[type-1];
   	if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        return i;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{

        int i,delta_str;
        // 穿透率調整
        if( (type<1||type>18) ) return 0;
        delta_str = (int)me->query_stat("str")-(int)victim->quert_stat("str");
        if (delta_str<0) { delta_str=0; } 
        i = gonfu_level(me)/2 +15 +random(20)+ delta_str/2 ;
        if(i<0) i=0;
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        // 穿透率調整為百分之（熟練度/4 + 雙方力量差/2），低於零則不計
        return i;

}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int i;
        mixed ii,dam; 
        // 攻擊力調整
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
            else {me->add("force_points",-query_need_fp()); } 
        if( (type<1||type>18) ) return 0;
        i = gonfu_level(me)/5+dams[type-1];
        // 攻擊力調整為百分之（  熟練度/6+ 11~18）
  
        return i;
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string a_msg;
        if( (type<1||type>18) ) return 0;
        a_msg = attack_msg[type-1];
        if( (int)me->query("force_points") < query_need_fp() )
        { a_msg = a_msg+"，但是出手時顯得內力不足的感覺";}
        return a_msg;
}
