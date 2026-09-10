#include <mudlib.h>
void init()
{
    add_action("cmd_identify","identify");
}
void identify_weapon(object obj, int skill)
{
     int wc, dam;
     string type;

     type = to_chinese((string)obj->query("type"));
     write(sprintf("這是一種%s。\n",type));
     if ( obj->query("not_the_one") ) {
        write( "與其說它是武器，不如說是件裝飾品。\n" );
        return ;
     }
     if ( obj->query("the_one") ) {
          if ( random(10)>2)
             write(sprintf("如果你不是巫師的話，這樣的武器可能是凡人在這個世界上所能獲得\n的，最可怕的破壞力量，只有巫師的神力方能和它相抗衡。\n"));	
          else
             write(sprintf("即使是一個畢生與武器為伍的戰士，能獲得這樣一件完美的神兵利器\n可說是上輩子修來的福氣。\n"));
          return ;
     }
     wc = (int)obj->query("weapon_class");
     dam = (int)obj->query("min_damage") + (int)obj->query("max_damage");
     skill += (int)this_player()->query_skill(type) / 3;
     if( skill < wc + random(wc/2) + dam/2 ) {
	wc = wc/2 + random(wc);
	dam = dam/2 + random(dam);
     }
     if( wc <= 5 ) write( "與其說它是武器，不如說是件裝飾品。\n" );
     else if( wc <= 10 ) write( "拿它當作武器，勉強可以湊和著使用。\n" );
     else if( wc <= 15 ) write( "它的品質看起來似乎值得花錢去買。\n" );
     else if( wc <= 20 ) write( "依你的經驗，這樣的武器算得上是高級品。\n" );
     else if( wc <= 25 ) write( "憑良心說，它可算得上是一般人心目中所謂的「神兵利器」了。\n" );
     else if( wc <= 30 ) write( sprintf("如果你在%s武器技能上沒有相當的造詣，這樣的\n神兵利器對你而言，只是一個不切實際的夢想。\n",type) );
     else if( wc <= 40 ) write( sprintf("即使是一個畢生與武器為伍的戰士，能獲得這樣一件完美的神兵利器\n可說是上輩子修來的福氣。\n") );
	else write( sprintf("如果你不是巫師的話，這樣的武器可能是凡人在這個世界上所能獲得\n的，最可怕的破壞力量，只有巫師的神力方能和它相抗衡。\n") );
}

void identify_armor(object obj, int skill) {
	int ac, db, value;
	string material;

	ac = (int)obj->query("armor_class");
	db = (int)obj->query("defense_bonus");
	switch( (string)obj->query("type") ) {
		case "head" : value = ac * 100 / 10;					break;
		case "body" : value = ac * 60 / 40 + db * 40 / 5;		break;
		case "arms" : value = ac * 80 / 5 +  db * 20 /5 ; 		break;
		case "hands" : value = ac * 80 / 5 +  db * 20 /5 ;		break;
		case "legs" : value = ac * 60 / 10 + db * 40/5 ;		break;
		case "feet" : value = ac * 100 / 10;	   	            break;
		case "shield" : value = ac * 100 / 10;					break;
		case "cloak" : value = ac * 100 / 10;					break;
		case "misc" : value = db * 100 / 10;					break;
		case "finger" : value = db * 100 / 10;					break;
		case "kernel" : value = ac * 40 / 10 + db * 60 / 20;	break;
		case "globe" : value = ac * 50 / 30 + db * 50 / 20;		break;
		case "saddle" : value = ac * 60 / 20 + db * 40 / 5;		break;
		case "tail" : value = ac * 100 / 10;					break;
	}
	if( value/2 + random(value/2) > skill )
		value = value/2 + random(value/2);
		switch ((string)obj->query("material")) {
			case "heavy_metal" :
				material = "重金屬打造的";
				break;
			case "light_metal" :
				material = "輕金屬組成的";
				break;
			case "element" :
				material = "礦物元素做成的";
				break;
			case "stone" :
				material = "硬得像石頭的";
				break;
			case "wood" :
				material = "木頭釘的";
				break;
			case "leather" :
				material = "皮革硝製成的";
				break;				
			case "cloth" :
				material = "布做的";
				break;
			default :
				material = "公會專用的";
				break;
		}
		if ( obj->query("not_the_one") ) {
                   write( sprintf("唉....這樣%s護具只能提供些許的保護。\n",material) );		
		   return ;
		}
		if ( obj->query("the_one") ) 
                   switch(skill){
                   case 70..100:
                       write( sprintf("哇....這件%s護具是你所看過的，防護力最佳的。\n",material) );		   
 		       return;
		   default:   
		      switch(random(10)){
		      case 0..4 :write( sprintf("哇....這件%s護具是你所看過的，防護力最佳的。\n",material) );
		              return;
		      case 5..8 :write( sprintf("噢....這件%s護具的品質極高，能提供嚴密的保護。\n",material) );        
		              return;
		      default :write( sprintf("嗯....這件%s護具看起來有中等以上的品質。\n",material) );
		              return;
		      }
		      return; 
		   }
		
		if( value < 20 ) write( sprintf("唉....這樣%s護具只能提供些許的保護。\n",material) );
		else if( value < 40 ) write( sprintf("咦....這件%s護具看起來似乎不算太差。\n",material) );
		else if( value < 60 ) write( sprintf("嗯....這件%s護具看起來有中等以上的品質。\n",material) );
		else if( value < 80 ) write( sprintf("噢....這件%s護具的品質極高，能提供嚴密的保護。\n",material) );
		else write( sprintf("哇....這件%s護具是你所看過的，防護力最佳的。\n",material) );
}

int cmd_identify(string arg)
{
	int skill;
	object dest;


	if( this_player()->query("stop_attack") > 0 )
		return notify_fail( 
			"( 你還沒有完成上一個動作，無法鑑定任何物品。 )\n");

	if( !arg || arg=="" )
		return notify_fail( 
			"指令格式: itentify <物品名>\n");

	if( !dest= present( arg, this_player() ) )
		return notify_fail( 
			"你沒有這樣東西。\n");

	this_player()->block_attack(4); 

	skill = (int)this_player()->query_skill("identify");

	if( dest->query("weapon_class") ) 
		identify_weapon(dest, skill);
	else if( dest->query("armor_class") || dest->query("defense_bonus") ) 
		identify_armor(dest, skill);
	else write( 
		"這件東西既不是武器，也不是護具。\n");

	return 1;
}
