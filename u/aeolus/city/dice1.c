inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
	����һ�Ŵ����Լ������ˣ���������ׯ�����е�һ�����ӣ�
�е���¶ϲɫ���еĵ��������ʹ���������ԣ�����ׯ�����ǽ����
��һ��ֽ(paper)��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"duchang",
]));
        set("item_desc", ([
                "paper": @TEXT


���ӵĶķ���

bet��<����>��<����>

���ࣺ��0��1��2��3��18
0����		��С	(3-10)	һ��һ
1��  		�Ĵ�	(11-18)	һ��һ
2����		��Χ��	(��������ͬ��)һ����ʮ��
3��18	�ĵ���  		һ���

���ӣ�
bet��0��50
����ʮ����С��
(ע�⣺���ĳ�ֻ��������������convert xxx gold to silver �һ����ӡ�)

TEXT
        ]) );

        set("objects", ([
       __DIR__"npc/dice_thrower" : 1,
                        ]) );
	set("no_fight",1);
	set("no_yun",1);
        set("no_sleep_room", 1);

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
	object me;
	me = this_player();
	if( me->query("gamble/amount")) {
		me->delete("gamble/amount");
//		me->decrease_skill("betting",1);
	}
}
