inherit ROOM;
void create()
{
        set("short", "�÷��");
        set("long", @LONG
�÷�����������޳�У�����ר�Ŷ������ü�����װ����Ь��ñ��
�������������·�������ʽ��ӱ�����Ҿ������ã��ſ���һ����ľ��(sign)��
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
�����ǲ÷�꣬Ŀǰ���ǿɶ���(ding):

ñ��(hat)��Χ��(scarf)������(suit)��
����(belt)����Ь(shose)��

ÿ��һ���ƽ�

���ӣ�
ding suit $HIY$ �ƽ�ս�� zhanjia qilinjia

���̾ͻ���������Ĳ��ϰ�����һ����ɫ�� zhanjia �У��ƽ�ս�ף�

$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ            $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ

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
