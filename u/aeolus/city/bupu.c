inherit ROOM;
void create()
{
        set("short", "裁缝店");
        set("long", @LONG
裁缝店里摆满了绫罗绸缎，这里专门订作，裁剪，改装各种鞋，帽，
衫．这里做的衣服不但款式新颖，而且经久耐用．门口有一个大木牌(sign)．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                 "north":"/d/quanzhou/xijie",
]));
        set("objects", ([
                "/d/city/npc/caifeng":1,
			]) );
        set("item_desc", ([
                "sign": @TEXT
这里是裁缝店，目前我们可订作(ding):

帽子(hat)，围巾(scarf)，外衣(suit)，
腰带(belt)，布鞋(shose)．

每件一两黄金．

例子：
ding suit $HIY$ 黄金战甲 zhanjia qilinjia

布铺就会用你带来的布料帮你作一件黄色的 zhanjia 叫＂黄金战甲＂

$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色

TEXT
        ]) );
 	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
