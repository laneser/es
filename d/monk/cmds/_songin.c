//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"佛言 惡人聞善 故來擾亂者 汝自禁息 當無□責 彼來惡者 而自惡之\n",

"佛言 人有二十難\n"
"貧窮佈施難 豪貴學道難 棄命必死難 得睹佛經難 生值佛世難 忍色忍欲難\n"
"見好不求難 被辱不瞋難 有劫不臨難 觸事無心難 廣學博究難 除滅我慢難\n"
"不輕未學難 心行平等難 不說是非難 會善知識難 見性學道難 隨化度人難\n"
"睹境不動難 善解方便難\n",

"佛言 觀天地 念非常 觀世界 念非常 觀靈覺 即菩提 如是知識 得道疾矣\n",

"佛言 人從愛慾生憂 從憂生怖 若離於愛 何憂何怖\n",

"第二覺知 多欲為苦 生死疲勞 從貪慾起 少欲無為 身心自在\n",

"第八覺知 生死熾然 苦惱無量 發大乘心 普濟一切\n"

"願代眾生受無量苦 令諸眾生 畢竟大樂\n",

"不是風動  不是幡動  仁者心動\n",

"菩提自性  本來清淨  但用此心  直了成佛\n",

"世人終日口唸般若 不識自性般若 猶如說食不飽 口但說空 終無有益\n",

"莫聞吾說空  便即著空  第一莫著空  若空心靜坐  便著無記空\n",

"自性能含萬法是大  萬法在諸人性中\n",

"一切即一  一即一切  來去自由  心體無滯  此即般若\n", 

"凡夫即佛 煩惱即菩提 前念迷即凡夫 後念悟即佛\n",

"前念著境即煩惱 後念離境即菩提\n",

"摩訶般若波羅蜜 最尊最上最第一 無住無往亦無來 三世諸佛從中生\n",

"用真如自性 以智慧觀照 於一切法 不取不捨 即是見性成佛道\n",

"若見一切法 心不染著 是明無念 \n",

"用即遍一切處 亦不著一切處 但淨本心\n",

"邪來煩惱至  正來煩惱除  邪正俱不用  清淨至無餘\n",

"常見自己過  與道即相當  離道別覓道  終身不見道\n",

"佛法在世間  不離世間覺  離世覓菩提  猶如求兔角\n",

"人有兩種  法無兩般  迷悟有殊  見有遲疾\n",

"性在身心存  性去身心壞  佛向性中作  莫向性外求\n",

"自性迷即是眾生  自性覺即是佛  慈悲即是觀音  喜舍名為勢至\n",

"心平何勞持戒  行直何用修禪  恩則孝養父母  義則上下相憐\n",

"定是慧體 慧世定用 猶如燈光 燈是光之體 光是燈之用 名雖有二 體本同一\n",

"一行三昧者  於一切處  行、住、坐、臥常行一直心是也\n",

"直心是道場 直心是淨土 但行直心 於一切法 勿有執著\n",

"心不住法  道即通流  心若住法  名為自縛\n",

"若言看心  心元是妄  知心如幻  故無所看也\n",

"若言看淨 人心本淨 由妄念故 蓋覆真如 但無妄想 性自清淨\n",

"外於一切善惡境界  心念不起  名為坐 內見自性不動 名為禪\n",

"外離相為禪  內不亂為定  外若著相  內心即亂\n",

"懺者 懺其前愆 悔者 悔其後過 前惡不起 後過不作 是名懺悔\n",

"無相三皈依 皈依覺 皈依正 皈依淨 <--> 皈依佛  皈依法  皈依僧\n"
"皈依覺  邪迷不生  少欲知足  能離財色  名兩足尊\n"
"皈依正 念念離邪見 以無邪見故 即無人我貢高貪愛執著 名離欲尊\n"
"皈依淨 一切塵勞愛慾境界 自性接不染著 名眾中尊\n",

"萬法從自性生  思量一切惡事  即生惡行  思量一切善事  即生善行\n",

"一燈能除千年暗  一智能滅萬年惡\n",

"莫思向前  已過不可得  常思於後  念念圓明  自見自性\n",

"自性起一念惡  滅萬劫善因  自性起一念善  得恆河沙惡盡\n",

"世人外迷著相 內迷著空 若能於相離相 於空離空 即是內外不迷 一念心開\n",

"諸行無常  是生滅法  生滅滅已  寂滅為樂\n",

"心如虛空  不著空見  應用無礙  動靜無心  凡聖情忘  能所俱渺\n", });

void do_songin(object player, int skill, int degree )
{
	string text;
	string *colors = ({ "HIC", "HIY", "HIB" });
	
	tell_object( player,"經文曰: ");
	if( degree < 14 && skill > random(degree*degree*2) 
		&& (int)player->query("hit_points") > 10 ) {
		text = c_illusion[degree*3+random(3)];
		message("illusion", 
			set_color(text, colors[random(3)], player),player) ;

		tell_room( environment(player), 
			sprintf("%s喃喃念著: %s",player->query("c_name"),
			set_color(text, colors[random(3)], player)) , player);

		player->receive_damage(random(2));
        if( (int)player->query("alignment") < 10000 )
        	player->add("alignment", degree*3);
 		call_out( "do_songin", 4, player, skill, degree + 1 );
	} else {
		player->delete_temp("block_command");
		tell_object( player, 
			"......\n一陣清風吹向你的光頭，打斷了你的思緒。\n" );
		tell_object( player,
			"你從寧靜祥和之境返回這個紛擾的世界，你停止唸經了。\n");
        tell_room( environment(player), 
		sprintf("%s合上佛經，心平氣合地站了起來。\n",player->query("c_name")), player );
	    call_out("quit_songin", degree*10, player);
	}
}

void quit_songin( object player )
{
	if( !player ) return;
	tell_object( player,
		"你覺得你終於想通剛剛所讀的佛經，又能繼續往下唸了。\n");
	player->delete_temp("monk_songin");
}

int cmd_songin()
{
	int skill, hp, alignment;
	object me;
	
	me = this_player();
	skill = (int)me->query_skill("recitation");
	if( !skill ) return notify_fail("你沒有學過誦經，你看不懂經書....。\n");

         if (me->query_temp("exercising"))
              return notify_fail("你正在運功，無法誦經...。\n");
	if( me->query_temp( "monk_songin" ) )
		return notify_fail("你需要一段時間理解，才能有足夠能力再念..。\n");

	write("你翻開隨身的佛經，開始仔細的唸了起來，慢慢進入禪定莊嚴的境界。\n");
		
	tell_room( environment(me), 
  		me->query("c_name")+"翻開隨身帶著的佛經，盤腿而坐，開始念頌佛經...。\n",
		me );

	me->set_temp("monk_songin", 1);
    if( !wizardp( me ) )
		me->set_temp("block_command", 1 );
	
	call_out( "do_songin", 4, me, skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax:  songin

This command is to sit down and reading. When you are songining, alignment
points will recovery . How long you can songin dependson your somgin skill.
Once you are awake from songin, you'll have have some headache. But that's 
normal.
HELP
	);
    return 1;
}
