inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
        set_name( "Bernice","柏妮絲" );
        add("id",({"bernice"}) );
        set_short( "柏妮絲" );
        set_long(@LONG
你看到一位亭亭玉立的少女，秀麗的面孔，細緻的皮膚，不過臉上卻掛著淡
淡的愁思，或許你可以幫幫她唷。
LONG
        );
        set( "inquiry", ([
                "help" : "@@help_me",
                "traito" : "@@ask_traito",
                "vito" : "@@ask_vito",
                "adolph" : "@@ask_adolph",
                ]) );
        set( "alignment", 100 );
        set( "gender","female" );
        set( "race","hawkman" );
        set( "time_to_heal", 10 );
        set_natural_armor( 20, 12 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 300 );
}

int help_me()
{

        if ((int)this_player()->query_temp("find_ring") == 1 &&
           (present("blue ring",this_object())) )
        {
                tell_object(this_player(),@LONG
柏妮絲一看到你手中的戒指，臉色大變....
她嘆了口氣，說：唉....這件事說來話長。
....我想你應該知道鳥人族傳統的比武大會吧。比武大會的優勝者可以獲得
鳥人族領袖的地位，也因此我的愛人維多(Vito)就遭人陷害了。我一直想要
找到他最後的下落，並撫平他所受的傷害，洗刷他的恥辱，但卻一直無法實
現。柏妮絲抬起頭用滿載著哀傷的眼神望著遠方，輕輕的說：真希望能有人
肯幫助我....
你一股熱血湧上心頭，對著柏妮絲說：我會幫助你，讓你不再悲傷....
LONG
                );
                this_player()->set_temp("bernice",1);
                this_player()->delete_temp("find_ring");
                return 1;
        }
        else if (this_player()->query_temp("smore_box") == 6)
        {
                tell_object(this_player(),@LONG
柏妮絲說：
        謝謝你，讓維多能夠瞑目～～～
你完成了『鳥人領袖之謎』的任務，得到 8000 點經驗點的報酬。
LONG
                );
		this_player()->set_explore("noden#43");
		if ((int)this_player()->query_quest_level("vito's_wish") < 1) {
		this_player()->finish_quest("vito's_wish",1);
		this_player()->gain_experience(8000);
		}
        }

        else
        {
                tell_object(this_player(),@LONG
柏妮絲白了你一眼，說：這不甘你的事。
LONG
                );
                return 1;
        }
        return 1;
}


int ask_vito()
{
        if ((int)this_player()->query_temp("bernice") == 1)
        {
                tell_object(this_player(),@LONG
柏妮絲低著頭說：
維多是我的未婚夫，也是我心目中的英雄。不知道從多久以前，他就一直是鳥
人族的領袖，領導著鳥人族的戰士們對抗來犯的敵人，一次又一次的擊退想要
染指天空之城的敵人。但是卻在一年以前的比武大會中敗給了他的弟弟，阿道
夫(Adolph)。不過奇怪的是，阿道夫本來沒那麼厲害啊，真不知道為啥會在一
年之內武功突飛猛進，難道是因為偷吃禁藥嗎？
柏妮絲接著又說：
而且最近我總是夢到維多，他彷佛對我說著話，可是我卻都聽不懂，只隱隱約
約聽到什麼雷多(Traito)害我....
LONG
                );
                this_player()->set_temp("traito",1);
                return 1;
        }
        else
        {
                tell_object(this_player(),"柏妮絲理都不理你。\n");
                return 1;
        }
        return 1;
}

int ask_adolph()
{
        if ((int)this_player()->query_temp("bernice") == 1)
        {
                tell_object(this_player(),@LONG
柏妮絲說：
阿道夫啊....是維多的弟弟，維多一向滿照顧他的，不過他一向武藝都不強，
不知道為什麼會在去年一舉擊潰我的維多，而且看他跟本不像是在比武，跟本
是想把維多打死。而且在他當上鳥人族的領袖之後，不知道從哪裡帶回來一個
什麼錫卡拉教大祭司叫做裘拉根(Juraken) 的，兩個人整天在一起，而且還要
我們鳥人族的戰士們為他抵抗他的敵人。幾個月前的一場大戰害我們元氣大傷
，大家對阿道夫都是敢怒而不敢言。
LONG
        );
                return 1;
        }
        else
        {
                tell_object(this_player(),"柏妮絲理都不理你。\n");
                return 1;
        }
}

int ask_traito()
{
        if ((int)this_player()->query_temp("traito") == 1)
        {
                tell_object(this_player(),@LONG
柏妮絲說：雷多是維多生前最信任的部下，隨著維多出生入死好幾次，自
從維多失蹤，他就受到了阿道夫的賞識，地位越來越高。因為維多的關係，他
很照顧我，不過我最近覺得他好像怪怪的，不知道怎麼了。
LONG
                );
                return 1;
        }
        else
        {
                tell_object(this_player(),"柏妮絲理都不理你。\n");
                return 1;
        }
        return 1;
}

