#include <mudlib.h>

inherit WEAPON;

void init()
{
	add_action("dig_herb","dig" );
        add_action("help","help" ) ;
}

void create()
{
        seteuid( getuid() ) ;
        
	set_name("Herb Hoe","藥鋤");
	add( "id" , ({ "hoe" }) );
	set_short("a set of herb how." , "藥鋤");
	set_long("一把行醫者採藥用的藥鋤。\n");
   	set("unit","把");
   	set("weight", 15);
	set( "type","blunt");
	set( "second",1);
	set( "min_damage",5);
	set( "max_damage",12);
	set( "weapon_class",12);
   	set("value", ({200, "silver"}) );
}

int what_tree(object ob,string str)
{
    string c_name,name;
    c_name=(string)ob->query("c_realname");
    name=(string)ob->query("realname");

    if(c_name==str || name==str)
      { ob->set("test",1) ;
        return 1 ;
       }
    return 0 ;   
}

int dig_herb(string arg)
{       
        int num ;
        string s1,s3 ; 
        object *the_tree,new_herb,plant,dest ;
        int purified;
        int ok;
        string *verified;
        string s, temp;
        int i;
            
	if( !arg ) return 0 ;
	
	if(sscanf(arg,"%s %d %s",s1,num,s3)!=3)
	   { if(sscanf(arg,"%s %d",s1,num)!=2) 
               {  s1 = arg ;       
                  num = 1  ;
                }
            }  
        else       	         
	   {
	    return notify_fail("too much argument") ;
	    }
	             
	
        the_tree = filter_array(all_inventory(environment(this_player())),
                     "what_tree",this_object(),s1) ;

        if(sizeof(the_tree)==0) 
           {
            write(
                "你期望在這找到什麼??\n"
                ) ;
            return 1 ;
            }
        dest  = this_player() ;
        plant = the_tree[num-1] ;
        
        if ( this_player()->query_temp("last_verify") ){
          verified=explode(this_player()->query_temp("last_verify"),"\n");
          ok = 0;
          sscanf(identify(plant),"%s/%s",s,temp);
          for ( i = 0 ; i < sizeof(verified) ; i ++) {
            if ( (verified[i]) == temp )
            ok=1;
          }
        }
        else ok = 0;
   
        if ( ok == 0) { write("喂! 沒辨識清楚就亂挖, 鬧出人命怎麼辦?\n");
                        return 1;
                      }  
        purified= plant->query("purified");
        if (purified>0) plant->set("purified",(purified-1)) ;
        else { write ( "很抱歉, 這棵植物上能用的部份都已被採完了。\n"); 
               return 1;
             }   
        new_herb=new(plant->query("herb_path")+plant->query("herb_file")) ;
        new_herb->move(this_player()) ;

        write( "你從"+plant->query("c_realname")+"磔下一"+new_herb->query("unit")
               +new_herb->query("c_name")+"來。\n"
              ) ;
               
	tell_room( environment(this_player()), 
		dest->query("c_name")+"從"+plant->query("c_name")+
		"磔下一"+new_herb->query("unit")+new_herb->query("c_name")+
		"來。\n" 
	  , this_player() );
	if ( purified == 1 ) {
	  write( "\n這棵植物在你不斷的催殘之下, 終於枯萎而死了。\n" );
	  tell_room( environment(this_player()) ,
	             "\n"+ 
	             plant->query("c_name")+"在"+dest->query("c_name")  
                     +"的濫採之下, 終於枯萎而死了。\n",
                     this_player() );
          plant->remove();
          if (plant) destruct(plant);
        }             	
	return 1;
}

int help(string arg)
{
     if(!arg || (arg !="hoe"&&arg!="herb hoe")) 
        return 0 ;

     write( can_read_chinese(this_player())? 
  " 藥鋤是每個有經驗，能自行製藥的行醫者所必備的工具。\n"
  " 但是因為很多藥性相反的藥草長得極為相似，有時甚至是\n"
  " 葉脈方向的差別而已。為免悲劇發生，所以一定要經過\n"
  " 辨識<verify>的植物才能加以採集。\n\n"
  "  採集的方法為   dig <植物學名>\n"
   : ""    
    );
    return 1 ;
}
