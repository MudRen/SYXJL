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
          "out" : __DIR__"duchang",
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

TEXT
        ]) );

        set("objects", ([
       __DIR__"npc/fair_thrower" : 1,
                        ]) );
	set("no_fight",1);
	set("no_yun",1);
	set("no_steal", 1);
        set("no_sleep_room", 1);
	set("no_beg", 1);

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
