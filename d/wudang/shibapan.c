// shijie2.c ʮ����
// by Xiang
// by arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
	������һ����ʵ��ʯ���ϣ���Χ�������ԲԵİ��֣�����������������
����������徲����࣬ż���н�����߹���һ�����ͱڣ�һ�������£�̧ͷ��
Լ�ɼ������������е������壬������ˮ���ȣ������Ŀ�������
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie5",
		"northup" : __DIR__"zixiaogong",
	]));
       	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",140);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",140);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",140);
	setup();
	replace_program(ROOM);
}

