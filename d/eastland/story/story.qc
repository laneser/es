    

                      「神仙島」區域簡介 

I.歷史簡介 :
       
          神仙島位於遙遠的東方大陸，原來是個人煙罕至的地方，卻因為航海

　　　技術發達，島四周暴風圈的減小，漸漸地揭開了它神秘的面紗。 

          在原始洪荒的大地上，原本混雜著各種的族類，並和天界串連在一起

　　　千萬年來各安天命，彼此相安無事，和樂融融。大地上分為五個部分，各

　　　受著四個不同天帝所統治，但尊崇為中央部分的天帝－黃帝。不料三千多

　　　年前，南方的巨人族裡，一個兇殘暴厲名叫「蚩尤」的，表面上是順從，

　　　骨子裡卻不懷好意。蚩尤自從把南方天帝－炎帝的寶座奪過來後，因為他

　　　本是炎帝的後代，於是便「名正言順」地自稱起 "炎帝" 來。這個蚩尤是

　　　不會把這樣一個小小的一方天帝的位置看在眼裡的，最終目的乃是想奪取

　　　中央上帝的黃帝的寶座。

        　這場爭奪之戰是免不了的，起初，戰事是一面倒的，蚩尤籍著煽動地

　　　面上的人民，在各處打了不時勝仗，這對於黃帝而言是相當不利，但故事

　　　的結局都是一樣的，最後由代表正義的黃帝所戰勝。有鑑於神和人不分出

　　　界限，混居在一起，總是弊多利少，將來難免沒有第二個 "蚩尤" 起來煽

　　　動人民。自此，天和地的通路被阻隔斷，叫人們再也上不了天，又維持了

　　　安全。

　　　　　人們總是渴望能到天上的，於是便產生了 "巫師" 來傳達上天的消息

　　　，做為溝通的媒介，於是在神仙島上形成了一座名叫「巫咸城」的城市，

      當然，有著不為人知的秘密才能有那個神仙島，才能有那城在那座島上。
　
　        隨著時間的流逝，人們多已死心於窺往天界想，神仙島漸被遺忘，加

      上前往神仙島諸多兇險。近來航海技術發達，神仙島這個名字才又被人們

      想了起來。

　　

II.特殊房間：
       
       I). 買賣 eq ( /story/wiz/city/store.c)
       II).旅館    ( /story/wiz/city/hotel1.c")
       III).藥店   ( /story/wiz/city/hospital1.c")     


III.任務概要：

       I). 幫助受傷者 (/story/monster/patient1.c)
      II). 幫巫羅王找回巽靈珠 (/story/wiz/city/monster/wiz_king1.c)



IV. PART １ 武器： /story/weapon/

武器名稱    檔案名稱        武器類別     WC    Damage      特殊攻擊

戰士□匕    dagger1.c        dagger      20    13/23
釣杆        fisher_staff.c   blunt       20    8/15
天魔之杖    imp_wand.c       wand        30    10/20       evil
玄鐵重劍    sword1.c         longblade   35    20/30


IV. PART ２ 防具： /story/armor/

防具名稱      檔案名稱            型態       質料      AC/DB     特殊效果

卍符          amulet1.c           misc       cloth      0/1 
亂環環        fisher_armband.c    arms     heavy_metal  3/3
十二天都符□  imp_amulet.c        misc       cloth      0/1
戰士□臂環    imp_armband.c       arms      element     3/4      energy:-20
								 electric:20
大首領披風    imp_cloak.c         cloak      cloth      7/6     dex-2
								 meditate:10
羽神衣        imp_cloth.c         body       cloth      22/2     magic:35
								 fire:30
戰士□脛甲    imp_leggings.c      legs      element     6/3      electric:5
戰士□鎧甲    imp_plate.c         body      element     27/4       
七彩琉璃戒    imp_ring.c         finger     element     0/6
大紅衣服      lucky_cloth.c       body      cloth       0/1      electric:50
卍戒          ring1.c            finger     element     0/7
九魔陰陽符    vampire_amulet.c    misc      cloth       0/6     evil:-50


IV. PART ３ 物品： /story/item/

       物品名稱         檔名                   
                              
       巽靈珠          ball1.c            
       進財符          card1.c           
       飛翔之笛        flute1.c          
       大紅葫          gourd1.c
   「蚩尤」的屍體      head1.c
    「文蛛」毒液       liquid.c
      奇妙吸管         straw.c


IV. PART ４ 怪物: /story/monster  PS * 表主動攻擊

   怪物名稱        檔名      AC/DB  WC  傷害範圍   武器裝備      特殊能力    

[ 11 ] 羽民壯丁  adult1.c    55/2   24   11/24
[  6 ] 小蝙蝠     bat1.c     30/2   13   4/9 
[ 11 ] 大蝙蝠     bat2.c     55/2   24   11/24
[  8 ] 羽民小弟弟 boy1.c     40/2   15   6/12
[  5 ] 小螃蟹     crab1.c    25/0   11   5/11
[  6 ] 小螃蟹     crab2.c    30/0   13   6/13
[  4 ] 小螃蟹     crab3.c    20/0   9    4/9
[ 16 ] 小螃蟹     crab4.c    70/0   36   19/36
*[ 18 ] 地獄□犬  dog1.c     1/1    90   33/57                  bleeding
[ 18 ] 雷獸 應龍 dragon1.c   117/20 66   24/45                  lightning
[ 19 ] 羽民族大首領 羽後     104/66 78   35/60     天魔□杖     全部魔法  
		 elder1.c		           羽神衣
                                                   十二天都符□
						   七彩琉璃戒 
						   大首領披風 
						   戰士□脛甲
[ 16 ] 老釣者    fisher.c    73/28  41   18/35     釣杆	        special damage
						   亂環環
[  8 ] 羽民小妹妹 girl1.c    40/2   15   6/12
[ 16 ] 羽民族守衛 guard1.c   76/25  59   22/33     戰士□匕     aim weakest
						   戰士□鎧甲
						   戰士□脛甲	
						   戰士□臂環
*[ 13 ] 熱帶昆蟲 insect1.c   65/0   26   13/27     
*[ 16 ] 玄天玉獅 liong1.c    60/15  38   19/36     大紅衣服 
[ 17 ] 吉神 泰逢 lucky_god.c 1/101  309  16/16     進財符          
       						   大紅葫 
[ 13 ] 羽民老者  older1.c    65/2   31   12/30
[ 19 ] 受傷者    patient1.c                                     quest
								cant kill
 
[ 16 ] 吟遊詩人  poet1.c     75/5   38   15/36 

[ 19 ] 人面藍蠍的頭部 head.c 80/15  74   45/63
[ 19 ] 人面藍蠍的尾部 tail.c 10/45  9    1/7
                
*[ 19 ] 文蛛     spider1.c   1/1    67   36/60                  poison
								block
[ 18 ] 劍客 八門吹雪         80/32  65   35/35     玄鐵重劍     special damage
	        swordman1.c          		   卍符
						   卍戒  
[  1 ] 旅行商人[騎在驢子上]  			   水晶玻璃球
[ 10 ] 羽民媽媽  woman1.c    50/2   22   10/14

*[ 19 ] 萬年妖□ 谷辰                                           請看 code  
                vampir1.c




V. PART １ 武器： /story/war/weapon/

武器名稱    檔案名稱        武器類別     WC    Damage      特殊攻擊

巨斧        axe1.c          axe          33    23/38       bleeding
木棒        blunt1.c        blunt        15    5/14    
嗜血       chi_blood.c      dagger      lv*2   lv+5/lv*2   receive_healing 
血鐮刀      scythe.c        longblade    20    14/22
魔風杖      staff1.c        wand         30    10/20       evil
雨神鞭      whip1.c         whip         30    13/22


V. PART ２ 防具： /story/war/armor/

防具名稱      檔案名稱            型態       質料      AC/DB     特殊效果

蚩尤戰袍      chi_cloak.c         body       cloth     20/4      
蚩尤戰盔      chi_helmet.c        head       cloth     0/2       
地獄之盾      chi_shield.c       shield      cloth     0/5       
蚩尤綁腿      chi_skirt.c         legs       cloth     0/1       
披襟襤衣      cloth1.c            body       cloth     15/5 
風神衣        cloth2.c            body       cloth     15/5      
風神套        gloves1.c           hands      cloth     3/2
雨符          rain_amulet.c       body       cloth     0/4       evil:20
						                 divine:-15 
雨師之袍      rain_cloth.c        body       cloth     0/5       cold:-20
								 magic:30

V. PART ３ 怪物: /story/monster  PS * 表主動攻擊

   怪物名稱        檔名      AC/DB  WC   Damage   武器裝備      特殊能力

*[ 19 ] 蚩尤       chi_eu.c  20/12  67   37/60    蚩尤戰盔      evil
                                                  蚩尤戰袍      poison
    						  蚩尤綁腿      
						  嗜血 
						  地獄之盾
*[ 14 ] 魑鬼       ghost1.c  70/15  28   14/22    血鐮刀        evil
*[ 14 ] 魅鬼       ghost2.c  40/25  33   18/27    血鐮刀        
*[ 16 ] 魎鬼	   ghost3.c  50/25  50   21/33    血鐮刀        evil
								confused
*[ 16 ] 魍鬼       ghost4.c  50/25  50   21/33    血鐮刀        poison
*[ 16 ] 神嵬       ghost5.c  50/25  53   19/37                  poison
[ 16 ] 夔獸        healer1.c 53/35  42   16/30                  healing
*[ 13 ] 巨神獸     pet1.c    60/15  46   9/25                   poison
*[ 18 ] 雨師      rain_god.c 65/30  55   23/25    雨符          poison
						  雨師之袍
						  雨神鞭
[ 16 ] 天界奇兵   soldier1.c 80/22  45   22/35    白銀鎧甲
						  太乙青霜劍
[ 17 ] 眾天神將   soldier2.c 85/25  50   24/39    白銀鎧甲
						  白銀盾牌
						  太乙青霜劍
*[  8 ] 巨人族士兵 troll1.c  50/6   16   7/17     披襟襤衣
						  木棒
*[ 17 ] 巨人族戰士 troll2.c  75/35  52   27/42    披襟襤衣
						  巨斧
*[ 18 ] 風伯      wind_god.c 68/27  62   26/38    風神套        evil
						  風神衣
						  魔風杖
               

VI. PART １ 武器： /story/wiz/weapon/

武器名稱    檔案名稱        武器類別     WC    Damage      特殊攻擊

太皓古弋   captain_hook1.c  thrusting    45    28/47
冰精       ice_dagger.c     dagger       20    13/20
黃金槍     jousting1.c      jousting     25    14/24
黃金槍     jousting2.c      jousting     30    15/33
芭蕉扇     p_fan1.c         blunt        25    13/22
黃金長矛   polearm1.c       polearm      30    19/30
黃金長矛   polearm2.c       polearm      33    19/33
渡劫金針   wiz_dagger1.c    dagger       30    19/33
霸王槍     wiz_lance.c      jousting     35    10/30        nosecond
金筆       wiz_pen1.c       thrusting    30    15/20
混沌□杖   wiz_wand1.c      wand         35    20/30        electric


VI. PART ２ 防具： /story/wiz/armor/

防具名稱      檔案名稱            型態       質料      AC/DB     特殊效果

長袖對襟棉袍  captain_cloth1.c    body       cloth     0/5       evil:-20													
麻紗帽        captain_hat1.c      head       cloth     7/1       
雪魂凝指      ice_ring.c         fihger      element   0/5       dex:-1
							         meditate:10
琉璃珠項鍊    p_amulet1.c         misc       element   0/5       light
 								 str:-1
紅緞地彩繡肚兜 p_cloth1.c         body       cloth     20/5
護國師□符□  wiz_amulet1.c       misc       cloth     0/8      evil:30
								 poison:30
								 fire:-30
								 cold:-30
白練腰帶      wiz_belt1.c	  legs       cloth     6/5      
王者披風      wiz_cloak1.c        cloak    heavy_metal 7/3
白色官服      wiz_cloth1.c        body       cloth     26/5
藥師診袍      wiz_cloth2.c        body       healer    32/7      evil:30
							         poison:30
								 fire:-20
								 cold:20													
藥師手套      wiz_gloves1.c       hands      healer     4/3       evil:20
								 poison:20
								 fire:-20
						                 cold:-20
皇冠          wiz_helmet1.c       head     heavy_metal 7/1 
藥師護頭      wiz_helmet2.c       head     healer      7/4       evil:20
								 poison:20
								 fire:-20
								 cold:-20
黃金鎧甲      wiz_plate1.c        body     heavy_metal 34/5      
護國師□戒    wiz_ring1.c         finger   element     0/5       magic:30
								 divine:-60
王者之戒      wiz_ring2.c         finger   element     0/5
護國師□袍    wiz_robe1.c         body     cloth       30/5
黃金盾        wiz_shield1.c       shield   heavy_metal 5/0
黃金盾        wiz_shield2.c       shield   heavy_metal 7/4
黃金盾        wiz_shield3.c       shield   heavy_metal 10/1


VI. PART ３ 物品： /story/wiz/item/

       物品名稱         檔名

       無底袋           bag1.c
       金色籃子        basket1.c 
       水晶玻璃球      crystal1.c
       遁龍樁          flee1.c
       令牌            mark1.c
       滅魔符          spell1.c
       萬相俱滅術      spell2.c
       

VI. PART ４ 怪物: /story/wiz/monster  PS * 表主動攻擊

   怪物名稱        檔名      AC/DB  WC   Damage  武器裝備       特殊能力

[  1 ] 旅館老闆   boss1.c                                       不能砍
[  5 ] 小男孩     boy1.c     25/0   11    2/6     
[  1 ] 小白狗 吉利 dog1.c					不能砍
[  9 ] 宮女     f_servant1.c 45/0   20    8/19
[  5 ] 小女孩     girl1.c    25/0   11    2/6
[  1 ] 金石老人 golden_older.c		                        不能砍
[ 18 ] 雪山靈魅 寒玉娘娘     85/14  64    30/50  雪魂凝指       poison
               icewoman.c			 冰精           block
								bleeding
[ 11 ] 路邊賣蚵仔煎的        55/2   24    11/24  
               merchant1.c
[ 11 ] 路邊賣米粉羹的        55/2   24    11/24
               merchant2.c
[  6 ] 老頭子  older1.c      30/0   13    4/12
[  7 ] 患者    patient1.c    15/2   26    11/23
[ 17 ] 鐵扇公主 princess1.c  75/35  76    35/55  紅緞地彩繡肚兜 forget 
 						 琉璃珠項鍊
						 芭蕉扇
[ 13 ] 卜筮者 soothsayer1.c  65/0   29    10/28
[  3 ] 學子   student1.c     25/0   6     2/6
[ 12 ] 私塾教師 teacher1.c   60/0   23    10/25
[  6 ] 路邊小販 vendor1.c					不能砍
[ 15 ] 一大群觀光旅客        75/0   33    15/33
              visitor2.c
[ 16 ] 皇宮禁軍              66/17  52    22/34  黃金盾
	 wiz_bodyguard1.c 			 黃金槍
[ 17 ] 皇宮禁軍 城主的貼身待衛      72    30/45  黃金盾
         wiz_bodyguard2.c    98/30		 黃金長矛
[ 18 ] 皇宮禁軍隊長          86/28  60    30/40  黃金盾
	 wiz_captain1.c 			 黃金長矛
[ 18 ] 京城四大名捕 夏侯忍   65/34  68    33/48  長袖對襟棉袍
	 wiz_captain2.c				 麻紗帽
						 太皓古弋
[ 17 ] 藥師 巫姑             55/53  95    27/50  藥師護頭       aim    
	 wiz_doctor1.c				 藥師手套
						 藥師診袍
						 渡劫金針
[ 18 ] 護國師 巫真           75/48  72    28/48  護國師□符□   spells
	 wiz_elder1.c				 護國師□戒
						 護國師□袍
						 混沌□杖
[ 18 ] 武將 巫既             100/11 65	  23/53	 黃金鎧甲	special_damage
	wiz_general1.c				 黃金盾 
						 黃金槍
[ 13 ] 城門守衛              56/11 39     19/30  黃金盾
        wiz_guard1.c		                 黃金長矛
[ 14 ] 縣役捕快		     68/10 39     19/30  黃金盾
        wiz_guard2.c			         黃金長矛
[ 19 ] 城主 巫羅王          110/65 77     40/75  皇冠          special_damage 						
	wiz_king1.c				 王者披風 
						 王者之戒

						 黃金盾
						 霸王槍
[ 18 ] 文官 巫禮             70/40 65      21/35 金筆          aim g
	wiz_scholar1.c             65      21/35 金筆
				   		 白色官服
						 白練腰帶
 


 	     
 
VII. PART １ 武器： /story/palace/weapon/

武器名稱    檔案名稱        武器類別     WC    Damage      特殊攻擊

昊天神劍   dragonsword.c    longblade    35    20/40       
神禹令     dragonwand1.c    wand         23    7/22        evil
蒲扇        fan1.c	    blunt        20    15/22
水晶匕首 northgod_dagger.c  dagger       25    14/28
玉如意     queen_weapon.c   blunt        35    10/20
大花剪     scissors.c       shortblade   20    15/22
七彩璇天尺 ruler.c          thrusting    45    30/45       mantel or divine
          ( unique )                                       
青狼鎖     chain.c          chain        30    15/23
太乙青霜劍  sword1.c        shortblade   25    15/22
太乙青霜劍  sword2.c        shortblade   28    16/32
三叉戟     westgod_fork.c   thrusting    30    18/35

          
VII. PART ２ 防具： /story/wiz/armor/

防具名稱      檔案名稱            型態       質料      AC/DB     特殊效果

淺黃色宮裝    f_cloth1.c	  body	     cloth     0/5
白練戰裙      gardener_belt.c     leges      cloth     1/2
陸吾之戒      gardener_ring1.c	  finger     elmenet   0/5	  poison:30
								  evil:30
								  divine:-30
							          fire:-50
潛龍符        god_amulet.c	  misc       element   0/5	  
界龍鎧甲      god_cloth.c	  body       element   26/5	  
天龍鐲        god_gloves.c	  hands	     element   3/3	  
亢龍盔	      god_helmet.c	  head       element   6/2	  
星龍戒	      god_ring.c	  finger     element   0/10 
升龍盾	      god_shield.c	  shield     element   7/5      dex:-7
水晶雲肩     northgod_cape.c      cloak      element   6/3	  fire:-20
								  cold:40
水晶鎧甲     northgod_cloth.c 	  body	     element   35/8	  
潛於琉璃鏡   northgod_shield.c    shield     element   6/8        light
								  cold:-20
龍戒	     northgod_ring.c 	  finger     element   0/5	  
繡絲彩靴     queen_boots.c	  feet	     cloth     6/2	  energy:20
繡絲曳尾雲肩 queen_cape.c	  cloak	     cloth     0/10	  
玉勝	     queen_helmet.c       head	     element   6/2	  acid:30
曲盾         goldgod_shield.c     shield   heavy_metal 5/1
白銀鎧甲     soldier_plate1.c     body	   heavy_metal 27/4	      
白銀鎧甲     soldier_plate2.c     body     heavy_metal 34/5
白銀盾牌     soldier_shield1.c    shield   heavy_metal 7/4
星天衣 	     westgod_cloth.c	  body     heavy_metal 33/5       magic:-20     
						                  mental:25
星天冠       westgod_helmet.c     head     heavy_metal 8/3       divine:10
龍形項鍊     westgod_necklace.c   misc     heavy_metal 0/5        
	

VII. PART ３ 怪物: /story/wiz/monster  PS * 表主動攻擊

   怪物名稱        檔名      AC/DB  WC   Damage  武器裝備       特殊能力

[ 16 ] 應龍     dragon1.c    76/39  53   34/59                  horse
[ 13 ] 天都仙女  f_se1.c     70/5   30   15/27   淺黃色宮裝
						 蒲扇
[ 16 ] 後花園管理者 招英     69/32  35   19/32   白練戰裙
	        gardener1.c		         大花剪
[ 17 ] 天神 陸吾 gardener2.c 1/6    134  14/22   陸吾之戒
						 神禹令
[ 19 ] 中央天帝 黃帝 king1.c 125/79 80   45/77   星龍戒         magic
						 界龍鎧甲       special_damage
						 亢龍盔
						 潛龍符 
						 天龍鐲
						 升龍盾 
						 昊天神劍
[ 19 ] 北方天帝 顓頊 	     50/50  82   22/36   水晶匕首 		
             northgod.c  		         龍戒
						 水晶鎧甲 
						 水晶雲肩
[ 16 ] 火鳳凰  phoenix.c     76/39  53   34/59   
[ 19 ] 西王母娘娘 queen1.c   62/44  65   35/60   玉勝           special damage
						 繡絲彩靴		
						 繡絲曳尾雲肩
						 玉如意
[ 16 ] 天界神兵 soldier1.c   80/14  35   17/36   白銀鎧甲
						 太乙青霜劍
[ 19 ] 金神蓐收 goldgod.c    75/53  85  44/66   青狼鎖
              ( unique )            75  38/58   曲盾
 						 七彩璇天尺
[ 17 ] 諸天神將 soldier2.c   81/24  40   22/40   白銀鎧甲
						 白銀盾牌
						 太乙青霜劍
[ 19 ] 西方天帝少昊 westgod.c 71/39 50   31/48   星天衣         special_damage
						 星天冠
					         龍形項鍊
					         三叉戟




PS.
     
      關於這區域的怪物，多設為高 level 的，一來不想區域是所謂所有等級

　　　 "皆宜" ，變得沒有什麼突顯的地方；二來是在進來這裡以前，必須經
　　　
　　　過 "鏡湖" ( "/d/eastland/legend" ) 那支 "無支祈" 的考驗 ( "/d/
     
      eastland/legend/monster/water_mob.c")，尋常 low level 是到不了

      的，於是怪物定會有很多 "大支" 之說，希望諸位考量以上這兩點。



                                                     That's all .
                                                     作者 : Dony 於1996




              
	    						


  

